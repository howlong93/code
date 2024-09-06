from typing import Union
from pymongo import MongoClient
from fastapi import Request, FastAPI, HTTPException, Depends, Path, status
from pydantic import BaseModel
from typing import Optional, Dict, List
import json
import os
from dotenv import load_dotenv

from time import strftime, localtime
from fastapi.middleware.cors import CORSMiddleware

from fastapi.security import OAuth2PasswordBearer, OAuth2PasswordRequestForm #

app = FastAPI()

load_dotenv()
uri = os.getenv('MONGO_CONNECT_URI')

client = MongoClient(uri)

try:
    client.admin.command('ping')
    print("Pinged your deployment. You successfully connected to MongoDB!")
except Exception as e:
    print(e)

SIZE = 256 # number of LED per board

db = client['test']
collection_front = db['front']
collection_pico = db['pico']
user_list = db['users']

origins = [
    "http://localhost",
    "http://localhost:8000",
    "http://localhost:8081",
    "http://localhost:3000",
    "http://140.113.160.136:419"
]

app.add_middleware(
    CORSMiddleware,
    allow_origins=origins,
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"]
)

oauth2_scheme = OAuth2PasswordBearer(tokenUrl="token") 

class User(BaseModel): 
    username: str
    disabled: Union[bool, None] = None

class UserInDB(User): 
    password: str

def get_user(db, username: str):
    user_now = db.find_one({"username": username})
    if user_now:
        user_dict = user_now
        return User(**user_dict)

def decode_token(token):
    user = get_user(user_list, token)
    return user

async def get_current_user(token: str = Depends(oauth2_scheme)):
    user = decode_token(token)
    if not user:
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail = "Invalid authentication credentials",
            headers = {"WWW-Authenticate": "Bearer"},
        )
    return user

async def get_current_active_user(current_user: User = Depends(get_current_user)):
    if current_user.disabled:
        raise HTTPException(status_code=400, detail="Inactive user")
    return current_user

@app.post("/token")
async def login(form_data: OAuth2PasswordRequestForm = Depends()):
    user_dict = user_list.find_one({"username": form_data.username})
    if not user_dict:
        raise HTTPException(status_code=400, detail="Incorrect username or password")
    user = UserInDB(**user_dict)
    if not form_data.password == user.password:
        raise HTTPException(status_code=400, detail="Incorrect username or password")

    return {"access_token": user.username, "token_type": "bearer"}

@app.get("/users/me")
async def read_users_me(current_user: User = Depends(get_current_active_user)):
    return current_user

@app.get("/")
def read_root():
    return {"Hello": "World"}

class Item(BaseModel):
    ID: int
    update_time: str
    color: str

@app.get("/items/{item_id}")
async def pico_read(item_id: int):
    item = collection_pico.find_one({"ID": item_id})
    if item:
        return {
            'ID': item['ID'], 
            'color': item['color']
        }
    else:
        return {"message": "Item not found"}

@app.get("/items/time/")
async def front_read_time():
    time_list = collection_front.distinct("update_time")

    return {
        "time_list" : time_list[::-1]
    }

@app.post("/items/")   # to be determined
async def front_upload(request: Request):
    b = await request.body()            # 等 body 傳進來再繼續
    body = json.loads(b)                # parse body from string to json
    color = body['color']               # get the "color" attribute 
    
    current_time = strftime("%Y-%b-%d %H:%M:%S", localtime())

    collection_front.insert_one({
        "update_time": current_time,
        "color": color
    })

    for i in range (1, 4): #1,2,3
        search_item = collection_pico.find_one({"ID": i})  
        if search_item:
            collection_pico.update_one({"ID": i}, {"$set": {"color": color[int(SIZE*3*(i-1)): int(SIZE*3*i)]}})
        else:
            collection_pico.insert_one({
                "ID": i,
                "color": color[int(SIZE*3*(i-1)): int(SIZE*3*i)]
            })

    search_item = collection_pico.find_one({"ID": 4})  
    if search_item:
        collection_pico.update_one({"ID": 4}, {"$set": {"color": color[int(SIZE*9): int(SIZE*9+6)]}})
    else:
        collection_pico.insert_one({
            "ID": 4,
            "color": color[int(SIZE*9): int(SIZE*9+6)]
        })

    return {
        "message": "upload success OuOb",
        "color": color
    }

@app.get("/items/load/{time}")
async def front_load(time: str):
    search_item = collection_front.find_one({"update_time": time})
    color = search_item["color"]
    return {
        "color" : color
    }

@app.get("/items/latest/")
async def front_latest():
    time_list = collection_front.distinct("update_time")
    latest_time = time_list[-1]
    search_item = collection_front.find_one({"update_time": latest_time})
    color = search_item["color"]
    return {
        "color" : color
    }
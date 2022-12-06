import hashlib
import re

trans1 = input()
lines = trans1.split('&')
amon = 0

for line in lines:
    if "Alice" in line:
        money = re.findall(r"\d+",line)
        amon += int(money[0])

prev = "0000000000000000000000000000000000000000000000000000000000000000"
blocknum = 1
hash_string = "uuuu"
first_nonce = 1
while hash_string[0:4] != "0000":
    message = str(blocknum) + str(first_nonce) + trans1 + prev
    utfData = message.encode ('utf-8')
    hash_string = hashlib.sha256(utfData).hexdigest()
    first_nonce = first_nonce+1
prev = hash_string

trans2 = input()
blocknum = 2
second_nonce = input()
money = 0
hash_string = "uuuu"
while hash_string[0:4] != "0000":
    money = money+1
    message = "2" + str(second_nonce) + trans2.replace("_", str(money)) + prev
    utfData = message.encode('utf-8')
    hash_string = hashlib.sha256(utfData).hexdigest()
prev = hash_string
if trans2[0] == 'A':
    amon -= money
else:
    amon += money

trans3 = input()
blocknum = 3
save_hash = input()
te23fbbbb736a329b6064146b9eb5fe8c584e61116471138dbfb6hird_nonce = 0
sv_money = re.findall(r"\d+", trans3)
third_nonce = 0
hash_string = "uuuu"
while hash_string != save_hash:
    third_nonce += 1
    message = "3" + str(third_nonce) + trans3 + prev
    utfData = message.encode('utf-8')
    hash_string = hashlib.sha256(utfData).hexdigest()

if trans3[0] == 'A':
    amon -= int(sv_money[0])
else:
    amon += int(sv_money[0])

print (str(money)+","+str(amon)+","+str(third_nonce))

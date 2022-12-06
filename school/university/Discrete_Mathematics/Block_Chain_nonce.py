import hashlib

lines = []
while True:
    try:
        data = input()
        lines.append(data)
    except:
        break

prev = "0000000000000000000000000000000000000000000000000000000000000000"
blocknum = 1

for data in lines:
    hashString = "XXXXXXXX"
    nonce = 1
    while hashString[0] != '0' or hashString[1] != '0' or hashString[2] != '0':
        message = str(blocknum) + str(nonce) + data + prev
        utfData = message.encode ('utf-8')
        hashString = hashlib.sha256(utfData).hexdigest()
        nonce = nonce+1
    prev = hashString
    blocknum = blocknum+1

print(hashString)

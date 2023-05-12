import socket
import pickle
s= socket.socket(socket.AF_INET,socket.SOCK_STREAM) # AF_INET: IPV4; SOCK_STREAM: TCP
s.connect((socket.gethostname(),1236))

HEADERSIZE = 10


while True:
    full_msg = ''
    new_msg = True
    while True:
        msg = s.recv(6) # buffer to 8 byte
    
        if new_msg:
            print(f"new message length: {msg[:HEADERSIZE]}")
            msglen = int(msg[:HEADERSIZE])
            new_msg = False
        full_msg += msg
        
        if len(full_msg)-HEADERSIZE ==msglen:
            print("full msg received")
            print(full_msg[HEADERSIZE:])
            
            d = pickle.loads(full_msg[HEADERSIZE:])
            new_msg = True
            full_msg = ''
    print(full_msg)

import socket
import time
import pickle

HEADERSIZE = 10

s= socket.socket(socket.AF_INET,socket.SOCK_STREAM) # AF_INET: IPV4; SOCK_STREAM: TCP

s.bind((socket.gethostname(),1236)) # 1234: port number
s.listen(5) # queue of 5, 最大监听5个客户端
while True:
    clientsocket, address = s.accept()
    print(f"Connection from {address} has been established!")
    

    d = {1:"Hey", 2:"There"}
    msg = pickle.dumps(d)
    msg = bytes(f"{len(msg):<{HEADERSIZE}}","utf-8") +msg
    clientsocket.send(msg)
    

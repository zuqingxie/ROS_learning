import socket
import time

HEADERSIZE = 10

s= socket.socket(socket.AF_INET,socket.SOCK_STREAM) # AF_INET: IPV4; SOCK_STREAM: TCP

s.bind((socket.gethostname(),1235)) # 1234: port number
s.listen(5) # queue of 5
while True:
    clientsocket, address = s.accept()
    print(f"Connection from {address} has been established!")
    
    msg = f"Welcome to the server!"
    msg = f"{len(msg):<{HEADERSIZE}}" +msg
    
    clientsocket.send(bytes(msg,"utf-8"))
    
    while True:
        time.sleep(3)
        msg = f"The time is :  {time.time()}"
        msg = f"{len(msg):<{HEADERSIZE}}" +msg
        clientsocket.send(bytes(msg,"utf-8"))
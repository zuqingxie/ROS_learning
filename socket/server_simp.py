import socket




s= socket.socket(socket.AF_INET,socket.SOCK_STREAM) # AF_INET: IPV4; SOCK_STREAM: TCP

s.bind((socket.gethostname(),1234)) # 1234: port number
s.listen(5) # queue of 5
while True:
    clientsocket, address = s.accept()
    print(f"Connection from {address} has been established!")
    clientsocket.send(bytes("Wekcome to the server","utf-8"))
    clientsocket.close()
    
    
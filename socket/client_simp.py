import socket

s= socket.socket(socket.AF_INET,socket.SOCK_STREAM) # AF_INET: IPV4; SOCK_STREAM: TCP

s.connect((socket.gethostname(),1234))

full_msg = ''
while True:
    msg = s.recv(8) # buffer to 8 byte
    
    if len(msg) <= 0:
        break
    full_msg += msg.decode("utf-8")
print(full_msg)

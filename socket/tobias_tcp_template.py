'''
    This is a client template from Tobias
'''

import socket
import struct
import time


BINARY_INTERFACE_HOST = "localhost"


# Twist (ClientMotionCommandDatagram)
#BINARY_INTERFACE_PORT = 9102
#unpacker = struct.Struct('<dQiQQBdddddddiii')


# Position (ClientLocalizationPoseDatagram)

BINARY_INTERFACE_PORT = 1235

# <：表示使用小端字节序（Little-Endian）进行编码，即最低有效字节排在最前面。
# dd：表示两个双精度浮点数（double）。
# Q：表示一个无符号长整数（unsigned long long）。
# i：表示一个整数（int）。
# QQ：表示两个无符号长整数。
# dddddddddddddd：表示16个双精度浮点数。
# Q：表示一个无符号长整数。
# ddd：表示三个双精度浮点数。


unpacker = struct.Struct('<ddQiQQddddddddddddddQddd')

print("host: " + BINARY_INTERFACE_HOST)

print("port: " + str(BINARY_INTERFACE_PORT))

 

 

# Creating a TCP/IP socket

running = True

while running:

    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # AF_INET: IPV4; SOCK_STREAM: TCP

    sock.settimeout(5)

    # Connecting to the server

    server_address = (BINARY_INTERFACE_HOST, BINARY_INTERFACE_PORT)

    print("connecting to %s:%s \n" % (server_address))

    connected = False

    try:

        while not connected:

            try:

                sock.connect(server_address)

                print("connected...")

                connected = True

                sock.settimeout(0.005)

            except ConnectionRefusedError:

                print("waiting for server...")

            except socket.error as e:

                print(str(e))

                print("nothing to do in here...")

    except KeyboardInterrupt:

        print("KeyboardInterrupt caught")  

        running = False

   

    # Start Reading Binary

    watchdog = 0

    if (running):
        data = None
        try:
            while watchdog < 5000:
                try:
                    # Increase Watchdog
                    watchdog += 1
                    # read the socket
                    if data == None:
                        data = sock.recv(unpacker.size)
                    else:
                        data = data + sock.recv(unpacker.size)
                except socket.timeout as e:
                    if data != None:
                        # upack the data, if there is enough
                        if len(data) < unpacker.size:
                            continue
                        unpacked_data = unpacker.unpack(data[:unpacker.size])
                        print(unpacked_data)

                        # Reset Databuffer and Watchdog
                        data = None
                        watchdog = 0
            # connection lost, start again
            print("connection lost")
            sock.close()

        except KeyboardInterrupt:
            print("KeyboardInterrupt caught")
            # Close Binary Socket
            print("closing socket")
            sock.close()
            running = False
        except Exception as e:
            print("Exception: " + str(e))
from http import client
import socket
import cv2
import pickle
import struct


#Creating Socket for connection
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host_name = socket.gethostname()
host_ip = socket.gethostbyname(host_name)
print('HOST IP: ', host_ip)
port = 9999
socket_adress = (host_ip, port)

#Socket Bind
server_socket.bind(socket_adress)

#Socket Listen
server_socket.listen(5)
print("LISTENING AT:", socket_adress)

#Socket accept
while True:
    client_socket,addr = server_socket.accept()
    print('GOT CONNECTION FROM:', addr)
    if client_socket:
        vid = cv2.VideoCapture(0)
        while(vid.isOpened()):
            img,frame = vid.read()
            a = pickle.dumps(frame)
            message = struct.pack("Q", len(a))+a
            client_socket.sendall(message)
            cv2.imshow('LIVE', frame)
            key = cv2.waitKey(1)
            if key == ord('q'):
                client_socket.close()
                
                










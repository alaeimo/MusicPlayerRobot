import socket
import serial

ser = serial.Serial('COM4', 9600, timeout=0)

serverSocket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
host = socket.gethostname()
host = socket.gethostbyname(socket.gethostname())
port = 80
serverSocket.bind((host,port))
serverSocket.listen(1)
print(socket.gethostbyname(socket.gethostname()))

while True:
    client,address =serverSocket.accept()
    msg = client.recv(1024)
    if(len(msg) !=0):
        msg = str(msg.decode('utf-8'))
        print("msg: " + msg)
        if('تاب تاب' in msg):
            print("1")
            ser.write(bytes("1",'ascii'))
        elif('خونه ی ماردبزرگه'in msg):
            print(2)
            ser.write(bytes("2",'ascii'))
        elif('تولدت مبارک 1'in msg):
            print(3)
            ser.write(bytes("3",'ascii'))
        elif('برف'in msg):
            print(4)
            ser.write(bytes("4",'ascii'))
        elif('خوشحال و شاد و خندان'in msg):
            print(5)
            ser.write(bytes("5",'ascii'))
        elif('تولدت مبارک 2'in msg):
            print(6)
            ser.write(bytes("6",'ascii'))
client.close() 
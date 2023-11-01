import serial

arduino_port = ""
baud = 9600
fileName="ultra.csv"
samples = 10
print_labels = False


ser = serial.Serial(arduino_port, baud)
print("Connected to Arduino port:" + arduino_port)
file = open(fileName, "a")
print("Created file")

line = 0

while line <= samples:


    if print_labels:
        if line==0:
            print("Printing Column Headers")
        else:
            print("Line " + str(line) + ": writing...")
    getdata=str(ser.readline())
    data=getdata[0:][:-2]
    print(data)            


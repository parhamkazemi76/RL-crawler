import serial 

"""
theese lines are needed to initialize the serial port 
make sure to write a line in arduino in setup part 
which says Serial.println("ready")
this is used to make sure that serial commiunication 
has started and there is no problem to it
"""
ser = serial.Serial()
ser.baudrate = 9600
ser.port = 'COM14'
ser.timeout = 20
ser.open()
while True:
    income = ser.readline()
    ser.flush() 
    serial_stat = income.decode('utf-8')
    if serial_stat == "ready\r\n" :
        break


"""
this is for reading an input and printing it as string

"""
#while 1:
#    inp = ser.readline()
#    ser.flush()
#    str_inp = inp.decode('utf-8')
#    print(str_inp)
"""
this is for sending a string and reciving the same string from the board

"""

for i in range(20):
    user = input("give me ")
    user_byt = bytes(user, 'utf-8')
    ser.write(user_byt)
    inp = ser.readline()
    ser.flush() 
    str_inp = inp.decode('utf-8')
    print(str_inp)


    

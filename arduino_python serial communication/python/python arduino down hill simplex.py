import scipy.optimize as optimize
import serial 
import random
import numpy as np
ser = serial.Serial()
ser.baudrate = 9600
ser.port = 'COM9'
ser.open()
while True:
    income = ser.readline()
    ser.flush() 
    serial_stat = income.decode('utf-8')
    if serial_stat == "ready\r\n" :
        break
trace_back_state = np.zeros((3,2))
trace_back_func = np.zeros((3,1))

def roll_forward_state(trace_back_state, a, b):
    k = 1
    for i in range(0,2):
        for j in range (0,2):
            trace_back_state[k+1][j] = trace_back_state[k][j]
        k = k - 1
    trace_back_state[0][0] = a
    trace_back_state[0][1] = b

def roll_forward_func(trace_back_func, reward):
    k = 1
    for i in range(0,2):
        trace_back_func[k+1][0] = trace_back_func[k][0]
        k = k - 1
    trace_back_func[0][0] = reward

def f(params):
    
    a, b = params 
    a = str(a)
    b = str(b)
    
    out = a + "&" + b
    out_byt = bytes(out, 'utf-8')
    ser.write(out_byt)
    inp = ser.readline()
    ser.flush() 
    str_inp = inp.decode('utf-8')
    reward = float(str_inp)
    roll_forward_state(trace_back_state, a, b)
    roll_forward_func(trace_back_func, reward)
    print(trace_back_state)
    #print(reward)
    return reward 

initial_guess = [10, 10]
result = optimize.minimize(f, initial_guess,(),'Nelder-Mead')
if result.success:
    fitted_params = result.x
    print(fitted_params)
else:
    raise ValueError(result.message)

print (result)
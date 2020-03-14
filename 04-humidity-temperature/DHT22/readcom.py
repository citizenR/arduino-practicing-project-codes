import time
import serial # pyserial

com = serial.Serial('COM4', 9600, timeout=1)

while True:
    time.sleep(1)
    com.readline()
#Code for Raspberry Pi Pico
import utime
import machine
from machine import I2C

I2C_ADDR = 0x08 #I2C Address of NodeMCU
data = "Some data to send" #Data to send to I2C device

def main():
    print("Initalizing I2C as Master")
    try:
        i2c = I2C(0, sda=machine.Pin(8), scl=machine.Pin(9), freq=10000)
    except:
        print("cannot connect")
    
    for _ in range(10):
        try:
            i2c.writeto(I2C_ADDR, data) #This line is responsible for sending data
                                #the above function can be called multiple times, changing
                                #the I2C_ADDR to transmit to various devices on the bus
                                #also changing the data variable will change the data being transmitted 
            utime.sleep_ms(50)
        except Exception as e:
            print(e)

main()
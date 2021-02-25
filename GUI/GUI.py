from kivy.app import App
from kivy.core.window import Window
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.widget import Widget
import serial
import struct

Window.clearcolor = (.9, .9, .9, 1)

class MyWidget(BoxLayout):
    while(1):
        while(1):
            try:
                port = input('Enter the number of the port where the Robot Arm is connected: ')
                port = 'COM'+port
                break
            except:
                print('Enter a valid number')
        try:
            ser = serial.Serial(port, baudrate = 9600, timeout = 1500)
            ser.close()
            break
        except:
            print('Unable to connect with the port')
    
    def baseMove(self, servo1, servo2, servo3, port):
        ser = serial.Serial(port, baudrate = 9600, timeout = 1500)
        ser.write(struct.pack('>B',1))
        ser.write(struct.pack('>B',servo1))
        ser.write(struct.pack('>B',2))
        ser.write(struct.pack('>B',servo2))
        ser.write(struct.pack('>B',3))
        ser.write(struct.pack('>B',servo3))
        ser.close()

    def dcLeft(self, port):
        ser = serial.Serial(port, baudrate = 9600, timeout = 1500)
        ser.write(struct.pack('>B',4))
        ser.close()
        
    def dcRight(self, port):
        ser = serial.Serial(port, baudrate = 9600, timeout = 1500)
        ser.write(struct.pack('>B',5))
        ser.close()
        
    def steppLeft(self, port):
        ser = serial.Serial(port, baudrate = 9600, timeout = 1500)
        ser.write(struct.pack('>B',6))
        ser.close()
        
    def steppRight(self, port):
        ser = serial.Serial(port, baudrate = 9600, timeout = 1500)
        ser.write(struct.pack('>B',7))
        ser.close()
        
class Window(App):
    def build(self):
        return MyWidget()
 
if __name__ == "__main__":
    window = Window()
    window.run()

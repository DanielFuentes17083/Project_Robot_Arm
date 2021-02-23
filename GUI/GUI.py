from kivy.app import App
from kivy.core.window import Window
from kivy.uix.boxlayout import BoxLayout

Window.clearcolor = (.9, .9, .9, 1)
pos1 = 0
pos2 = 0
pos3 = 0


class MyWidget(BoxLayout):
    def baseMove(self, servo1, servo2, servo3 ):
        print(1)
        print(servo1)
        print(2)
        print(servo2)
        print(3)
        print(servo3)

    def dcLeft(self):
        print('4')
        
    def dcRight(self):
        print('5')
        
    def steppLeft(self):
        print('6')
        
    def steppRight(self):
        print('7')
class Window(App):
    def build(self):
        return MyWidget()
 
if __name__ == "__main__":
    window = Window()
    window.run()

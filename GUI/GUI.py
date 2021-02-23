from kivy.app import App
from kivy.core.window import Window
from kivy.uix.widget import Widget

Window.clearcolor = (1, 1, 1, 1)
 
class MyWidget(Widget):
    pass
 
 
class Window(App):
    def build(self):
        return MyWidget()
 
 
if __name__ == "__main__":
    window = Window()
    window.run()

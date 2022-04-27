from tkinter import *
from tkinter import messagebox 

class Application(Frame):
    
    """一个经典的GUI类写法"""   
    def __init__(self, master=None):    
        super().__init__(master)
        self.master = master
        self.pack()
        self.createWidget()

    def createWidget(self):
        """这个就是
        """        
        self.label01 = Label(self, text="你好", width=10, height=2, bg="blue", fg="white")
        self.label01.pack()
        a= "就这一行吗"
        print(a)
        print("还有这一行吗")
if __name__ == '__main__':
    root = Tk()
    root.geometry("400x400+300+300")
    root.title("一个经典的GUI程序类对象的测试")
    app = Application(master=root)
    root.mainloop()

# 很奇怪的事情在TKinter里面是：
# 如果想要一个input widget，我们呢需要创建Entry，不大一样哦
from tkinter import *

from matplotlib.pyplot import text


root = Tk()
e = Entry(root,width=50, fg="white",bg="green",borderwidth=10)
e.pack()



def myClick():
    myLabel = Label(root, text="Hello" + e.get())
    myLabel.pack()
    # myLabel.grid(row=1,colcum=1)


myButton = Button(root, text="输入你的名字", padx=50,pady=100,command=myClick, fg="green",bg="#ff0000")
myButton.pack()


root.mainloop()
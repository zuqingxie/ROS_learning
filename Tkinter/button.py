
from tkinter import *

from matplotlib.pyplot import text


root = Tk()


def myClick():
    myLabel = Label(root, text="我按了这个按键")
    myLabel.pack()
    # myLabel.grid(row=1,colcum=1)


myButton = Button(root, text="按键", padx=50,pady=10,command=myClick, fg="green",bg="#ff0000")
myButton.pack()


root.mainloop()
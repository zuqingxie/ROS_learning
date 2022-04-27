from tkinter import Button, Tk
from tkinter.ttk import LabelFrame
from PIL import ImageTk, Image

root = Tk()
root.title("frame learning")
root.iconbitmap('@/home/zuqing/Downloads/apple_icon.xbm')

# 这个好像就是一个框框
frame = LabelFrame(root, text="This is my frame",padding=[50,50])
frame.pack(padx=100,pady=100)
b=Button(frame,text="dont click here")

b.pack()

root.mainloop()
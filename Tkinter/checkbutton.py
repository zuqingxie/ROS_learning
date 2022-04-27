from tkinter import *
from PIL import ImageTk, Image

root = Tk()
root.title("frame learning")
root.iconbitmap('@/home/zuqing/Downloads/apple_icon.xbm')
root.geometry("600x600")

# var = IntVar()
var = StringVar()
c = Checkbutton(root, text="check this box",variable=var,onvalue="Pizza",offvalue="汉堡")
c.deselect()
c.pack()
def show():
    my_label = Label(root,text=var.get()).pack()

my_Button = Button(root,text="show  the selection",command=show).pack()
root.mainloop()
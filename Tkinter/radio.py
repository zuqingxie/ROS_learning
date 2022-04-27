from tkinter import *
from PIL import ImageTk, Image

root = Tk()
root.title("frame learning")
root.iconbitmap('@/home/zuqing/Downloads/apple_icon.xbm')

type = IntVar()
type.set(0)

MODES = [
    ("Paper","Paper"),
    ("eat","eat"),
    ("choko","choko"),
    ("man","man"),
    
        
]

pizza= StringVar()
pizza.set("Paper")
for text, mode in MODES:
    Radiobutton(root,text=text,variable=pizza,value=mode).pack(anchor=E)

def Click(value):
    myLable = Label(root,text=value)
    myLable.pack()
    return

# Radiobutton(root, text="Perception",variable=type,value=1,command=lambda: Click(type.get())).pack()
# Radiobutton(root, text="Kamara",variable= type, value=2,command=lambda: Click(type.get())).pack()
# myLable = Label(root,text=type.get())
# myLable.pack()
myButton = Button(root,text="Click Me",command=lambda: Click(pizza.get())).pack()

root.mainloop()
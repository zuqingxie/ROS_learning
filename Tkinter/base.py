# 弹窗
# 点击然后打开一个窗口
from tkinter import *
from tkinter import messagebox
from PIL import ImageTk, Image

root = Tk()
root.title("my first window")
root.iconbitmap('@/home/zuqing/Downloads/apple_icon.xbm')

def open():
        
    top = Toplevel()
    top.title("my second window")
    my_img = ImageTk.PhotoImage(Image.open("/home/zuqing/ROS_learning/Tkinter/Images/star.png"))
    label = Label(top, image=my_img).pack()
    return 



button = Button(root, text="open the second window", command=open).pack()
root.mainloop()
# 下拉菜单选项
from tkinter import *
from PIL import ImageTk, Image

root = Tk()
root.title("frame learning")
root.iconbitmap('@/home/zuqing/Downloads/apple_icon.xbm')
root.geometry("600x600")

list = [
    "周一",
    "周二",
    "周三",
    "周四"
]
print(*list)

clicked = StringVar()
clicked.set(list[0])
drop =OptionMenu(root, clicked, *list)
drop.pack()
# 也可以使用python list



def show():
    my_label = Label(root,text=clicked.get()).pack()

my_b = Button(root, text="show selection",command= show).pack()

root.mainloop()
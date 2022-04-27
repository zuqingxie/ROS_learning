from tkinter import *
from PIL import ImageTk, Image
# 创建一个下拉按钮 并返回它的值

root = Tk()
root.title("标题")
root.geometry("400x400")

vertical = Scale(root, from_=0, to_=200)
vertical.pack()
horizontal = Scale(root, from_=0, to_=400,orient=HORIZONTAL)
# pack 最好不要写在后面，还是分开写来的合适！！！
horizontal.pack()

def slide():
    my_label = Label(root,text=str(horizontal.get()))
    my_label.pack()
    root.geometry(str(horizontal.get()) + "x" + str(vertical.get()))
my_button = Button(root,text="click me ",command=slide).pack()

root.mainloop()
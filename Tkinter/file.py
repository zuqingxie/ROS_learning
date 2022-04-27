from tkinter import *
import tkinter
from PIL import ImageTk, Image
from tkinter import filedialog


from matplotlib.pyplot import text

# 弹出特定的窗口，然后显示特定文件类型

root = Tk()
root.title("标题")


# # 打开了一个对话框
# a = filedialog.askopenfilename(initialdir="@/home/zuqing/ROS_learning/Tkinter/Images",title="Slect a picture",filetypes=(("png files","*.png"),("all files","*.*")))

# mL = Label(root,text=root.filename).pack()

# my_image = ImageTk.PhotoImage(Image.open(a))
# ma_image_label = Label(image=my_image).pack()

def open():
    # 这句话很重要！！！！淦
    global my_image
    filename = filedialog.askopenfilename(initialdir="/home/zuqing/ROS_learning/Tkinter/Images",title="Slect a picture",filetypes=(("png files","*.png"),("all files","*.*")))

    my_label = Label(root,text=filename)
    my_label.pack()

    my_image = ImageTk.PhotoImage(Image.open(filename))
    my_image_label = Label(image=my_image)
    my_image_label.pack()

my_button = Button(root, text="Open File", command=open).pack()

root.mainloop()
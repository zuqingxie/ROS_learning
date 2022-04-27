
# icon 图标
# pip install Pillow
# sudo apt-get install python3-pil python3-pil.imagetk
from tkinter import *
from PIL import ImageTk, Image

root = Tk()
root.iconbitmap('@/home/zuqing/Downloads/apple_icon.xbm')


# 展示图片
# my_img = ImageTk.PhotoImage(Image.open("/home/zuqing/Downloads/apple_icon.jpg"))

my_img = ImageTk.PhotoImage(Image.open("/home/zuqing/ROS_learning/Tkinter/Images/star.png"))
my_label = Label(image=my_img)
my_label.pack()

# 按键退出窗口
button_quit = Button(root, text="Exit program", command=root.quit)
button_quit.pack()

root.mainloop()
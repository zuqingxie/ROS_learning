
# icon 图标
# pip install Pillow
# sudo apt-get install python3-pil python3-pil.imagetk
from tkinter import *
from PIL import ImageTk, Image


root = Tk()
root.iconbitmap('@/home/zuqing/Downloads/apple_icon.xbm')


# 展示图片
my_img1 = ImageTk.PhotoImage(Image.open("/home/zuqing/Downloads/apple_icon.jpg"))
my_img2 = ImageTk.PhotoImage(Image.open("/home/zuqing/ROS_learning/Tkinter/Images/tree.png"))
my_img3 = ImageTk.PhotoImage(Image.open("/home/zuqing/ROS_learning/Tkinter/Images/star.png"))
my_img4 = ImageTk.PhotoImage(Image.open("/home/zuqing/ROS_learning/Tkinter/Images/ananas.png"))

image_list = [my_img1, my_img2, my_img3, my_img4]

global image_num
image_num = 0

my_label = Label(image=image_list[image_num])
my_label.grid(row=0,column=0,columnspan=3)


def back():
    global my_label
    global image_num
    global button_back
    if image_num >=0:
        
        my_label.grid_forget()

        image_num = image_num-1
        my_label= Label(image=image_list[image_num-1])
        my_label.grid(row=0,column=0,columnspan=3)
    else:
        button_back = Button(root,text="<<",state=DISABLED).grid(row=1,column=0)
    return

def forward():
    global my_label

    global image_num
    global button_forward

    image_num = image_num+1
    
    if image_num <= 2:
        my_label.grid_forget()
        my_label= Label(image=image_list[image_num])
        my_label.grid(row=0,column=0,columnspan=3)
    else:
        button_forward = Button(root,text=">>",state= DISABLED).grid(row=1,column=1)


    return


button_back=Button(root,text="<<",command=back).grid(row=1,column=0)
button_forward=Button(root,text=">>",command=forward).grid(row=1,column=1)
button_exit=Button(root,text="Exit", command=root.quit).grid(row=1,column=2)


root.mainloop()
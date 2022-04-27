
from tkinter import *
from tkinter import messagebox
from PIL import ImageTk, Image

root = Tk()
root.title("frame learning")
root.iconbitmap('@/home/zuqing/Downloads/apple_icon.xbm')

# 可以有很多中消息的类型：
#   showinfo, showwarning, showerror, askquestion, askokcancel,askyesno
def popup():
    response = messagebox.askyesno("This is my Popup!","Hello World")
    # Label(root, text=response).pack()
    if response ==1:
        Label(root, text="you clicked yes").pack()
    else:
        Label(root,text="you clicked no").pack()
Button(root, text="出现一个窗口",command=popup).pack(padx=100,pady=100)

root.mainloop()
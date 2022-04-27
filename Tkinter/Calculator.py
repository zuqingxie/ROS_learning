# 开发一个简单的计算器
import math
from tkinter import *


root = Tk()
root.title("计算器")

e = Entry(root,width=35,borderwidth=5)
e.grid(row=0,column=0,columnspan=3,padx=10,pady=10)
# e.insert(0, END)
def button_click(number):
    current = e.get()
    
    e.delete(0,END)
    e.insert(0,str(current)+str(number))
    return


def add():
    first_number = e.get()
    global f_num
    global math
    math = "+"
    f_num= first_number
    e.delete(0, END)
    # e.insert(e.get + f_num)


def mine():
    first_number = e.get()
    global f_num
    global math
    math = "-"
    f_num= first_number
    e.delete(0, END)


def multiple():
    first_number = e.get()
    global f_num
    global math
    math = "*"
    f_num= first_number
    e.delete(0, END)


def devide():
    first_number = e.get()
    global f_num
    global math
    math = "/"
    f_num= first_number
    e.delete(0, END)

def equal():
    if math == "+":
        second_number = e.get()
        e.delete(0, END)
        e.insert(0,int(f_num) + int(second_number))
    elif math == "-":
        second_number = e.get()
        e.delete(0, END)
        e.insert(0,int(f_num) - int(second_number))
    elif math == "*":
        second_number = e.get()
        e.delete(0, END)
        e.insert(0,int(f_num) * int(second_number))
    elif math == "/":
        second_number = e.get()
        e.delete(0, END)
        e.insert(0,int(f_num) / int(second_number))
    else:
       raise Exception("Error")
    
def clear():
    e.delete(0, END)
    return

myButton_1 = Button(root, text="1", padx=50,pady=20,command= lambda:button_click(1))
myButton_2 = Button(root, text="2", padx=50,pady=20,command= lambda: button_click(2))
myButton_3 = Button(root, text="3", padx=50,pady=20,command= lambda: button_click(3))
myButton_4 = Button(root, text="4", padx=50,pady=20,command= lambda: button_click(4))
myButton_5 = Button(root, text="5", padx=50,pady=20,command= lambda: button_click(5))
myButton_6 = Button(root, text="6", padx=50,pady=20,command= lambda: button_click(6))
myButton_7 = Button(root, text="7", padx=50,pady=20,command= lambda: button_click(7))
myButton_8 = Button(root, text="8", padx=50,pady=20,command= lambda: button_click(8))
myButton_9 = Button(root, text="9", padx=50,pady=20,command= lambda: button_click(9))
myButton_0 = Button(root, text="0", padx=50,pady=20,command= lambda:button_click(0))



myButton_add = Button(root, text="+", padx=50,pady=20,command=add)
myButton_mines = Button(root, text="-", padx=50,pady=20,command= mine)
myButton_time = Button(root, text="*", padx=50,pady=20,command=multiple)
myButton_dev = Button(root, text="/", padx=50,pady=20,command=devide)
myButton_equal = Button(root, text="=", padx=50,pady=20,command=equal)
myButton_clear = Button(root, text="clear", padx=50,pady=20,command=clear)


myButton_7.grid(row=1,column=0,padx=40,pady=20)
myButton_8.grid(row=1,column=1,padx=40,pady=20)
myButton_9.grid(row=1,column=2,padx=40,pady=20)
myButton_4.grid(row=2,column=0,padx=40,pady=20)
myButton_5.grid(row=2,column=1,padx=40,pady=20)
myButton_6.grid(row=2,column=2,padx=40,pady=20)
myButton_1.grid(row=3,column=0,padx=40,pady=20)
myButton_2.grid(row=3,column=1,padx=40,pady=20)
myButton_3.grid(row=3,column=2,padx=40,pady=20)
myButton_0.grid(row=3,column=2,padx=40,pady=20)
myButton_add.grid(row=5,column=0,padx=40,pady=20)
myButton_mines.grid(row=5,column=1,padx=40,pady=20)
myButton_dev.grid(row=5,column=2,padx=40,pady=20)
myButton_time.grid(row=6,column=0,padx=40,pady=20)
myButton_equal.grid(row=6,column=1,padx=40,pady=20)
myButton_clear.grid(row=6,column=2,padx=40,pady=20)

root.mainloop()

from tkinter import *
# 在tk里面所有的东西都叫做widget 小部件

root = Tk()
# 注意在tk里面一般就两步
#   creat
#   put it inthe sreen

#creating
myLabel1 = Label(root,text="my Label")
myLabel2 = Label(root,text="my name is zuqing!")

# showing in the screen
# 这里就不需要pack（）了grid已经把位置摆好了
myLabel1.grid(row=0,column=0)
myLabel2.grid(row=1,column=1)


#对于一个界面来说它是再一直的作循环的 loop always
# 只有一直在循环才能知道我们的鼠标在哪里

root.mainloop()
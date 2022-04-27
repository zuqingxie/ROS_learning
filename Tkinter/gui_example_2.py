
from tkinter import *
# 在tk里面所有的东西都叫做widget 小部件

root = Tk()
# 注意在tk里面一般就两步
#   creat
#   put it inthe sreen

#creating
myLabel = Label(root,text="my Label 标题")

# showing in the screen
myLabel.pack()

#对于一个界面来说它是再一直的作循环的 loop always
# 只有一直在循环才能知道我们的鼠标在哪里

root.mainloop()

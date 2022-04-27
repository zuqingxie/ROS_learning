
# sudo apt install python3-tk
from tkinter import Tk
from tkinter.ttk import *

root = Tk()
label = Label(root, text="Hello world Tkinter GUI Example")
label.pack()
root.mainloop()
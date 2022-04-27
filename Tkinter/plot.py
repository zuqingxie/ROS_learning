
from tkinter import *
from PIL import ImageTk, Image
import numpy as np

import matplotlib.pyplot as plt


root = Tk()
root.title("frame learning")
root.iconbitmap('@/home/zuqing/Downloads/apple_icon.xbm')


def graph():
    hause_prices = np.random.normal(20000, 2500,5000)
    plt.hist(hause_prices,50) # 50个柱状图
    plt.show()
    
my_button = Button(root,text="Graph It!", command=graph)
my_button.pack()


root.mainloop()
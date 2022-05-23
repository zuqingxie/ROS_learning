# # Imports
# from __future__ import division
# import numpy as np
# import pandas as pd
# from pandas import DataFrame, Series
# import matplotlib.pyplot as plt
# from scipy.stats import pearsonr
# import seaborn as sns
# sns.set(style='ticks', palette='Set2')
# # %matplotlib inline

# #GG
# df= pd.read_csv('/home/zuqing/Downloads/SLAM_eva_21653063230.831053.CSV', header = None, delim_whitespace=True, error_bad_lines=False)

# import seaborn as sns
# sns.set_theme(style="ticks")

# ax = df
# print(df.head)
# sns.pairplot(ax, hue=0, height=20, plot_kws={"s": 20})
# plt.show()

# numpy.random.bit_generator = numpy.random._bit_generator

# import numpy 
import pandas as pd
import matplotlib.pyplot as plt


columns = ["time","x_d","y_d","theta_d",]
df_new = pd.read_csv('/home/zuqing/Downloads/SLAM_eva1653063216.437485.CSV',usecols=columns)  # with delay compensation
df_old = pd.read_csv('/home/zuqing/Downloads/SLAM_eva_21653063230.831053.CSV',usecols=columns)  # old version
a = 0
if a == 1:
# df.set_index('Name').plot()
    fig, a = plt.subplots(3, sharex=True, sharey=True)
    fig.suptitle('Axes values are scaled individually by default')
    a[0].plot(df_new.time, df_new.x_d,'x') 
    a[0].plot(df_old.time, df_old.x_d) 

    a[1].plot(df_new.time, df_new.y_d)
    a[1].plot(df_old.time, df_old.y_d)
    a[2].plot(df_new.time, df_new.theta_d)
    a[2].plot(df_old.time, df_old.theta_d)
    plt.show()
else:
    plt.figure(figsize=(20,10))
    plt.plot(df_new.time, df_new.x_d, 'x') 
    plt.plot(df_old.time, df_old.x_d, 'x') 
    plt.xlabel("Time[s]",fontsize='15')	# adds a label in the x axis
    plt.ylabel("Error[cm]",fontsize='15')
    plt.legend(['with delay comp','without delay comp']) # 这个是把之前设置的标签之类的东西全部打印出来
    plt.grid()
    plt.show()

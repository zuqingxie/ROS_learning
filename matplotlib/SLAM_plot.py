
"""
This the python script for evaluate and compare the SLAM quality
"""

import numpy 
import pandas as pd
import matplotlib.pyplot as plt

#choose the module that you want to evaluate the SLAM
module = 1 # module choosing

# columns = ["time","x_d","y_d","theta_d","lidar_delay"]
columns = ["time","x_d","y_d","theta_d",]
# df_new = pd.read_csv('/home/greenteamsim/Downloads/skidpad.CSV',usecols=columns)  # with delay compensation
df_new = pd.read_csv('/home/greenteamsim/SLAM_eva_1654275557.554863.CSV',usecols=columns)  # with delay compensation
if module == 1:
    df_old = pd.read_csv('/home/greenteamsim/Downloads/skidpad.CSV',usecols=columns)  # old version
    # df.set_index('Name').plot()
    fig, a = plt.subplots(3, sharex=True, sharey=True)
    # fig.suptitle('Axes values are scaled individually by default')
    time = df_new.time -df_new.time[0]
    a[0].plot(time, df_new.x_d) 
    # a[0].plot(df_old.time, df_old.x_d)  
    a[0].legend("x error")
    a[0].grid()
    a[1].plot(time, df_new.y_d)
    # a[1].plot(df_old.time, df_old.y_d)
    a[1].grid()
    a[1].legend("y error")
    
    a[2].plot(time, df_new.theta_d)
    # a[2].plot(df_old.time, df_old.theta_d)
    a[2].grid() 
    a[2].legend("theta error")
    # plt.ylabel('x axis error')
    plt.xlabel("time[cm]",fontsize='15')
    plt.show()
else:
    # a = df_new.lidar_delay
    # mean = a.mean()*1000
    # cov = a.cov(a)*1000*1000
    # a = pd.Series(a)*1000
    # ax = a.plot.kde()
    # print("mean of the delay is :",mean,"ms" "  cov of the delay is : ", cov,"ms^2")
    plt.figure(figsize=(20,10))
    plt.plot(df_new.time, df_new.x_d, 'x') 
    plt.plot(df_new.time, df_new.y_d, 'x') 
    plt.plot(df_new.time, df_new.theta_d, 'x') 
    # plt.plot(df_new.time, df_new.lidar_delay * 100, 'o') 
    # plt.plot(df_old.time, df_old.x_d, 'x') 
    plt.xlabel("Time[s]",fontsize='15')	# adds a label in the x axis
    plt.ylabel("Error[cm]",fontsize='15')
    plt.legend(['x axis error','y axis error','theta error'])
    plt.grid()
    plt.show()

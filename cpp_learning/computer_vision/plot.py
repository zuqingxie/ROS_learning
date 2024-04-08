import matplotlib.pyplot as plt
import numpy as np

# 给定离散点数据
# data = [7.0, 5.4, 3.7, 2.7, 2.3, 2.0, 2.15, 2.4, 2.6, 2.7, 2.9]
data = [3.0, 2.9, 2.8, 2.7, 2.6, 2.5, 2.4, 2.3, 2.2, 2.1, 2.0,1.9,1.8,1.7,1.6,1.55,1.5,1.48,1.46,1.5,1.6,1.7,1.9,2.1,2.4,2.7]
x = np.arange(len(data))  # 创建索引数组作为横坐标

# 计算一介倒数（一阶导数）
first_derivative = np.gradient(data, x)

# 计算二介倒数（二阶导数）
second_derivative = np.gradient(first_derivative, x)

# 创建三张子图
plt.figure(figsize=(10, 15))

# 绘制原始数据点
plt.subplot(3, 1, 1)
plt.plot(x, data, marker='o', linestyle='-', label='原始数据')
plt.title("原始数据点")
plt.xlabel("数据点索引")
plt.ylabel("数据值")
plt.legend()

# 绘制一介倒数
plt.subplot(3, 1, 2)
plt.plot(x, first_derivative, marker='o', linestyle='-', label='一介倒数')
plt.title("一介倒数")
plt.xlabel("数据点索引")
plt.ylabel("一介倒数值")
plt.legend()

# 绘制二介倒数
plt.subplot(3, 1, 3)
plt.plot(x, second_derivative, marker='o', linestyle='-', label='二介倒数')
plt.title("二介倒数")
plt.xlabel("数据点索引")
plt.ylabel("二介倒数值")
plt.legend()

# 调整子图之间的间距
plt.tight_layout()

# 显示图形
plt.show()

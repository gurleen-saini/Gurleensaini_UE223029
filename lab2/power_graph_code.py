import matplotlib.pyplot as plt
import numpy as np

b=[27.1,54.3,93.1,121.3,132.8,158.5,198.9,216.5,240,287.2,314,325,352.1,398.3,442,493.7,502.1,523.6,576,657.4,672.3,708.6,677.5,715.2,728.1,770.4,821.7,921.8,867.4,854.7,866,946,949.3,981.9,1033.4,1113.1,1114.2,1114.9,1251.6,]

print(len(b))
b.sort()

a=np.arange(10000,1000001,10000)
print(a)

# Adjust according to the length of b
a=[10000,   20000,   30000,   40000,   50000,   60000,   70000,
         80000,   90000,  100000,  110000,  120000,  130000,  140000,
        150000,  160000,  170000,  180000,  190000,  200000,  210000,
        220000,  230000,  240000,  250000,  260000,  270000,  280000,
        290000,  300000,  310000,  320000,  330000,  340000,  350000,
        360000,  370000,  380000,  390000]

plt.figure(figsize=(10,6))
plt.plot(a,b,color='g',marker='o',label='Growth Rate')
plt.title('Power with : O(m)' , fontsize=20)
plt.xlabel('No Of Inputs',fontsize=18)
plt.ylabel('Timing',fontsize=18)
plt.legend()
plt.show()


# For small time complexity
b=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,]

print(len(b))
b.sort()

a=np.arange(10000,1000001,10000)
print(a)

plt.figure(figsize=(10,6))
plt.plot(a,b,color='g',marker='o',label='Growth Rate')
plt.title('Power with : O(log m base 2)' , fontsize=20)
plt.xlabel('No Of Inputs',fontsize=18)
plt.ylabel('Timing',fontsize=18)
plt.legend()
plt.show()
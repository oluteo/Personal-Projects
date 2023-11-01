import numpy as np
import math
import matplotlib.pyplot as plt

l1 = 40 #cm
l2 = 40 #cm
theta1 = np.linspace(0,180,num=200)
theta2 = np.linspace(0,350,num=200)

#print(theta1)
#print(theta2)
#x = []
#x = l1*np.cos(np.deg2rad(theta1))- l2*np.cos(np.deg2rad(theta1+theta2))

#y = []
#y = l1*np.sin(np.deg2rad(theta1))- l2*np.sin(np.deg2rad(theta1+theta2))
#print(x)
#print(y)


THETA1,THETA2 = np.meshgrid(theta1,theta2)
x = []
x = l1*np.cos(np.deg2rad(THETA1))- l2*np.cos(np.deg2rad(THETA1+THETA2))

y = []
y = l1*np.sin(np.deg2rad(THETA1))- l2*np.sin(np.deg2rad(THETA1+THETA2))
print(x)
print(y)

plt.scatter(x,y)
plt.show
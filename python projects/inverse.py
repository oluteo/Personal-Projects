import numpy as np
import math
import matplotlib.pyplot as plt

l1 = 40 #cm
l2 = 40 #cm
x= 10 #cm
y = 10 #cm
phi =90 #cm
theta1 = np.linspace(0,180)
theta2 = np.linspace(0,220)
THETA2,THETA1 = np.meshgrid(theta2,theta1)
THETA2 = math.acos(((x**2)+(y**2)-(l1**2)-(l1**2))/(2*(l1)*(l2)))

THETA1 =  (phi)- (THETA2)
flat_x =np.reshape(x,x.size)
flat_y = np.reshape(y,y.size)
    ggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggflat_THETA1 = np.reshape(THETA1,THETA1.size)
flat_THETA2 = np.reshape(THETA2,THETA2.size)

xa=np.linspace(0,l1*np.cos(np.deg2rad(flat_THETA1)),nn)
xb=np.linspace(xa[-1+len(xa)],xa[-1+len(xa)]+L2*np.cos(np.deg2rad(flat_THETA1+flat_THETA2)),nn)
xb_record=xb
yb_record=yb
xa_record=xa
ya_record=ya

plt.plot(xa_record[kk],ya_record[kk],color = 'blue', label = 'LINK 2')
plt.plot(xb_record[kk],yb_record[kk],color = 'green', label = 'LINK 2')

#print(theta1)
#print(theta2)
#x = []
#x = l1*np.cos(np.deg2rad(theta1))- l2*np.cos(np.deg2rad(theta1+theta2))

#y = []
#y = l1*np.sin(np.deg2rad(theta1))- l2*np.sin(np.deg2rad(theta1+theta2))
#print(x)
#print(y)
x=[]
y=[]
xb=[]
yb=[]
xc=[]
yc=[]
xa=[]
ya=[]




xb_record=[[0 for col in range(nn)] for row in range(len(flat_x))]
yb_record=[[0 for col in range(nn)] for row in range(len(flat_x))]
xa_record=[[0 for col in range(nn)] for row in range(len(flat_x))]
ya_record=[[0 for col in range(nn)] for row in range(len(flat_x))]




#print(theta1)
#print(theta2)


plt.scatter(theta1,theta2)
plt.show

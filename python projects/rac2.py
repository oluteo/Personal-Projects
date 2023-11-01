import numpy as np
import matplotlib.pyplot as plt
import threading
import time

nn=10 #number of points in drawing y = x+c
n = 20 #number of angle elements in theta1 and theta2

L1 = 30  #cm
L2 = 20 #cm
L3 = 10 #cm
is_plot = 0


def draw():
    kk = 0
    global is_plot
    while is_plot:
        if kk<n**2:
            plt.figure(1)
            plt.cla()
            plt.xlim([-L1-L2-L3-5,L1+L2+L3+5])
            plt.ylim([-L1-L2-L3-5,L1+L2++L3+5])
            #plt.legend()

            plt.plot(xa_record[kk],ya_record[kk],color = 'blue', label = 'LINK 2')
            plt.plot(xb_record[kk],yb_record[kk],color = 'green', label = 'LINK 2')
            plt.plot(xc_record[kk],yc_record[kk],color = 'black', label = 'LINK 2')
            plt.scatter(flat_x[[f for f in range(1+kk)]],flat_y[[f for f in range(1+kk)]],s=5,c='red') 
            
            plt.pause(0.0000000000000000000001)
            kk = kk+1
    plt.close("all")
    

x=[]
y=[]
xb=[]
yb=[]
xc=[]
yc=[]
xa=[]
ya=[]



theta1 = np.linspace(20,150,num=n)
theta2 = np.linspace(20,220,num=n)
theta3 = np.linspace(20,320,num =n)
THETA2,THETA1,THETA3 = np.meshgrid(theta2,theta1,theta3)
x = (L1 * np.cos(np.deg2rad(THETA1))) + (L2 * np.cos(np.deg2rad(THETA1 + THETA2))) + (L3 * np.cos(np.deg2rad(THETA1 + THETA2 + THETA3)))
y = (L1 * np.sin(np.deg2rad(THETA1))) + (L2 * np.sin(np.deg2rad(THETA1 + THETA2))) + (L3 * np.sin(np.deg2rad(THETA1 + THETA2 + THETA3)))


flat_THETA3 = np.reshape(THETA3,THETA3.size)
flat_THETA2 = np.reshape(THETA2,THETA2.size)
flat_THETA1 = np.reshape(THETA1,THETA1.size)


flat_x =np.reshape(x,x.size)
flat_y = np.reshape(y,y.size)


xb_record=[[0 for col in range(nn)] for row in range(len(flat_x))]
yb_record=[[0 for col in range(nn)] for row in range(len(flat_x))]
xa_record=[[0 for col in range(nn)] for row in range(len(flat_x))]
ya_record=[[0 for col in range(nn)] for row in range(len(flat_x))]
xc_record=[[0 for col in range(nn)] for row in range(len(flat_x))]
yc_record=[[0 for col in range(nn)] for row in range(len(flat_x))]

#loop starts
for count in range (len(flat_x)):
    M=np.tan(np.deg2rad(flat_THETA1[count]))
    xa=np.linspace(0,L1*np.cos(np.deg2rad(flat_THETA1[count])),nn)
    ya=0+M*xa
    
    Mb=np.tan(np.deg2rad(flat_THETA1[count]+flat_THETA2[count]-180))
    xb=np.linspace(xa[-1+len(xa)],xa[-1+len(xa)]+L2*np.cos(np.deg2rad(flat_THETA1[count]+flat_THETA2[count]-180)),nn)
    Cb = ya[-1+len(ya)] - Mb*xa[-1+len(xa)]
    yb= Cb +( Mb*xb)

    Mc= np.tan(np.deg2rad(flat_THETA1[count]+flat_THETA2[count]+flat_THETA3[count]-300))
    xc= np.linspace(xb[-1+len(xb)],xb[-1+len(xb)]+L2*np.cos(np.deg2rad(flat_THETA1[count]+flat_THETA2[count]+flat_THETA3[count]-300)),nn)
    Cc = yb[-1+len(yb)] - Mc*xb[-1+len(xb)]
    yc= Cc + (Mc*xc)

    xb_record[count]=xb
    yb_record[count]=yb
    xa_record[count]=xa
    ya_record[count]=ya
    xc_record[count]=xc
    yc_record[count]=yc
    is_plot = 1

threading.Thread(target=draw).start()



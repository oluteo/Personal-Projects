import numpy as np

l1 = 40
l2 = 20
l3 = 10
phi = 105
x3 = 17.411809548974794
y3 = 64.30027441426823
x2 = x3 - (l3*np.cos(np.deg2rad(phi)))
y2 = y3 - (l3*np.sin(np.deg2rad(phi)))

theta2 = np.arccos((x2**2 + y2**2 - l1**2 - l2**2)/(2 * l1 * l2))
theta1 = np.arccos(((y2*l2*np.sin(theta2)) + ((l1 + l2*np.cos(theta2))*x2)) / (x2**2 + y2**2))

#theta1 = phi - theta2

THETA2 = np.rad2deg(theta2)
THETA1 = np.rad2deg(theta1)
THETA3 = phi-(THETA1 + THETA2)

print("The angles are ", THETA1, ", ", THETA2, ", ", THETA3)

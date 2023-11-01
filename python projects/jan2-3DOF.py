import numpy as np

l1 = 40
l2 = 20
l3 = 10
theta1 = 60
theta2 = 30
theta3 = 15

x = (l1 * np.cos(np.deg2rad(theta1))) + (l2 * np.cos(np.deg2rad(theta1 + theta2))) + (l3 * np.cos(np.deg2rad(theta1 + theta2 + theta3)))
y = (l1 * np.sin(np.deg2rad(theta1))) + (l2 * np.sin(np.deg2rad(theta1 + theta2))) + (l3 * np.sin(np.deg2rad(theta1 + theta2 + theta3)))

print("The point is ", x, ", ", y)

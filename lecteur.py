import numpy as np
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt


colors = ["#cf7f0e", "#729fcf", "#555753", "#f667ca", "#9156f6", "#73d216", "#ef2929", "#75507b"]



def readtraj(filename):
    plt.ion()
    fig = plt.figure()
    ax = fig.gca(projection='3d')
    ax.set_color_cycle(colors)
    ax.ticklabel_format(style = "scientific", scilimits =(0,0))

    t = np.loadtxt(filename)
    N = t.shape[1]
    n=0;i=0
    while n+2 < N:
        ax.scatter(t[:,n][-1], t[:,n+1][-1], t[:,n+2][-1])
        ax.plot(t[:,n], t[:,n+1], t[:,n+2])
        n+=3

def readenergy(filename):
    plt.ion()
    fig = plt.figure(figsize = [6,3])
    ax = fig.gca()
    ax.set_color_cycle(colors)
    ax.ticklabel_format(style = "scientific", scilimits =(0,0))
    t = np.loadtxt(filename)
    plt.plot(t[:,0],t[:,1], label = 'potential', linewidth = 3)
    plt.plot(t[:,0], t[:,2], label = 'kinectic', linewidth = 3)
    plt.plot(t[:,0], t[:,3], label ='total', linewidth = 3)
    plt.legend()
    plt.xlabel('epoch')
    plt.ylabel('dimensionless energy')



readtraj('results/traj.txt')
readenergy('results/energycurve.txt')
c = raw_input("press 'enter' to close  ")
plt.close("all")




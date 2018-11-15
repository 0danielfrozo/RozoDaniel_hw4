import numpy as np
import matplotlib.pylab as plt 
import sys
from mpl_toolkits.mplot3d import Axes3D

datos=np.genfromtxt(sys.argv[1]);

fig=plt.figure()
plt.plot(datos[:,0],datos[:,1]);
plt.xlabel('Distancia [m]')
plt.ylabel('Altura [m]')
plt.ylim(ymin = 0);
fig.savefig('45grados.jpg');


datos=np.genfromtxt(sys.argv[2]);
longitud=np.shape(datos)[0];


i=0;
n=1;
fig=plt.figure()
while i<longitud:
 theta=n*10;
 plt.plot(datos[i,:],datos[i+1,:],label='Angulo %s' %theta )
 i=i+2;
 n=n+1;
plt.xlabel('Distancia [m]')
plt.ylabel('Altura [m]')
plt.ylim(ymin = 0,ymax = 5000)
plt.xlim(xmin=0,xmax = 10000)
plt.legend()
fig.savefig('grados.jpg');


datos=np.genfromtxt(sys.argv[3]);
n=50**2;
fig = plt.figure()

ax = fig.add_subplot(2, 2, 1, projection='3d');
scat=ax.scatter(datos[:n,0],datos[:n,1],datos[:n,2],s=2, c=datos[:n,2],vmin=10,vmax=100)
ax.set_title('t=0s')
fig.colorbar(scat, ticks=np.arange(10,110,10))

ax = fig.add_subplot(2, 2, 2, projection='3d');
scat2=ax.scatter(datos[n:2*n,0],datos[n:2*n,1],datos[n:2*n,2],s=2, c=datos[n:2*n,2],vmin=10,vmax=100)
ax.set_title('t=5s')
fig.colorbar(scat2, ticks=np.arange(10,110,10))

ax = fig.add_subplot(2, 2, 3, projection='3d');
scat3=ax.scatter(datos[2*n:3*n,0],datos[2*n:3*n,1],datos[2*n:3*n,2],s=2, c=datos[2*n:3*n,2],vmin=10,vmax=100)
ax.set_title('t=10s')
fig.colorbar(scat3, ticks=np.arange(10,110,10))

ax = fig.add_subplot(2, 2, 4, projection='3d');
scat4=ax.scatter(datos[3*n:4*n,0],datos[3*n:4*n,1],datos[3*n:4*n,2],s=2, c=datos[3*n:4*n,2],vmin=10,vmax=100)
ax.set_title('t=inf')
fig.colorbar(scat4, ticks=np.arange(10,110,10))

fig.savefig('cond_1.jpg');


datos=np.genfromtxt(sys.argv[4]);
n=50**2;
fig = plt.figure()

ax = fig.add_subplot(2, 2, 1, projection='3d');
scat=ax.scatter(datos[:n,0],datos[:n,1],datos[:n,2],s=2, c=datos[:n,2],vmin=10,vmax=100)
ax.set_title('t=0s')
fig.colorbar(scat, ticks=np.arange(10,110,10))

ax = fig.add_subplot(2, 2, 2, projection='3d');
scat2=ax.scatter(datos[n:2*n,0],datos[n:2*n,1],datos[n:2*n,2],s=2, c=datos[n:2*n,2],vmin=10,vmax=100)
ax.set_title('t=10s')
ax.set_zlim(zmin=0,zmax = 100)
fig.colorbar(scat2, ticks=np.arange(10,110,10))

ax = fig.add_subplot(2, 2, 3, projection='3d');
scat3=ax.scatter(datos[2*n:3*n,0],datos[2*n:3*n,1],datos[2*n:3*n,2],s=2, c=datos[2*n:3*n,2],vmin=10,vmax=100)
ax.set_title('t=100s')
ax.set_zlim(zmin=0,zmax = 100)
fig.colorbar(scat3, ticks=np.arange(10,110,10))

ax = fig.add_subplot(2, 2, 4, projection='3d');
scat4=ax.scatter(datos[3*n:4*n,0],datos[3*n:4*n,1],datos[3*n:4*n,2],s=2, c=datos[3*n:4*n,2],vmin=10,vmax=100)
ax.set_title('t=inf')
ax.set_zlim(zmin=0,zmax = 100)
fig.colorbar(scat4, ticks=np.arange(10,110,10))

fig.savefig('cond_3.jpg');



datos=np.genfromtxt(sys.argv[5]);
n=50**2;
fig = plt.figure()

ax = fig.add_subplot(2, 2, 1, projection='3d');
scat=ax.scatter(datos[:n,0],datos[:n,1],datos[:n,2],s=2, c=datos[:n,2],vmin=10,vmax=100)
ax.set_title('t=0s')
fig.colorbar(scat, ticks=np.arange(10,110,10))

ax = fig.add_subplot(2, 2, 2, projection='3d');
scat2=ax.scatter(datos[n:2*n,0],datos[n:2*n,1],datos[n:2*n,2],s=2, c=datos[n:2*n,2],vmin=10,vmax=100)
ax.set_title('t=10s')
ax.set_zlim(zmin=0,zmax = 100)
fig.colorbar(scat2, ticks=np.arange(10,110,10))

ax = fig.add_subplot(2, 2, 3, projection='3d');
scat3=ax.scatter(datos[2*n:3*n,0],datos[2*n:3*n,1],datos[2*n:3*n,2],s=2, c=datos[2*n:3*n,2],vmin=10,vmax=100)
ax.set_title('t=100s')
ax.set_zlim(zmin=0,zmax = 100)
fig.colorbar(scat3, ticks=np.arange(10,110,10))

ax = fig.add_subplot(2, 2, 4, projection='3d');
scat4=ax.scatter(datos[3*n:4*n,0],datos[3*n:4*n,1],datos[3*n:4*n,2],s=2, c=datos[3*n:4*n,2],vmin=10,vmax=100)
ax.set_title('t=inf')
ax.set_zlim(zmin=0,zmax = 100)
fig.colorbar(scat4, ticks=np.arange(10,110,10))

fig.savefig('cond_2.jpg');





 



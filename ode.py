import numpy as np
import matplotlib.pylab as plt 
import sys

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




 



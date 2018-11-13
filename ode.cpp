#include <iostream>
#include <fstream>
#include <math.h> 

double h;
int npuntos;
double *x;
double *y;

double k1_x;
double k2_x;
double k3_x;
double k4_x;
double kpromedio_x;
double k1_y;
double k2_y;
double k3_y;
double k4_y;
double kpromedio_y;
double k1_vx;
double k2_vx;
double k3_vx;
double k4_vx;
double kpromedio_vx;
double k1_vy;
double k2_vy;
double k3_vy;
double k4_vy;
double kpromedio_vy;

double fxprima(double t, double x, double vx);
double fyprima(double t, double y, double vy);
double fvxprima(double t, double vy, double vx);
double fvyprima(double t, double vy, double vx);
void runge_kutta(double tmax, double theta);

using namespace std;

int main()
{ 

 runge_kutta(42.32, 45);
 ofstream datos;
 datos.open("45grados.txt");
 for(int i=0;i<npuntos;i++)
 {
  datos <<x[i]<<" "<< y[i]<<endl;
 }
 datos.close();

 datos.open("grados.txt");
 for(int j=1;j<8;j++){
 runge_kutta(42.32*8, 10*j);
  for(int i=0;i<npuntos;i++)
 {
  datos <<x[i]<<" ";
 } 
 datos<<endl;
 for(int i=0;i<npuntos;i++)
 {
  datos <<y[i]<<" ";
 }
 datos<<endl;

 }
 datos.close();

 return 0;
}

void runge_kutta(double tmax, double theta){
 h=0.01;
 double tmin=0;
 npuntos=(tmax-tmin)/h;
 double t[npuntos];
 x=new double[npuntos];
 double vx[npuntos];
 y=new double[npuntos];
 double vy[npuntos];
 
 
 t[0]=tmin;
 x[0]=0;
 y[0]=0;
 vx[0]=300*cos(3.1415*theta/180);
 vy[0]=300*sin(3.1415*theta/180);

 for(int i =1;i<npuntos;i++)
 {
    k1_x = h*fxprima(t[i-1],x[i-1],vx[i-1]);
    k1_y = h*fyprima(t[i-1],y[i-1],vy[i-1]);
    k1_vx = h*fvxprima(t[i-1],vy[i-1],vx[i-1]);
    k1_vy = h*fvyprima(t[i-1],vy[i-1],vx[i-1]);

    k2_x = h*fxprima(t[i-1]+0.5*h, x[i-1]+0.5*k1_x,vx[i-1]+0.5*k1_vx);
    k2_y = h*fyprima(t[i-1]+0.5*h, y[i-1]+0.5*k1_y,vy[i-1]+0.5*k1_vy);
    k2_vx = h*fvxprima(t[i-1]+0.5*h, vy[i-1]+0.5*k1_vy,vx[i-1]+0.5*k1_vx);
    k2_vy = h*fvyprima(t[i-1]+0.5*h, vy[i-1]+0.5*k1_vy,vx[i-1]+0.5*k1_vx);
    
    k3_x = h*fxprima(t[i-1]+0.5*h, x[i-1]+0.5*k2_x,vx[i-1]+0.5*k2_vx);
    k3_y = h*fyprima(t[i-1]+0.5*h, y[i-1]+0.5*k2_y,vy[i-1]+0.5*k2_vy);
    k3_vx = h*fvxprima(t[i-1]+0.5*h, vy[i-1]+0.5*k2_vy,vx[i-1]+0.5*k2_vx);
    k3_vy = h*fvyprima(t[i-1]+0.5*h, vy[i-1]+0.5*k2_vy,vx[i-1]+0.5*k2_vx);

    k4_x = h*fxprima(t[i-1]+h,x[i-1]+k3_x,vx[i-1]+k3_vx);
    k4_y = h*fyprima(t[i-1]+h,y[i-1]+k3_y,vy[i-1]+k3_vy);
    k4_vx = h*fvxprima(t[i-1]+h,vy[i-1]+k3_vy,vx[i-1]+k3_vx);
    k4_vy = h*fvyprima(t[i-1]+h,vy[i-1]+k3_vy,vx[i-1]+k3_vx);


    kpromedio_x = (1.0/6.0)*(k1_x+2.0*k2_x+2.0*k3_x+k4_x);
    kpromedio_y = (1.0/6.0)*(k1_y+2.0*k2_y+2.0*k3_y+k4_y);
    kpromedio_vx = (1.0/6.0)*(k1_vx+2.0*k2_vx+2.0*k3_vx+k4_vx); 
    kpromedio_vy = (1.0/6.0)*(k1_vy+2.0*k2_vy+2.0*k3_vy+k4_vy);
      
    t[i] = t[i-1] + h;
    x[i] = x[i-1] + kpromedio_x;
    y[i] = y[i-1] + kpromedio_y;
    vx[i] = vx[i-1] + kpromedio_vx;
    vy[i] = vy[i-1] + kpromedio_vy;
 }
}

double fxprima(double t, double x, double vx)
{
 return vx;
}

double fyprima(double t, double y, double vy)
{
 return vy;
}

double fvxprima(double t, double vy, double vx)
{
  double g=10;
  int c=0.2;
  double m=0.2;

 return (-c*(vy*vy+vx*vx)/m) *vx/sqrt(vy*vy+vx*vx);
}

double fvyprima(double t, double vy, double vx)
{
  double g=10;
  int c=0.2;
  double m=0.2;

 return -g-(c*(vy*vy+vx*vx)/m )*vy/sqrt(vy*vy+vx*vx);
}

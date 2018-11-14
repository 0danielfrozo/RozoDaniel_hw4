#include <iostream>
#include <fstream>
using namespace std;

double k = 1.62;
double Cp= 820;
double rho=2.71;
double T_varilla=100;

double calcita[50][50];
double pos_varilla[50][50];

void varilla(int lon ,double diam);
void cond_ini_1(int lon, double t_tot, double dt);

int main(){
 int lon=50;
 double diam=10;
 varilla(lon,diam);

 ofstream datos;
 datos.open("PDE.txt");
 
 cond_ini_1(lon,0,0);
 for( int x=0;x<lon;x++){
  for ( int y=0;y<lon;y++){
   datos <<x<<" "<< y<<" "<< calcita[x][y]<<endl;
  }
 }
 datos.close();
 
 return 0;
}





void varilla(int lon ,double diam){
 for( int x=0;x<lon;x++){
  for ( int y=0;y<lon;y++){
   if( ((x-lon/2)*(x-lon/2)+(y-lon/2)*(y-lon/2))<diam*diam/4){
    calcita[x][y]=T_varilla;
    pos_varilla[x][y]=1;
   }
  }
 }
}

void cond_ini_1(int lon, double t_tot, double dt){
 double T_front=10;
 for(int i=0;i<lon;i++){
 calcita[0][i]=T_front;
 calcita[lon-1][i]=T_front;
 calcita[i][0]=T_front;
 calcita[i][lon-1]=T_front;
 }
 if(dt==0){dt=1;} 
 double pasos_tiempo=t_tot/dt;
 double calcita_nuevo[50][50];
 for(int t=0;t<pasos_tiempo;t++){
 



 }

 
}





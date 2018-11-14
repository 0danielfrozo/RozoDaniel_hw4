#include <iostream>
#include <fstream>
using namespace std;

double k = 1.62;
double Cp= 820;
double rho=2.71;
double T_varilla=100;
double T_inicial=10;
int lon=50;

ofstream datos;

double calcita[50][50];
double pos_varilla[50][50];

void impresion();
void varilla(int lon ,double diam);
void cond_ini_1(int lon, double t_tot, double dt);

int main(){

 double diam=10;
 varilla(lon,diam);

 
 datos.open("PDE.txt");
 
 cond_ini_1(lon,0,0.005);
 impresion();
 varilla(lon,diam);
 cond_ini_1(lon,1,0.005);
 impresion();
 varilla(lon,diam);
 cond_ini_1(lon,3,0.005);
 impresion();
 varilla(lon,diam);
 cond_ini_1(lon,5,0.005);
 impresion();
 

 datos.close();
 
 return 0;
}



void impresion(){
for( int x=0;x<lon;x++){
  for ( int y=0;y<lon;y++){
   datos <<x<<" "<< y<<" "<< calcita[x][y]<<endl;
  }
}
}

void varilla(int lon ,double diam){
 for( int x=0;x<lon;x++){
  for ( int y=0;y<lon;y++){
   if( ((x-lon/2)*(x-lon/2)+(y-lon/2)*(y-lon/2))<diam*diam/4){
    calcita[x][y]=T_varilla;
    pos_varilla[x][y]=1;
   }
   else{
    calcita[x][y]=T_inicial;
   }
  }
 }
}

void cond_ini_1(int lon, double t_tot, double dt){
 double T_front=10;
 double h=0.01;
 double nu=k/(rho*Cp);
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
  for(int x=1;x<lon-1;x++){
   for (int y=1;y<lon-1;y++){
    if(pos_varilla[x][y]!=1){
     calcita_nuevo[x][y]=calcita[x][y]+(dt*nu/(h*h))*((calcita[x+1][y]-2*calcita[x][y]+calcita[x-1][y])+(calcita[x][y+1]-2*calcita[x][y]+calcita[x][y-1]));
    }
    else{
     calcita_nuevo[x][y]=calcita[x][y];
    }
   }
  }
  for( int x=1;x<lon-1;x++){
   for ( int y=1;y<lon-1;y++){
    calcita[x][y]=calcita_nuevo[x][y];
   }
  }
 }
}

 






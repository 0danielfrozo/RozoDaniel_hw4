#include <iostream>
double k = 1.62;
double Cp= 820;
double rho=2.71;
double T_varilla=100;

double *calcita;

int main(){
double lon=50;
double diam=10;
calcita= new double[long][long];
varilla(lon,diam);



return 0;
}





void varilla(double lon ,double diam){
 for( int x=0;x<lon;x++){
  for ( int y=0;y<lon;y++){
   if( ((x-lon/2)*(x-lon/2)+(y-lon/2)*(y-lon/2))<diam*diam/4){
    calcita[x][y]=T_varilla;
   }
  }
 }
}



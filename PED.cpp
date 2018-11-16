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
double *promedio;


void impresion();
void varilla(int lon ,double diam);
void cond_ini_1(int lon, double t_tot, double dt);
void cond_ini_2(int lon, double t_tot, double dt);
void cond_ini_3(int lon, double t_tot, double dt);

int main(){

 double diam=10;
  
 datos.open("con_1.txt");
 
 varilla(lon,diam);
 cond_ini_1(lon,0,0.005);
 impresion();
 varilla(lon,diam);
 cond_ini_1(lon,5,0.005);
 impresion();
 varilla(lon,diam);
 cond_ini_1(lon,10,0.005);
 impresion();
 varilla(lon,diam);
 cond_ini_1(lon,50,0.005);
 impresion();
 
 datos.close();
 datos.open("prom_1.txt");
 for(int i =0; i<50/0.005;i++){
  datos <<i*0.005<<" "<< promedio[i]<<endl;
 }
 datos.close();
  
 datos.open("con_2.txt");
 
 varilla(lon,diam);
 cond_ini_2(lon,0,0.005);
 impresion();
 varilla(lon,diam);
 cond_ini_2(lon,10,0.005);
 impresion();
 varilla(lon,diam);
 cond_ini_2(lon,100,0.005);
 impresion();
 varilla(lon,diam);
 cond_ini_2(lon,350,0.005);
 impresion();
 
 datos.close();
 
 datos.open("prom_2.txt");
 for(int i =0; i<350/0.005;i++){
  datos <<i*0.005<<" "<< promedio[i]<<endl;
 }
 datos.close();
 
 datos.open("con_3.txt");

 varilla(lon,diam);
 cond_ini_3(lon,0,0.005);
 impresion();
 varilla(lon,diam);
 cond_ini_3(lon,10,0.005);
 impresion();
 varilla(lon,diam);
 cond_ini_3(lon,100,0.005);
 impresion();
 varilla(lon,diam);
 cond_ini_3(lon,350,0.005);
 impresion();
 
 datos.close();
 
  datos.open("prom_3.txt");
 for(int i =0; i<350/0.005;i++){
  datos <<i*0.005<<" "<< promedio[i]<<endl;
 }
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
 int pasos_tiempo=t_tot/dt;
 promedio=new double[pasos_tiempo];
 double calcita_nuevo[50][50];
 for(int t=0;t<pasos_tiempo;t++){
  double sum=0;
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
    sum+=calcita_nuevo[x][y];
   }
  }
  promedio[t]=sum/(50*50);
 }
}



void cond_ini_2(int lon, double t_tot, double dt){
 double h=0.01;
 double nu=k/(rho*Cp);
 
 if(dt==0){dt=1;} 
 int pasos_tiempo=t_tot/dt;
 promedio=new double[pasos_tiempo];
 double calcita_nuevo[50][50];
 for(int t=0;t<pasos_tiempo;t++){
  double sum=0;
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
  for( int i=1;i<lon-1;i++){
   calcita_nuevo[0][i]=calcita[1][i];
   
   calcita_nuevo[lon-1][i]=calcita[lon-2][i];

   calcita_nuevo[i][0]=calcita[i][1];

   calcita_nuevo[i][lon-1]=calcita[i][lon-2]; 
  }  

  calcita_nuevo[0][0]=calcita[0][0]+(dt*nu/(h*h))*((2*calcita[0+1][0]-2*calcita[0][0])+(2*calcita[0][0+1]-2*calcita[0][0]));

  calcita_nuevo[0][lon-1]=calcita[0][lon-1]+(dt*nu/(h*h))*((2*calcita[0+1][lon-1]-2*calcita[0][lon-1])+(-2*calcita[0][lon-1]+2*calcita[0][lon-2]));

  calcita_nuevo[lon-1][0]=calcita[lon-1][0]+(dt*nu/(h*h))*((-2*calcita[lon-1][0]+2*calcita[lon-2][0])+(2*calcita[lon-1][0+1]-2*calcita[lon-1][0]));

  calcita_nuevo[lon-1][lon-1]=calcita[lon-1][lon-1]+(dt*nu/(h*h))*((-2*calcita[lon-1][lon-1]+2*calcita[lon-2][lon-1])+(-2*calcita[lon-1][lon-1]+2*calcita[lon-1][lon-2]));

  for( int x=0;x<lon;x++){
   for ( int y=0;y<lon;y++){
    calcita[x][y]=calcita_nuevo[x][y];
    sum+=calcita_nuevo[x][y];
   }
  }
 promedio[t]=sum/(50*50);
 }
}



void cond_ini_3(int lon, double t_tot, double dt){
 double h=0.01;
 double nu=k/(rho*Cp);
 
 if(dt==0){dt=1;} 
 int pasos_tiempo=t_tot/dt;
 promedio=new double[pasos_tiempo];
 double calcita_nuevo[50][50];
 for(int t=0;t<pasos_tiempo;t++){
  double sum=0;
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
  for( int i=1;i<lon-1;i++){
   calcita_nuevo[0][i]=calcita[0][i]+(dt*nu/(h*h))*((calcita[0+1][i]-2*calcita[0][i]+calcita[lon-1][i])+(calcita[0][i+1]-2*calcita[0][i]+calcita[0][i-1]));
   
   calcita_nuevo[lon-1][i]=calcita[lon-1][i]+(dt*nu/(h*h))*((calcita[0][i]-2*calcita[lon-1][i]+calcita[lon-2][i])+(calcita[lon-1][i+1]-2*calcita[lon-1][i]+calcita[lon-1][i-1])); 

   calcita_nuevo[i][0]=calcita[i][0]+(dt*nu/(h*h))*((calcita[i-1][0]-2*calcita[i][0]+calcita[i+1][0])+(calcita[i][0+1]-2*calcita[i][0]+calcita[i][lon-1])); 

   calcita_nuevo[i][lon-1]=calcita[i][lon-1]+(dt*nu/(h*h))*((calcita[i-1][lon-1]-2*calcita[i][lon-1]+calcita[i+1][lon-1])+(calcita[i][0]-2*calcita[i][lon-1]+calcita[i][lon-2])); 
  }  

  calcita_nuevo[0][0]=calcita[0][0]+(dt*nu/(h*h))*((calcita[0+1][0]-2*calcita[0][0]+calcita[lon-1][0])+(calcita[0][0+1]-2*calcita[0][0]+calcita[0][lon-1]));

  calcita_nuevo[0][lon-1]=calcita[0][lon-1]+(dt*nu/(h*h))*((calcita[0+1][lon-1]-2*calcita[0][lon-1]+calcita[lon-1][lon-1])+(calcita[0][0]-2*calcita[0][lon-1]+calcita[0][lon-2]));

  calcita_nuevo[lon-1][0]=calcita[lon-1][0]+(dt*nu/(h*h))*((calcita[0][0]-2*calcita[lon-1][0]+calcita[lon-2][0])+(calcita[lon-1][0+1]-2*calcita[lon-1][0]+calcita[lon-1][lon-1]));

  calcita_nuevo[lon-1][lon-1]=calcita[lon-1][lon-1]+(dt*nu/(h*h))*((calcita[0][lon-1]-2*calcita[lon-1][lon-1]+calcita[lon-2][lon-1])+(calcita[lon-1][0]-2*calcita[lon-1][lon-1]+calcita[lon-1][lon-2]));

  for( int x=0;x<lon;x++){
   for ( int y=0;y<lon;y++){
    calcita[x][y]=calcita_nuevo[x][y];
    sum+=calcita_nuevo[x][y];
   }
  }
 promedio[t]=sum/(50*50);
 }
}







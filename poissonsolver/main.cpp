#include <iostream>
#include<array>
#include<fstream>
#include<math.h>

using namespace std;

int main (int argc, char** argv){

// Laengen des Gitters festlegen
  const int a = 100;
  const int b = 100;
  const int c = 100;
// Gitter definieren 
  array<array<array<double,a>,b>,c> rhogitter;
  array<array<array<double,a>,b>,c> phialt;
  array<array<array<double,a>,b>,c> phineu;
  array<array<array<double,a>,b>,c> phi2alt;
  array<array<array<double,a>,b>,c> phi2neu;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//rho=0////////////////////


  // Randbedingung
for (int i = 0; i < a; ++i){
  for (int j = 0; j < b; ++j){
    phialt[i][j][0] = 1000;  
  }
}
    

// Zeitschritte

for (int t = 0; t < 500; ++t){

//Raumelicher Loop, gehe Gitterpunkte durch
  for (int i = 1; i < a-1; ++i){
    for (int j = 1; j < b-1; ++j){
     for (int k = 1; k < c-1; ++k){
      phineu[i][j][k] = (1.0/6.0)*(phialt[i+1][j][k] + phialt[i-1][j][k] + phialt[i][j+1][k] + phialt[i][j-1][k] + phialt[i][j][k+1] + phialt[i][j][k-1]);
      phialt[i][j][k] = phineu[i][j][k];
      
      }
    }
  }
}




// Ausgabe der Daten
ofstream output_potential0("Potential_rho0.txt");
  for (int i = 0; i < a; ++i){
      for (int k = 0; k < b; ++k){
      output_potential0 << i <<" "<< k <<" "<<phineu[i][50][k]<< endl;
      }
  }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////Punktladung mit fester Ladungsdichte//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Ladungsdichte definieren
for(int i = 0; i < a; i++){
 for(int j = 0; j < b; j++){
   for(int k= 0; k < c; k++){
      rhogitter[50][50][50] = 50.0;
    }
  }
}


 // Zeitschritte durch Abbruchbedingung
for (int t = 0; t < 500; ++t){
//Raumelicher Loop, gehe Gitterpunkte durch
  for (int i = 1; i < a-1; ++i){
    for (int j = 1; j < b-1; ++j){
     for (int k = 1; k < c-1; ++k){
      phi2neu[i][j][k] =(1.0/6.0)*(phi2alt[i+1][j][k] + phi2alt[i-1][j][k] + phi2alt[i][j+1][k] + phi2alt[i][j-1][k] + phi2alt[i][j][k+1] + phi2alt[i][j][k-1] - 4.0*M_PI*rhogitter[i][j][k]);
      phi2alt[i][j][k] = phi2neu[i][j][k];
      }
    }
  }
}




// Ausgabe der Daten
ofstream output_potential1("Potential_punktladung.txt");
  for (int i = 0; i < a; ++i){
      for (int k = 0; k < b; ++k){
      output_potential1 << i <<" "<< k <<" "<<phi2neu[i][50][k]<< endl;
      }
  }
ofstream output_potential2("Potential_punktladung_querschnitt.txt");
  for (int i = 0; i < a; ++i){
      output_potential2 << i <<" "<<phi2neu[i][50][50]<< endl;
      }

}

#include <iostream>
#include<array>
#include<fstream>
#include<math.h>

using namespace std;

int main (int argc, char** argv){

// Laengen des Gitters festlegen
  const int a = 10;
  const int b = 10;
  const int c = 10;
// Gitter definieren 
  array<array<array<int,a>,b>,c> rhogitter;
  array<array<array<int,a>,b>,c> phialt;
  array<array<array<int,a>,b>,c> phineu;

  // Anfangsbedingungen
for (int i = 0; i < a; ++i){
  for (int j = 0; j < b; ++j){
    phialt[i][j][0] = 1000;  
  }
}


  // Zeitschritte durch Abbruchbedingung
double delta = 10;
while (delta > 0.01){
  
 //Raumelicher Loop, gehe Gitterpunkte durch 
  for (int i = 1; i < a-1; ++i){
    for (int j = 1; j < b-1; ++j){
      for (int k = 1; k < c-1; ++k){
	phineu[i][j][k] = (1.0/6.0)*(phialt[i+1][j][k] + phialt[i-1][j][k] + phialt[i][j+1][k] + phialt[i][j-1][k] + phialt[i][j][k+1] + phialt[i][j][k-1]); 
      delta = sqrt((phialt[i][j][k] - phineu[i][j][k])*(phialt[i][j][k] - phineu[i][j][k]));
      phialt[i][j][k] = phineu[i][j][k];
      }
    }
  }
}        

// Ausgabe der Daten
std::ofstream output_potential0("Potential_rho_0.txt");
  for (int i = 0; i < a; ++i){
      for (int k = 0; k < b; ++k){
      output_potential0 << i <<" "<< k <<" "<<phineu[i][5][k]<< std::endl;
      }
  }

} 


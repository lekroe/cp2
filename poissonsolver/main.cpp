#include <iostream>
#include<array>
#include<fstream>
#include<math.h>

using namespace std;

int main (int argc, char** argv){

// Laengen des Gitters festlegen
  const int a = 20;
  const int b = 20;
  const int c = 20;
// Gitter definieren 
  array<array<array<int,a>,b>,c> rhogitter;
  array<array<array<int,a>,b>,c> phialt;
  array<array<array<int,a>,b>,c> phineu;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//rho=0////////////////////


  // Randbedingung
for (int i = 0; i < a; ++i){
  for (int j = 0; j < b; ++j){
    phialt[i][j][0] = 1000;  
  }
}


  // Zeitschritte durch Abbruchbedingung
//double delta = 1;
//while (delta > 0.1){
  
// //Raumelicher Loop, gehe Gitterpunkte durch 
//  for (int i = 1; i < a-1; ++i){
//    for (int j = 1; j < b-1; ++j){
//      for (int k = 1; k < c-1; ++k){
//	phineu[i][j][k] = (1.0/6.0)*(phialt[i+1][j][k] + phialt[i-1][j][k] + phialt[i][j+1][k] + phialt[i][j-1][k] + phialt[i][j][k+1] + phialt[i][j][k-1]); 
//      delta = sqrt((phineu[i][j][k] - phialt[i][j][k])*(phineu[i][j][k] - phialt[i][j][k]));
//      phialt[i][j][k] = phineu[i][j][k];
//      }
//    }
//  }
//}        

  // Zeitschritte durch Abbruchbedingung
for (int t = 0; t < 1000000000; ++t){
//Raumelicher Loop, gehe Gitterpunkte durch
  for (int i = 1; i < a-1; ++i){
    for (int j = 1; j < b-1; ++j){
     for (int k = 1; k < c-1; ++k){
      phineu[i][j][k] = (1.0/6.0)*(phialt[i+1][j][k] + phialt[i-1][j][k] + phialt[i][j+1][k] + phialt[i][j-1][k] + phialt[i][j][k+1] + phialt[i][j][k-1]);
      phialt[i][j][k] = phineu[i][j][k];
      t = t+1;
      }
    }
  }
}




// Ausgabe der Daten
ofstream output_potential0("Potential_rho_test.txt");
  for (int i = 0; i < a; ++i){
      for (int k = 0; k < b; ++k){
      output_potential0 << i <<" "<< k <<" "<<phineu[i][10][k]<< endl;
      }
  }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////Punktladung mit fester Ladungsdichte//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

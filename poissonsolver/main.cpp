#include <iostream>
#include<array>
#include<fstream>
#include<math.h>

using namespace std;

int main (){

// Laengen des Gitters festlegen
  const int a = 50;
  const int b = 50;
  const int c = 50;
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
double delta = 100;
while (delta > 0.01){
  
 //Raumelicher Loop, gehe Gitterpunkte durch 
  for (int i = 1; i < a-1; ++i){
    for (int j = 1; j < b-1; ++j){
      for (int k = 1; k < c-1; ++k){
	phineu[i][j][k] = (1/6.)*(phialt[i+1][j][k] + phialt[i-1][j][k] + phialt[i][j+1][k] + phialt[i][j-1][k] + phialt[i][j][k+1] + phialt[i][j][k-1]); 
      delta = sqrt((phineu[i][j][k] - phialt[i][j][k])*(phineu[i][j][k] - phialt[i][j][k]));
      }
    }
  }
}        

for (int i = 0; i < 50; ++i){
     for (int j = 0; j < 50; ++j){
        for (int k = 0; k < 50; ++k){
	  cout<< i <<" "<< j <<" "<< k <<" "<<phialt[i][j][k]<< endl;
	}
      }
    }




} 




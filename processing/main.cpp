#include <iostream>
#include <fstream>
#include <vector>

//Daten einlesen
int main(int argc, char** argv){
    std::ifstream in("input.txt");

// Vektor definieren    
    std::vector<double> hector;
    std::vector<double> hectorresult;

//Variablen definieren 
  double var1;
  double var2 = 9./5.;
  double var3 = 32;
  double var4;

//Input durchgehen und an Vektor anhängen  
    for( int i = 0 ; i < 4; i++ ) {
    in >> var1;
    hector.push_back(var1);
    }

// Input aus Vektor nehmen und Umrechnungsformel anwenden und in neuen Vektor reinschreiben    
    for ( double e : hector){ 
      var4 = (e*var2)+var3;
      hectorresult.push_back(var4);
    }
for (int i=0; i < hectorresult.size();i++){
  std::cout << " " << hectorresult[i];
  std::cout << "F";
}

    return 0;
}

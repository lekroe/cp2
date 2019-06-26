#include <iostream>
#include <fstream>
#include <vector>
#include <random>
using namespace std;

int main(int argc, char** argv){

    std::mt19937 gen;
    gen.seed(5);
    std::uniform_real_distribution<double> dis(0,1);
    std::vector<int> hector(10000000,0);
    std::vector<double> timehector(10,0);

    double a;
    double x1;
    double x1ave;
    double x2;
    double x2ave;
    

// Loop für Zeitschritte    
    for (int i = 0; i < timehector.size(); ++i){

// Loop für die Sprünge
      for (int n = 0; n < hector.size(); ++n){
      a = dis(gen);
      if (a >= 0.5){
      hector[n]+=1;
      }
      else {
      hector[n]+=-1;}
      }
// Loop Ende 

// 1. Moment <x> ausrechnen 
      for (int n = 0; n < hector.size(); ++n){
      x1+= hector[n];
      }

      x1ave = x1*1/hector.size();

// 2. Moment <x^{2}> ausrechnen 
      for (int n = 0; n < hector.size(); ++n){
      x2+= hector[n]*hector[n]; 
      }

      x2ave= x2*1/hector.size();

// Momente über Zeit in Vektor reinschreiben
    timehector[i] = x2ave;
    }

    for(int t = 0; t < timehector.size(); t++){    
    cout << timehector[t] << endl;
    }
}

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
//#include <ofstream>
using namespace std;

int main(int argc, char** argv){
    std::mt19937 gen;
    gen.seed(5);
    std::uniform_real_distribution<double> dis(0,1);
    std::vector<int> hector(10000000,0);
    std::vector<double> timehector(6,0);
std::vector<double> zahlort(2* timehector.size() +1,0);
vector<double> hector_x1ave(11,0);
    double a;
    double x1;
    double x1ave;
    double x2;
    double x2ave;
    

// Loop für Zeitschritte    
    for (int i = 1; i < timehector.size(); ++i){

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
//x1=0;
// 1. Moment <x> ausrechnen 
      for (int n = 0; n < hector.size(); ++n){
      x1+= hector[n];
      }

      x1ave = x1*1/hector.size();
      hector_x1ave[i] = x1ave;
//      cout << x1ave << endl;

// 2. Moment <x^{2}> ausrechnen
x2=0;
      for (int n = 0; n < hector.size(); ++n){
      x2+= (hector[n]-x1ave)*(hector[n]-x1ave); 
      }

      x2ave= x2*1/hector.size();
      //cout << x2ave << endl;
// Momente über Zeit in Vektor reinschreiben
    timehector[i] = x2ave;
  

    }
    for (int k=0; k < 2*timehector.size()+1; k++){

	    for(int n=0; n < hector.size(); n++){
		if (hector[n]==k-timehector.size()) {

			zahlort[k]=zahlort[k]+1;
		}
	}
    }  
    
ofstream out("werte_6zs.txt");
for (int k = 0; k < 2*timehector.size()+1; k++){
  out << k-6 << " " << zahlort[k]/10000000 << endl;
  }

}

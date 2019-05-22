#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char** argv){
    std::ifstream in("input.txt");
    std::vector<double> hector(4,0);
    for( double& e : hector ){
     in>>e;  
}   	

  double var1;
  std::string var4;
  double var2 = 9./5.;
  double var3 = 32; 

    for( int i = 0 ; i < hector.size(); i++ ) {
      

    if (var4 == "C"){
    std::cout << var1 << "Celsius in Fahrenheit" << (var1*var2)+var3<< std::endl;
    }
  

}

    return 0;
}

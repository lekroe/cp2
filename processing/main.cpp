#include <iostream>
#include <fstream>

int main(int argc, char** argv){
    std::ifstream in("input.txt");

  double var1;
  std::string var4;
  double var2 = 9./5.;
  double var3 = 32; 


    for( int i = 0 ; i < 4; i++){
    in >>var1;
    in >>var4;

    if (var4 == "C"){
    std::cout << var1 << "Celsius in Fahrenheit" << (var1*var2)+var3<< std::endl;
    }
    else if (var4 == "F"){
    std::cout << var1 << "Fahrenheit in Celsius" <<(var1-var3)/var2 << std::endl;
    }

}

    return 0;
}
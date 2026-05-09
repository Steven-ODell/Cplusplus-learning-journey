
#include <iostream>

int main(){
  float a = 10.0 / 3;
  a = a * 10000000000;
  double b = 7.7E4; //7.7E4 = 7.7 * 10^4
  long double c;

  std::cout << std::fixed << a << std::endl;

  return 0;
}



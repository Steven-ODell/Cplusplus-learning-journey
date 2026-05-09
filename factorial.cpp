#include <climits>
#include <iostream>

int factorial(int);

//Main
int main(){
  int n = 1;
  factorial(n);
  return 0;
}

//Function
int factorial(int n){
   int result = 1;
  //This allows me to check if it breaks before even multpilying
  while (result < INT_MAX / n){
    result = result * n;
    n++;
  }
  std::cout << "Overflow limit hit" << std::endl;
  std::cout << "The factorial of " << n - 1 << " is " << result << "\nthis is the highers number before the overflow" << std::endl;
  return 0;
}

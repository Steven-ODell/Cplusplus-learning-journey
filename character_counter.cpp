#include <iostream>
#include <string>
#include <cctype>
//Take a string from the user with getline.
//Loop through it character by character using .length() as your bound.
//Count and print how many letters, digits, and spaces it contains.
//Use the isalpha, isdigit, isspace functions.

//Main
int main(){
  std::string input_string;
  std::getline(std::cin, input_string);
  int letter_counter = 0;
  int digit_counter = 0;
  int space_counter = 0;
  for (int i = 0; i < input_string.length(); i++){
      if (isalpha(input_string[i])){
        letter_counter++;
      }
      if (isdigit(input_string[i])){
        digit_counter++;
      }
      if (isspace(input_string[i])){
        space_counter++;
      }
    }
  std::cout << "Number of spaces: " << space_counter << std::endl;
  std::cout << "Number of Digits: " << digit_counter << std::endl;
  std::cout << "Number of Letters: " << letter_counter << std::endl;
  return 0;
}


#include <iostream>
#include <string>
#include <cctype>

struct Token {
  std::string type;
  std::string value;
  int index;
};

//Main
int main(){
  std::string input_string = "hello world 42 foo";

  Token holding_array[100];

  int counter = 0;

  for (int i = 0; i < input_string.length();){
    std::string word;
    int start = i;

    if (isalpha(input_string[i])){
      while (isalpha(input_string[i])){
        word += input_string[i];
        i++;
      }
      holding_array[counter].type = "LETTER";
      holding_array[counter].index = start; 
      holding_array[counter].value = word;
      counter++;
      word = "";
      start = i;
    }

    else if (isdigit(input_string[i])){
      while (isdigit(input_string[i])){
        word += input_string[i];
        i++;
      }
      holding_array[counter].type = "NUMBER";
      holding_array[counter].index = start; 
      holding_array[counter].value = word;
      counter++;
      word = "";
      start = i;
      }

    else if (isspace(input_string[i])){
      while (isspace(input_string[i])){
        word += " " ;
        i++;
      }
      holding_array[counter].type = "SPACE";
      holding_array[counter].index = start; 
      holding_array[counter].value = word;
      counter++;
      word = "";
      start = i;
      }
    
    else {
      holding_array[counter].type = "UNKNOWN";
      //next line converts single char to a string
      holding_array[counter].value = std::string(1, input_string[i]);
      holding_array[counter].index = i;
      counter++;
      i++;
    }
  }

  for (int j = counter - 1; j >= 0; j--) {
    if (holding_array[j].type == "LETTER"){
    std::cout << holding_array[j].value << " | Spot: " << holding_array[j].index << std::endl;
    }
  }
  
  int letter_counter = 0;
  int digit_counter = 0;
  int space_counter = 0;
  for (int k = counter - 1; k >= 0; k--){
      if (holding_array[k].type == "LETTER"){
        letter_counter++;
      }
      else if (holding_array[k].type == "NUMBER"){
        digit_counter++;
      }
      else if (holding_array[k].type == "SPACE"){
        space_counter++;
      }
    }
  std::cout << "---\n" << "Number of spaces: " << space_counter << std::endl;
  std::cout << "Number of Digits: " << digit_counter << std::endl;
  std::cout << "Number of Letters: " << letter_counter << std::endl;
  return 0;
}


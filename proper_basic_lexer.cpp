#include <iostream>
#include <string>
#include <cctype>

//Create a Token struct with type and value as std::string fields. 
//Then take your character counter from the last challenge and
//instead of just counting, create a Token every time you identify
//a sequence — one token for a word, one for a number, one for a space.
//Store them in a raw array of Token (max size 100 is fine 
//to hardcode for now). 
//Print each token's type and value at the end.

struct Token {
  std::string type;
  std::string value;
  int index;
};

//Main
int main(){
  std::string input_string;
  std::getline(std::cin, input_string);
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
  for (int j = 0; j < counter; j++) {
    std::cout << holding_array[j].type << ": " << holding_array[j].value << " | Spot: " << holding_array[j].index << std::endl;
  }
  return 0;
}



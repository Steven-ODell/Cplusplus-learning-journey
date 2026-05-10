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


std::string check_token_alpha(std::string input_string, int* i);
std::string check_token_digit(std::string input_string, int* i);
std::string check_token_space(std::string input_string, int* i);

struct Token {
  std::string type;
  std::string value;
  int index;
};

//Main
int main(){
  Token t;
  std::string input_string;
  std::getline(std::cin, input_string);
  int letter_counter = 0;
  int digit_counter = 0;
  int space_counter = 0;
  for (int i = 0; i < input_string.length(); i++){
      if (isalpha(input_string[i])){
        int start = i;
        t.value = check_token_alpha(input_string, &i);
        t.index = start;
        t.type = "LETTER";
        std::cout << t.type << ": " << t.value << " | Spot: " << t.index << std::endl;
      }
      if (isdigit(input_string[i])){
        int start = i;
        t.value = check_token_digit(input_string, &i);
        t.index = start;
        t.type = "NUMBER";
        std::cout << t.type << ": " << t.value << " | Spot: " << t.index << std::endl;
      }
      if (isspace(input_string[i])){
        int start = i;
        t.value = check_token_space(input_string, &i);
        t.index = start;
        t.type = "SPACE";
        std::cout << t.type << ": " << t.value << " | Spot: " << t.index << std::endl;
      }
    }
  return 0;
}

std::string check_token_alpha(std::string input_string, int* i){
  std::string return_value;
  return_value += input_string[*i];
  if (isalpha(input_string[(*i)+1])){
    (*i)++;
    return_value += check_token_alpha(input_string, i);
  }
  return return_value;
}

std::string check_token_digit(std::string input_string, int* i){
  std::string return_value;
  return_value += input_string[*i];
  if (isdigit(input_string[(*i)+1])){
    (*i)++;
    return_value += check_token_digit(input_string, i);
  }
  return return_value;
}

std::string check_token_space(std::string input_string, int* i){
  std::string return_value;
  return_value += " ";
  if (isspace(input_string[(*i)+1])){
    (*i)++;
    return_value += check_token_space(input_string, i);
  }
  return return_value;
}

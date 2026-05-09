#include <iostream>
#include <string>

int sum_array(int lets_add[], int size);
void get_inputs(int input_length, int lets_add[]);
std::string create_array_string(int lets_add[], int input_length);

//Main
int main(){
  std::string s;
  int input_length;
  std::cout << "How many numbers are we adding? " << std::endl;
  std::cin >> input_length;
  int* lets_add = new int[input_length];
  get_inputs(input_length, lets_add);
  std::cout << input_length << " is the array length" << std::endl;
  int sum_result = sum_array(lets_add, input_length);
  s += create_array_string(lets_add, input_length);
  std::cout << sum_result << " is the sum of the array: {" << s << "}" <<  std::endl;
  delete[] lets_add;
  lets_add = nullptr;
  return 0;
}

void get_inputs(int input_length, int lets_add[]){
  int tracker = 0; 
  int chosen_value;
  while (input_length > tracker){
    std::cout << "number " << tracker + 1 << ":" << std::endl;
    std::cin >> chosen_value;
    lets_add[tracker] = chosen_value;
    tracker++;
  }
}

std::string create_array_string(int lets_add[], int input_length){
  std::string result = "";
  int tracker = 0; 
  while (input_length > tracker){
    if (input_length - 1 == tracker){
      result += std::to_string(lets_add[tracker]);
      break;
    }
    result += std::to_string(lets_add[tracker]) + ", ";
    tracker++;
  }
  return result;
}

int sum_array(int lets_add[], int size){
  int current_total = 0;
  while (size > 0){
    current_total += lets_add[size - 1];
    size--;
  }
  return current_total;
}

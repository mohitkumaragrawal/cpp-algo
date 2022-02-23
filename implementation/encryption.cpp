#include <iostream>
#include <string>
#include <cmath>

std::string encrypt(std::string input) {
  int space_count = 0;
  int i = 0;
  int j = 0;

  while (j < input.size()) {
    if (input[j] == ' ') {
      ++j;
      space_count++;
      continue;

    }
    input[i] = input[j];
    j++;
    i++;
  }

  // popping stuff may cause extra "time" trouble;
  // for (int k = 0; k < space_count; ++k) {
  //   input.pop_back();
  // }

  int L = input.size() - space_count;

  auto rootL = std::sqrt((double) L);
  int rows = (int) std::floor(rootL);
  int cols = (int) std::ceil(rootL);

  // I don't know what exactly to do in such case;
  //if (rows * cols < L) return "";

  while (rows * cols < L) {
    if (rows < cols) {
      rows++;
    } else {
      cols++;
    }
  }


  std::string output;
  for (i = 0; i < cols; ++i) {

    for (j = i; j < L; j += cols) {
      output.push_back(input[j]);
    }
    output.push_back(' ');
  }

  if (output[output.size() - 1] == ' ') {
    output.pop_back();
  }

  return output;

}

int main() {
  std::string input;
  
  std::getline(std::cin, input);
  std::cout << encrypt(input) << std::endl;
}
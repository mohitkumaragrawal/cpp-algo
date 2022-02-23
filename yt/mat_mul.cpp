#include <iostream>
#include <vector>

#include "matrix.hpp"

int main() {
  // redirect input from console to input.txt
  freopen("mat_mul.txt", "r", stdin);

  auto mat1 = read_matrix();
  auto mat2 = read_matrix();

  auto result = mat1 * mat2;

  std::cout << result << std::endl;
}
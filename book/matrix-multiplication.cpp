#include <iostream>

#include "matrix.hpp"

// C(i,j) = Sum[ A(i,k) x B(k, j), {k, 0, n-1} ]
// both are nxn matrix;
matrix mul(const matrix& a, const matrix& b) {
  matrix c(a.rows(), b.cols());
  auto n = c.rows();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        c(i, j) += a(i, k) * b(k, j);
      }
    }
  }
  return c;
}

int main() {
  freopen("matrix-multiplication.txt", "r", stdin);

  auto A = read_matrix(std::cin);
  auto B = read_matrix(std::cin);

  auto C = mul(A, B);

  std::cout << C << std::endl;
}
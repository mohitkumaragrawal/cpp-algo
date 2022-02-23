#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iterator>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

Matrix make_matrix(const int row, const int col) {
  Matrix mat(row, std::vector<int>(col, 0));
  return std::move(mat);
}

// read matrix from std::cin
Matrix read_matrix(std::istream& in = std::cin) {
  int row = 0, col = 0;
  in >> row >> col;
  auto mat = make_matrix(row, col);

  for (auto i = 0; i < row; ++i) {
    for (auto j = 0; j < col; ++j) {
      in >> mat[i][j];
    }
  }

  return std::move(mat);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
  char comma[3] = {'\0', ' ', '\0'};

  out.put('[');
  for (auto el : vec) {
    out << comma << el;
    comma[0] = ',';
  }
  out.put(']');
  return out;
}

std::ostream& operator<<(std::ostream& out, const Matrix& mat) {
  int m = mat.size();
  int n = mat[0].size();

  for (int i = 0; i < m; ++i) {
    std::copy(mat[i].begin(), mat[i].end(),
              std::ostream_iterator<int>(out, "  "));

    out << std::endl;
  }

  return out;
}

Matrix operator*(const Matrix& mat1, const Matrix& mat2) {
  int m1 = mat1.size();
  int n1 = mat1[0].size();

  int m2 = mat2.size();
  int n2 = mat2[0].size();

  auto result = make_matrix(m1, n2);

  // multiplication is not possible;
  if (n1 != m2) return result;

  for (int i = 0; i < m1; ++i) {
    for (int j = 0; j < n2; ++j) {
      result[i][j] = 0;
      for (int k = 0; k < n1; ++k) {
        result[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }

  return std::move(result);
}

#endif
#pragma once
#include <iostream>

struct matrix {
  int** data;
  
  int& operator()(int r, int c) {
    return data[r][c];
  }

  int operator()(int r, int c) const {
    return data[r][c];
  }

  matrix(int r, int c): m_rows(r), m_cols(c) {
    data = new int*[r];

    for (int j = 0; j < r; ++j) {
      int* col = new int[c];
      for (int i = 0; i < c; ++i) {
        col[i] = 0;
      }

      data[j] = col;
    }
  }

  // copy constructor
  matrix(const matrix& m): m_rows(m.rows()), m_cols(m.cols()) {
    std::cout << "Copy called" << std::endl;

    data = new int*[rows()];

    for (int j = 0; j < rows(); ++j) {
      int* col = new int[cols()];
      for (int i = 0; i < cols(); ++i) {
        col[i] = m(j, i);
      }

      data[j] = col;
    }
  }

  matrix(matrix&& m) : m_rows(m.rows()), m_cols(m.cols()) {
    data = m.data;
    m.data = nullptr;
  }

  // copy-assignment operator
  matrix& operator=(const matrix& m) {
    destroy();
    m_rows = m.rows();
    m_cols = m.cols();

    data = new int*[rows()];

    for (int j = 0; j < rows(); ++j) {
      int* col = new int[cols()];
      for (int i = 0; i < cols(); ++i) {
        col[i] = m(j, i);
      }

      data[j] = col;
    }

    return *this;
  }

  // move-assignment operator;
  matrix& operator=(matrix&& m) {
    // free memory
    destroy();

    // steal the resources;
    m_cols = m.cols();
    m_rows = m.rows();
    data = m.data;

    // avoid deleting the data by m destructor
    m.data = nullptr;

    return *this;  
  }

  ~matrix() {
    destroy();
  }

  void destroy() {
    if (data != nullptr) {
      for (int j = 0; j < rows(); ++j) {
        delete[] data[j];
      }

      delete[] data;
      data = nullptr;
    }
  }

  inline int rows() const {return m_rows;}
  inline int cols() const {return m_cols;}

private:
  int m_rows;
  int m_cols;
};

std::ostream& operator<<(std::ostream& out, const matrix& mat) {
  for (int i = 0; i < mat.rows(); ++i) {
    for (int j = 0; j < mat.cols(); ++j) {
      out << mat(i, j) << " ";
    }
    out << '\n';
  }
  out << std::endl;
  return out;
}

matrix read_matrix(std::istream& in) {
  int r, c;
  in >> r >> c;
  matrix m(r,c);

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      in >> m(i, j);
    }
  }

  return m;
}

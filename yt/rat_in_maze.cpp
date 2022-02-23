#include <cstdio>
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

Matrix rat_in_maze(const Matrix& mat, bool& success, int row_start = 0,
                   int col_start = 0) {
  int m = mat.size();
  int n = mat[0].size();

  if (col_start + 1 == m && row_start + 1 == n) {
    auto temp = make_matrix(1, 1);
    temp[0][0] = 0;
    if (mat[row_start][col_start] == 0) {
      success = false;
    } else {
      success = true;
      temp[0][0] = 1;
    }
    return temp;
  }

  bool right_success = false;
  bool down_success = false;

  auto result = make_matrix(m - row_start, n - col_start);
  result[0][0] = 1;

  if (col_start + 1 < n && mat[row_start][col_start + 1] == 1) {
    bool right_success = false;
    auto right_result =
        rat_in_maze(mat, right_success, row_start, col_start + 1);

    if (right_success) {
      for (int i = 0; i < right_result.size(); ++i) {
        for (int j = 0; j < right_result[0].size(); ++j) {
          result[i][j + 1] = right_result[i][j];
        }
      }
      success = true;
      return result;
    }
  }

  if (row_start + 1 < m && mat[row_start + 1][col_start] == 1) {
    bool bottom_success = false;
    auto bottom_result =
        rat_in_maze(mat, bottom_success, row_start + 1, col_start);

    if (bottom_success) {
      for (int i = 0; i < bottom_result.size(); ++i) {
        for (int j = 0; j < bottom_result[0].size(); ++j) {
          result[i + 1][j] = bottom_result[i][j];
        }
      }
      success = true;
      return result;
    }
  }

  success = false;
  return result;
}

int main() {
  freopen("rat_in_maze.txt", "r", stdin);
  auto mat = read_matrix();

  std::cout << mat << std::endl;

  bool success = false;

  auto result = rat_in_maze(mat, success);

  if (success) {
    // We successfully found a path;

    std::cout << result << std::endl;
  } else {
    std::cout << "There is no way to get to the finish line" << std::endl;
  }
}

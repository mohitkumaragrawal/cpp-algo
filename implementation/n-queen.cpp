#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<int>>;
Matrix make_matrix(const int row, const int col) {
  Matrix mat(row, std::vector<int>(col, 0));
  return std::move(mat);
}

bool solve(Matrix& mat, int n, int row = 0, std::vector<std::pair<int, int>> prev_queens = std::vector<std::pair<int, int>>()) {
  if (row >= n) {
    return true;
  }
  for (int j = 0; j < n; ++j) {
    bool is_free = true;

    for (auto pos: prev_queens) {
      if (pos.second == j) {
        is_free = false;
        break;
      } else if (abs(pos.first - row) == abs(pos.second - j)) { // Diagonal
        is_free = false;
        break;
      }
    }
    if (!is_free)
      continue;
    
    mat[row][j] = 1;
    prev_queens.push_back(std::make_pair(row, j));
    
    if (solve(mat, n, row+1, prev_queens)) { // success
      return true;
    }

    prev_queens.pop_back();
    mat[row][j] = 0;
  }
  return false;
}

int main() {
  int n;

  std::cin >> n;

  auto mat = make_matrix(n, n);
  solve(mat, n);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mat[i][j] == 0) {
        std::cout << ". ";
      } else {
        std::cout << "Q ";
      }
    }
    std::cout << std::endl;
  }
}
#include <iostream>
#include <vector>

using namespace std;

using Mat = vector<vector<int>>;

Mat multiply(const Mat& a, const Mat& b) {
  if (a.empty() || b.empty()) return Mat();
  if (a[0].size() != b.size()) return Mat(); // multiplication not possible;

  Mat result(a.size(), vector<int>(b[0].size(),0));
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < b[0].size(); ++j) {
      for (int k = 0; k < a[0].size(); ++k) {
        result[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return result;
}

Mat identity(int n) {
  Mat result(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    result[i][i] = 1;
  }
  return result;
}

Mat operator*(const Mat& a, const Mat& b) {
  return multiply(a, b);
}

Mat matrix_exponentiation(Mat base, int pow) {
  if (base.empty()) return Mat();
  if (base.size() != base[0].size()) return Mat();

  int n = base.size();
  Mat result = identity(n);

  while (pow > 0) {
    if (pow & 1) {
      pow--;
      result = result * base;
    } else {
      pow /= 2;
      base = base * base;
    }
  }
  return result;
}

void display_matrix(const Mat& m) {
  for (int i = 0; i < m.size(); ++i) {
    for (int j = 0; j < m[i].size(); ++j) {
      cout << m[i][j] << " ";
    } cout << endl;
  }
}

int main() {
  vector<vector<int>> mat {
    {1, 2}, {3, 4}
  };

  auto result = matrix_exponentiation(mat, 5);
  display_matrix(result);
}
#include <iostream>
#include <vector>
using namespace std;
using Mat = vector<vector<int>>;

Mat identity(int n) {
  Mat result(n,vector<int>(n, 0));
  for (int i =0; i<n; ++i) result[i][i]=1;
  return result;
}

Mat mul(const Mat& m1, const Mat& m2) {
  if (m1.empty() || m2.empty()) return Mat();
  if (m1[0].size() != m2.size()) return Mat();

  Mat result(m1.size(), vector<int>(m2[0].size(),0));
  for (int i = 0; i < m1.size(); ++i) {
    for (int j = 0; j < m2[0].size(); ++j) {
      for (int k = 0; k < m1[0].size(); ++k) {
        result[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
  return result;
}

Mat mat_exp(Mat mat, int pow) {
  if (mat.empty()) return Mat();
  if (mat.size() != mat[0].size()) return Mat();
  int n = mat.size();
  Mat result = identity(n);
  while (pow > 0) {
    if (pow & 1) {
      pow--;
      result = mul(result, mat);
    } else {
      pow >>= 1;
      mat = mul(mat, mat);
    }
  }
  return result;
}

Mat magic = {
  {0, 1},
  {1, 1}
};
Mat start = {{1, 1}};
// fib(1) = 1; fib(2) = 1; fib(n) = fib(n-1) + fib(n-2)
int fib(int n) {
  if (n == 1 || n == 2) return 1;
  auto m = mat_exp(magic, n-2);
  auto result = mul(start, m);
  return result[0][1];
}

int main() {
  while (true)
  {
    int n; cin >> n;
    int result = fib(n);
    cout << result << endl;
  }
  
}
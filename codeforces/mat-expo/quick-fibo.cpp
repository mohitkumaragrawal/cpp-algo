#include <iostream>
#include <vector>
#define mod 1000000007
using ull = unsigned long long;
using namespace std;
vector<vector<ull>> matmul(const vector<vector<ull>>& A,
                           const vector<vector<ull>>& B) {
  vector<vector<ull>> result(A.size(), vector<ull>(B[0].size(), 0));
  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < B[0].size(); ++j) {
      for (int k = 0; k < A[0].size(); ++k) {
        result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % mod;
      }
    }
  }
  return result;
}

int main() {
  ull n;
  cin >> n;

  vector<vector<ull>> m = {{0, 1}, {1, 1}};
  vector<vector<ull>> res = {{1, 0}, {0, 1}};

  while (n > 0) {
    if (n % 2 == 0) {
      n /= 2;
      m = matmul(m, m);
    } else {
      n--;
      res = matmul(res, m);
    }
  }
  cout << res[0][1] << endl;
}
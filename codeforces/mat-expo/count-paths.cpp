#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;
using ull = unsigned long long;

// O(n^3)
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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<ull>> v(n, vector<ull>(n, 0));

  while (m--) {
    int n1, n2;
    cin >> n1 >> n2;
    n1--;
    n2--;
    v[n1][n2] = 1;
  }

  vector<vector<ull>> result(n, vector<ull>(n, 0));
  for (int i = 0; i < n; ++i) result[i][i] = 1;

  while (k > 0) {
    if (k % 2 == 0) {
      v = matmul(v, v);
      k /= 2;
    } else {
      result = matmul(result, v);
      k--;
    }
  }

  ull ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans = (ans + result[i][j]) % mod;
    }
  }
  cout << ans << endl;
}
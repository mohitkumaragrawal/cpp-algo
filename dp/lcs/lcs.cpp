#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int mem[1000][1000];

int lcs(const string& x, const string& y, int m, int n) {
  if (mem[m][n] != -1) return mem[m][n];
  if (m == 0 || n == 0) return mem[m][n] = 0;

  if (x[m - 1] == y[m - 1]) {
    return mem[m][n] = 1 + lcs(x, y, m - 1, n - 1);
  } else {
    return mem[m][n] = max(lcs(x, y, m, n - 1), lcs(x, y, m - 1, n));
  }
}

int main() {
  string x, y;
  cin >> x >> y;

  for (int i = 0; i <= 100; ++i) {
    for (int j = 0; j <= 100; ++j) {
      mem[i][j] = -1;
    }
  }

  int val = lcs(x, y, x.size(), y.size());

  for (int i = 0; i <= x.size(); ++i) {
    for (int j = 0; j <= y.size(); ++j) {
      if (mem[i][j] == -1) {
        cout << ". ";
        continue;
      }
      cout << mem[i][j] << " ";
    }
    cout << endl;
  }
}
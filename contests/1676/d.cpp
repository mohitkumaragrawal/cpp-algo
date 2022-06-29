#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

void solve() {
  int m, n;
  cin >> m >> n;

  vector<vector<int>> mat(m, vector<int>(n));

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
    }
  }

  vector<int> p1(n, 0);
  vector<int> p2(m, 0);
  p2[0] = INT_MIN;

  vector<int> q1(m + n - 1, 0);

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      q1[i + j] += mat[i][j];

      if ((j - i) < 0) {
        p2[i - j] += mat[i][j];
      } else {
        p1[j - i] += mat[i][j];
      }
    }
  }

  int ans = INT_MIN;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int s = q1[i + j];

      if (j - i < 0) {
        s += p2[i - j];
      } else {
        s += p1[j - i];
      }
      s -= mat[i][j];
      ans = max(ans, s);
    }
  }

  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;

  while (T--)
    solve();
}

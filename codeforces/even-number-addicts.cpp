#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

int dp[101][101][2][2];

void solve() {
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      dp[0][0][i][j] = (i == 0);
    }
  }

  int n, z = 0, o = 0;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x % 2 == 0) {
      z++;
    } else {
      o++;
    }
  }

  for (int i = 0; i <= z; ++i) {
    for (int j = 0; j <= o; ++j) {
      if (i == 0 && j == 0) continue;
      for (int s = 0; s < 2; ++s) {
        // bob move;
        int m1 = 1;
        if (i > 0) {
          m1 = dp[i - 1][j][s][1];
        }
        if (j > 0) {
          m1 = min(m1, dp[i][j - 1][s][1]);
        }
        dp[i][j][s][0] = m1;

        // alice move;
        int m2 = 0;
        if (i > 0) {
          m2 = dp[i - 1][j][s][0];
        }
        if (j > 0) {
          m2 = max(m2, dp[i][j - 1][1 - s][0]);
        }

        dp[i][j][s][1] = m2;
      }
    }
  }

  int winner = dp[z][o][0][1];
  if (winner == 1) {
    cout << "Alice\n";
  } else if (winner == 0) {
    cout << "Bob\n";
  } else {
    cout << "not defined\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

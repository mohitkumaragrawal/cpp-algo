#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

// (i) -> index in str, (len) -> length of string, len is always even;
int dp[2001][2001];

void solve() {
  string s;
  cin >> s;

  int n = s.size();
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == s[i + 1]) {
      dp[i][2] = 0;
    } else {
      dp[i][2] = 1;
    }
  }

  auto choose = [&](int i, int j, int ni, int len) {
    int res = dp[ni][len];
    if (res == 0) {
      if (s[i] < s[j]) {
        return 1;
      } else if (s[i] > s[j]) {
        return -1;
      } else {
        return 0;
      }
    }
    return res;
  };

  for (int l = 4; l <= n; l += 2) {
    for (int i = 0; (i + l - 1) < n; ++i) {
      int j = (i + l - 1);

      int r1 = choose(i, j, i + 1, l - 2);
      int r2 = choose(i, i + 1, i + 2, l - 2);
      int r3 = choose(j, i, i + 1, l - 2);
      int r4 = choose(j, j - 1, i, l - 2);

      int res = max(min(r1, r2), min(r3, r4));
      dp[i][l] = res;
    }
  }

  switch (dp[0][n]) {
    case 1:
      cout << "Alice" << endl;
      break;
    case -1:
      cout << "Bob" << endl;
      break;
    default:
      cout << "Draw" << endl;
      break;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
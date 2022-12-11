#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

string s[6] = {"abc", "acb", "bac", "bca", "cab", "cba"};
int dp[6][200005];

void solve() {
  ll m, n;
  cin >> n >> m;

  string str;
  cin >> str;

  for (int i = 0; i < 6; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = dp[i][j - 1] + (str[j - 1] == s[i][(j - 1) % 3]);
    }
  }

  while (m--) {
    int l, r;
    cin >> l >> r;

    int max_matching = 0;
    for (int i = 0; i < 6; ++i) {
      max_matching = max(max_matching, dp[i][r] - dp[i][l - 1]);
    }

    cout << (r - l + 1) - max_matching << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

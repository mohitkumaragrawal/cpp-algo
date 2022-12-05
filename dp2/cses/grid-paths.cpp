#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll dp[1005][1005];
const ll MOD = 1e9 + 7;

void solve() {
  ll n;
  cin >> n;

  vector<string> grid(n);
  for (ll i = 0; i < n; ++i) cin >> grid[i];

  if (grid[0][0] == '*') {
    cout << "0\n";
    return;
  }

  dp[0][1] = 1;
  for (ll i = 1; i <= n; ++i) {
    for (ll j = 1; j <= n; ++j) {
      if (grid[i - 1][j - 1] == '*') continue;
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    }
  }
  cout << dp[n][n] << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

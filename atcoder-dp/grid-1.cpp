#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;

void solve() {
  ll h, w;
  cin >> h >> w;

  vector<string> grid(h);
  for (string& s : grid) cin >> s;

  vector<vector<ll>> dp(h, vector<ll>(w, 0));
  dp[0][0] = 1;

  for (ll i = 0; i < h; ++i) {
    for (ll j = 0; j < w; ++j) {
      if (grid[i][j] == '#') {
        dp[i][j] = 0;
        continue;
      }

      if (i > 0) dp[i][j] += dp[i - 1][j];
      if (j > 0) dp[i][j] += dp[i][j - 1];

      if (dp[i][j] > (MOD << 10)) dp[i][j] %= MOD;
    }
  }

  cout << dp[h - 1][w - 1] % MOD << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

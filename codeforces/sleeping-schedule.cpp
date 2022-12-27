#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll n, h, l, r;
ll dp[2005][2005];
ll a[2005];

void solve() {
  cin >> n >> h >> l >> r;
  for (ll i = 1; i <= n; ++i) cin >> a[i];

  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;

  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < h; ++j) {
      if (dp[i][j] == -1) continue;

      ll nxt_time = (j + a[i + 1]) % h;
      if (nxt_time >= l && nxt_time <= r) {
        dp[i + 1][nxt_time] = max(dp[i + 1][nxt_time], 1 + dp[i][j]);
      } else {
        dp[i + 1][nxt_time] = max(dp[i + 1][nxt_time], dp[i][j]);
      }

      nxt_time = (j + a[i + 1] - 1) % h;
      if (nxt_time >= l && nxt_time <= r) {
        dp[i + 1][nxt_time] = max(dp[i + 1][nxt_time], 1 + dp[i][j]);
      } else {
        dp[i + 1][nxt_time] = max(dp[i + 1][nxt_time], dp[i][j]);
      }
    }
  }

  ll ans = 0;
  for (ll i = 0; i < h; ++i) {
    ans = max(ans, dp[n][i]);
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

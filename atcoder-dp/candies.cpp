#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll dp[105][100005], prefix_sum[100005];
const ll MOD = 1e9 + 7;

void solve() {
  ll n, k;
  cin >> n >> k;
  ll a[n];
  for (ll i = 0; i < n; ++i) cin >> a[i];

  for (ll i = 0; i <= n; ++i) dp[i][0] = 1;

  for (ll i = 1; i <= n; ++i) {
    // dp[i][j] = 1 * dp[i-1][j] + 1 * dp[i-1][j-1] + .. + 1 * dp[i-1][j -
    // a[i-1]] dp[i][j] = prefix_sum[j] - prefix_sum[j - a[i-1] - 1];

    prefix_sum[0] = dp[i - 1][0];
    for (ll j = 1; j <= k; ++j)
      prefix_sum[j] = (prefix_sum[j - 1] + dp[i - 1][j]) % MOD;

    for (ll j = 1; j <= k; ++j) {
      dp[i][j] = prefix_sum[j];
      ll t = j - a[i - 1] - 1;
      if (t >= 0) dp[i][j] = (dp[i][j] + MOD - prefix_sum[t]) % MOD;
    }
  }

  ll ans = dp[n][k];
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

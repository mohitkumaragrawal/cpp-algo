#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll n;
ll a[305];

const ll MOD = 998244353;

const ll T = 300 * 300;
const ll SZ = 2 * T + 10;

ll dp[300][SZ];

void solve() {
  cin >> n;
  for (ll i = 1; i <= n; ++i) cin >> a[i];

  dp[0][a[2]] = 1;
  for (ll i = 0; i < n - 2; ++i) {
    for (ll j = 0; j <= 2 * T; ++j) {
      ll v = j;
      if (j > T) v = T - j;

      if (j == 0 || j == T) {
        dp[i + 1][a[i + 3]] += dp[i][j];
      } else {
        ll s1 = a[i + 3] - v;
        ll s2 = a[i + 3] + v;

        if (s1 < 0) s1 = T - s1;
        if (s2 < 0) s2 = T - s2;

        dp[i + 1][s1] += dp[i][j];
        dp[i + 1][s1] %= MOD;

        dp[i + 1][s2] += dp[i][j];
        dp[i + 1][s2] %= MOD;
      }
    }
  }

  ll ans = 0;
  for (ll j = 0; j <= 2 * T; ++j) {
    ans = (ans + dp[n - 2][j]) % MOD;
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

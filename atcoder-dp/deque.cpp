#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll dp[3003][3003];

void solve() {
  ll n;
  cin >> n;

  ll a[n];
  for (ll i = 0; i < n; ++i) cin >> a[i];

  for (ll i = 0; i < n; ++i) dp[i][0] = 0;

  // dp[i][j] = max(a[i] + dp[i+1][j], a[j] + dp[i][j-1])
  for (ll L = 1; L <= n; ++L) {
    for (ll i = 0; i < n; ++i) {
      ll j = i + L - 1;
      if (j >= n) break;

      ll chance = 0;
      if ((n % 2) != (L % 2)) chance = 1;

      if (chance == 0) {
        dp[i][L] = max(a[i] + dp[i + 1][L - 1], a[j] + dp[i][L - 1]);
      } else {
        dp[i][L] = min(-a[i] + dp[i + 1][L - 1], -a[j] + dp[i][L - 1]);
      }
    }
  }

  cout << dp[0][n] << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

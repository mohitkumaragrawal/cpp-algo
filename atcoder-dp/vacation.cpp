#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll n, a[100005], b[100005], c[100005];
ll dp[100005][3], t[100005][3];

void solve() {
  cin >> n;
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < 3; ++j) cin >> t[i][j];
  }

  for (ll j = 0; j < 3; ++j) dp[0][j] = t[0][j];

  for (ll i = 1; i < n; ++i) {
    for (ll j = 0; j < 3; ++j) {
      for (ll k = 0; k < 3; ++k) {
        if (j == k) continue;
        dp[i][j] = max(dp[i][j], dp[i - 1][k] + t[i][j]);
      }
    }
  }

  ll ans = 0;
  for (ll j = 0; j < 3; ++j) ans = max(ans, dp[n - 1][j]);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

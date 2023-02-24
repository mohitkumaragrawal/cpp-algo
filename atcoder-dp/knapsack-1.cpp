#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

// ll n, c;
// ll w[101], v[101];
//
// ll dp[101][100005];
//
// void solve() {
//   cin >> n >> c;
//   for (ll i = 0; i < n; ++i) cin >> w[i] >> v[i];
//
//   for (ll i = 1; i <= n; ++i) {
//     for (ll j = 0; j <= c; ++j) {
//       dp[i][j] = dp[i - 1][j];
//       if (j >= w[i - 1]) {
//         dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
//       }
//     }
//   }
//
//   cout << dp[n][c] << endl;
// }

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll dp[1000001];

void solve() {
  ll n;
  cin >> n;

  for (ll i = 0; i < 1000001; ++i) dp[i] = 1e+17;
  dp[0] = 0;

  for (ll i = 1; i <= n; ++i) {
    ll k = i;
    while (k > 0) {
      ll dig = k % 10;
      k /= 10;

      dp[i] = min(dp[i], 1 + dp[i - dig]);
    }
  }

  cout << dp[n] << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

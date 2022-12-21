#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n), b(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];
  for (ll i = 0; i < n; ++i) cin >> b[i];

  ll total_sum = 0;
  ll ans = 0;
  for (ll x : a) {
    total_sum += x;
    ans += x * x;
  }
  for (ll x : b) {
    total_sum += x;
    ans += x * x;
  }
  ans *= (n - 2);

  vector<vector<bool>> dp(n + 1, vector<bool>(total_sum + 1, false));
  dp[1][a[0]] = dp[1][b[0]] = true;

  for (ll i = 1; i < n; ++i) {
    for (ll j = 1; j < total_sum; ++j) {
      if (dp[i][j]) {
        dp[i + 1][j + a[i]] = true;
        dp[i + 1][j + b[i]] = true;
      }
    }
  }

  ll delta = 1e+17;
  for (ll j = 1; j <= total_sum; ++j) {
    if (!dp[n][j]) continue;
    ll ndelta = (total_sum - j) * (total_sum - j) + j * j;
    delta = min(delta, ndelta);
  }
  ans += delta;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

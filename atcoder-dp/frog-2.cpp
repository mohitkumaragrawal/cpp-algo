#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (ll& i : a) cin >> i;

  vector<ll> dp(n, INT_MAX);

  dp[0] = 0;

  for (ll i = 1; i < n; ++i) {
    for (ll j = 1; j <= k; ++j) {
      ll prev = i - j;
      if (prev < 0) break;

      dp[i] = min(dp[i], abs(a[i] - a[prev]) + dp[prev]);
    }
  }

  cout << dp[n - 1] << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

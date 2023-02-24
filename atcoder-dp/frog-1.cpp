#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  for (ll& i : a) cin >> i;

  vector<ll> dp(n, INT_MAX);

  dp[0] = 0;
  dp[1] = abs(a[1] - a[0]);

  for (ll i = 2; i < n; ++i) {
    dp[i] =
        min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i - 2] - a[i]));
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

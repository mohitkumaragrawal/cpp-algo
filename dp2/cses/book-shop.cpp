#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll dp[100005], ndp[100005], h[1005], s[1005];

void solve() {
  ll n, x;
  cin >> n >> x;
  for (ll i = 0; i < n; ++i) cin >> h[i];
  for (ll i = 0; i < n; ++i) cin >> s[i];

  for (ll i = 0; i < n; ++i) {
    for (ll p = 0; p <= x; ++p) {
      ndp[p] = dp[p];
      if (p - h[i] >= 0) ndp[p] = max(ndp[p], s[i] + dp[p - h[i]]);
    }
    swap(dp, ndp);
  }

  ll ans = *max_element(all(dp));
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

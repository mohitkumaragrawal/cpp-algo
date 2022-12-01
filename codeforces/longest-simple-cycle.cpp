#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll a[100005], b[100005], c[100005];
void solve() {
  ll n;
  cin >> n;

  for (ll i = 0; i < n; ++i) cin >> c[i];
  for (ll i = 0; i < n; ++i) cin >> a[i];
  for (ll i = 0; i < n; ++i) cin >> b[i];

  ll dp[n];
  dp[0] = 0;
  dp[1] = c[1] + abs(b[1] - a[1]) + 1;

  for (ll i = 2; i < n; ++i) {
    if (a[i] == b[i]) {
      dp[i] = c[i] + 1;
    } else {
      auto [m, M] = minmax({a[i], b[i]});
      ll ans1 = c[i] + abs(b[i] - a[i]) + 1;
      ll ans2 = c[i] + (dp[i - 1] - c[i - 1]) + m + (c[i - 1] - M + 1);

      dp[i] = max(ans1, ans2);
    }
  }

  ll ans = dp[1];
  for (ll i = 2; i < n; ++i) ans = max(ans, dp[i]);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

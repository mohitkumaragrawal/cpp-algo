#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll dp[100005][31];
ll a[100005];

void solve() {
  ll n, k;
  cin >> n >> k;

  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (ll x = 0; x <= 30; ++x) {
    dp[n - 1][x] = max((a[n - 1] / (1 << x)) - k, a[n - 1] / (1 << (x + 1)));
  }

  for (ll i = n - 2; i >= 0; --i) {
    for (ll x = 0; x <= 30; ++x) {
      ll val1 = a[i] / (1 << x) + dp[i + 1][x] - k;
      ll val2 = a[i] / (1 << (x + 1)) + dp[i + 1][min(30LL, x + 1)];

      dp[i][x] = max(val1, val2);
    }
  }

  ll ans = dp[0][0];
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

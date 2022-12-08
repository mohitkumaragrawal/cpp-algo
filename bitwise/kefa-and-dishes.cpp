#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll n, m, k;
ll bonus[20][20];
ll dp[(1 << 18)][18];
ll a[18];

void solve() {
  cin >> n >> m >> k;
  for (ll i = 0; i < n; ++i) cin >> a[i];

  for (ll i = 0; i < k; ++i) {
    ll x, y, c;
    cin >> x >> y >> c;
    bonus[x - 1][y - 1] = c;
  }

  for (ll i = 0; i < n; ++i) {
    dp[(1 << i)][i] = a[i];
  }

  for (ll i = 0; i < (1 << 18); ++i) {
    for (ll j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        for (ll k = 0; k < n; ++k) {
          if (!((i >> k) & 1)) {
            // eat k;
            ll mask = i | (1 << k);
            ll val = dp[i][j] + a[k] + bonus[j][k];

            dp[mask][k] = max(dp[mask][k], val);
          }
        }
      }
    }
  }

  ll ans = 0;
  for (ll i = 0; i < (1 << 18); ++i) {
    for (ll j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        if (__builtin_popcount(i) == m) ans = max(ans, dp[i][j]);
      }
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

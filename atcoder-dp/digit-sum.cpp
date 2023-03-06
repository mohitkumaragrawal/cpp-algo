#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

string K;
ll D, n;

ll dp[10004][104][2];
const ll MOD = 1e9 + 7;

void solve() {
  cin >> K;
  cin >> D;
  n = K.size();

  dp[0][0][0] = dp[0][0][1] = 1;

  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < D; ++j) {
      // for non-strict;
      for (ll d = 0; d <= 9; ++d) {
        ll& val = dp[i + 1][(j + d) % D][0];
        val += dp[i][j][0];
        val %= MOD;
      }

      // for strict;
      ll max_dig = K[n - i - 1] - '0';
      for (ll d = 0; d <= max_dig; ++d) {
        ll& val = dp[i + 1][(j + d) % D][1];

        if (d == max_dig) {
          val += dp[i][j][1];
        } else {
          val += dp[i][j][0];
        }

        val %= MOD;
      }
    }
  }

  // minus -1 because not including 0;
  ll ans = (MOD + dp[n][0][1] - 1) % MOD;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

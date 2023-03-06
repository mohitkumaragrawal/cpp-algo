#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll dp[3001][3001], pre[3001];
const ll MOD = 1e9 + 7;

void solve() {
  ll n;
  string s;
  cin >> n >> s;

  assert(s.size() == n - 1);

  dp[1][1] = 1;

  for (ll i = 2; i <= n; ++i) {
    for (ll j = 1; j <= i; ++j) {
      pre[j] = (pre[j - 1] + dp[i - 1][j]) % MOD;
    }

    for (ll j = 1; j <= i; ++j) {
      char comp = s[i - 2];
      if (comp == '<') {
        dp[i][j] = pre[j - 1];
      } else {
        dp[i][j] = (MOD + pre[i] - pre[j - 1]) % MOD;
      }
    }
  }

  ll ans = 0;
  for (ll j = 1; j <= n; ++j) {
    ans += dp[n][j];
    ans %= MOD;
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

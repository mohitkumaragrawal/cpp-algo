#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const ll inf = 1e18;

const ll K = 1E12;

void solve() {
  string s;
  cin >> s;

  ll n = s.size();

  vector<array<ll, 2>> dp(n + 1, array<ll, 2>{inf, inf});
  dp[0][0] = 0;

  for (ll i = 0; i < n; ++i) {
    ll val = s[i] - '0';
    for (ll j = 0; j < 2; ++j) {
      if (val >= j) {
        dp[i + 1][val] = min(dp[i + 1][val], dp[i][j]);
      }
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + K + 1);

      if (i + 1 < n && (s[i + 1] - '0') >= j && s[i + 1] <= s[i]) {
        dp[i + 2][s[i] - '0'] = min(dp[i + 2][s[i] - '0'], dp[i][j] + K);
      }
    }
  }

  ll ans = min(dp[n][0], dp[n][1]);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

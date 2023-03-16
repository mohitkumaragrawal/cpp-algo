#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n, mod;
  cin >> n >> mod;

  vector<ll> dp(n + 1);
  dp[n] = 1;

  vector<ll> suf(n + 1);
  suf[n] = 1;

  for (ll i = n - 1; i >= 1; --i) {
    dp[i] = suf[i + 1];

    for (ll j = i + i; j <= n; j += i) {
      ll f = j / i;
      ll k = j + f;
      dp[i] += suf[j];
      if (k <= n) dp[i] -= suf[k];
    }

    while (dp[i] < 0) dp[i] += mod;
    dp[i] %= mod;

    suf[i] = (suf[i + 1] + dp[i]) % mod;
  }

  ll ans = dp[1];
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

void solve() {
  ll n, p;
  cin >> n >> p;

  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];

  sort(all(a));
  set<ll> useful;

  for (ll i = 0; i < n; ++i) {
    ll x = a[i];
    bool is_useful = true;

    while (x > 0) {
      if (useful.count(x)) {
        is_useful = false;
        break;
      }

      if (x & 1) {
        x >>= 1;  // x is of the form 2y + 1; x -> y;
      } else if (x & 3) {
        break;
      } else {
        x >>= 2;  // x is of the form 4 y; x -> y;
      }
    }

    if (is_useful) useful.insert(a[i]);
  }

  vector<ll> cnt(30, 0), dp(p);

  for (ll x : useful) {
    cnt[__lg(x)]++;
  }

  ll ans = 0;

  for (ll i = 0; i < p; ++i) {
    if (i < 30) dp[i] = cnt[i];
    if (i - 1 >= 0) dp[i] = (dp[i] + dp[i - 1]) % MOD;
    if (i - 2 >= 0) dp[i] = (dp[i] + dp[i - 2]) % MOD;

    ans = (ans + dp[i]) % MOD;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}

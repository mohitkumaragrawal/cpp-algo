#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;
using lld = long double;

lld choose[2005][2005];

void solve() {
  ll n, t;
  lld p;
  cin >> n >> p >> t;

  lld ans = 0;

  for (ll i = 0; i <= min(t, n - 1); ++i) {
    ans += choose[t][i] * i * powl(p, i) * powl(1 - p, t - i);
  }

  if (t >= n) {
    for (ll k = n; k <= t; ++k) {
      ans += choose[k - 1][n - 1] * n * powl(p, n) * powl(1 - p, k - n);
    }
  }

  cout << fixed << setprecision(10) << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  choose[0][0] = 1;
  for (ll i = 1; i <= 2000; ++i) {
    choose[i][0] = 1;
    choose[i][i] = 1;

    for (ll j = 1; j <= i - 1; ++j) {
      choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
    }
  }

  solve();
}

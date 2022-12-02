#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n, k;
  cin >> n >> k;

  double p[n];
  for (ll i = 0; i < n; ++i) {
    ll l, r;
    cin >> l >> r;

    ll num = (r / k) - (l - 1) / k;
    ll den = (r - l + 1);

    p[i] = (1.0 * num) / (1.0 * den);
  }

  double ans = 0;
  for (ll i = 0; i < n; ++i) {
    ll j = (i + 1) % n;

    double side_p = p[i] * (1 - p[j]) + (1 - p[i]) * p[j] + p[i] * p[j];
    ans += 2000.0 * side_p;
  }

  cout << fixed << setprecision(8) << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

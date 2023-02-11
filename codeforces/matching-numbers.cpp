#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n;
  cin >> n;

  if (n % 2 == 0) {
    cout << "NO\n";
    return;
  }

  ll x = (3 * (n + 1)) / 2;

  cout << "YES\n";

  for (ll alpha = 1; alpha <= (x + 1) / 3; ++alpha) {
    cout << 2 * alpha - 1 << " " << x - alpha << '\n';
  }

  for (ll r = 1;; ++r) {
    ll first = 2 * r;
    ll second = 2 * n - r + 1;

    if (second <= x - 1) break;
    cout << first << " " << second << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

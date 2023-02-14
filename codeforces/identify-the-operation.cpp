/**

1 2 3 4 5
  2 1   3

1 . 2 . 1 = 2;

1 4 7 3 6 2 5
  3   1   2 4

2 . 1 . 2 . 1 = 4;
*/

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const ll MOD = 998244353;

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<ll> a(n), b(m), idx(n + 1, -1);

  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x;

    idx[x] = i;
  }

  for (ll i = 0; i < m; ++i) {
    cin >> b[i];

    ll j = idx[b[i]];
    a[j] = i + 1;
  }

  ll ans = 1;

  for (ll i = 0; i < n; ++i) {
    if (a[i] == 0) continue;

    ll w = 0;
    if (i + 1 < n && a[i + 1] < a[i]) w++;
    if (i - 1 >= 0 && a[i - 1] < a[i]) w++;

    ans = (ans * w) % MOD;
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

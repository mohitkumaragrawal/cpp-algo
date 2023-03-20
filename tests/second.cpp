#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n, x, y;
  cin >> n >> x >> y;

  string t;
  cin >> t;

  ll ans = 0;
  ll c_cnt = 0;
  for (ll i = 0; i < n; ++i) {
    if (t[i] == 'A' && x > 0) {
      x--;
      ans++;
    } else if (t[i] == 'B' && y > 0) {
      y--;
      ans++;
    } else if (t[i] == 'C') {
      c_cnt++;
    }
  }

  ll seats = x + y;
  ans += min(c_cnt, seats);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

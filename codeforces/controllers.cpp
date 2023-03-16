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

  string s;
  cin >> s;

  ll p = count(all(s), '+');
  ll m = s.size() - p;

  ll q;
  cin >> q;

  while (q--) {
    ll a, b;
    cin >> a >> b;

    if (a == b) {
      if (p == m) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }

      continue;
    }

    ll k = (m - p) * b;
    if (k % (a - b) != 0) {
      cout << "NO\n";
      continue;
    }

    k /= (a - b);

    if (-m <= k && k <= p) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

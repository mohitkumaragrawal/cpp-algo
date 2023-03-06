#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n, k;
  cin >> n >> k;
  string a, b;
  cin >> a >> b;

  string c = a;
  string d = b;
  sort(all(c));
  sort(all(d));
  if (c != d) {
    cout << "NO\n";
    return;
  }

  bool ok = true;

  for (ll i = 0; i < n; ++i) {
    // if it is not swapable
    if ((i - k) < 0 && (i + k) >= n) {
      if (a[i] != b[i]) {
        ok = false;
        break;
      }
    }
  }

  if (ok) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

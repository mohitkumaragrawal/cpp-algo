#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n, j;
  cin >> n >> j;
  j--;

  string s;
  cin >> s;

  ll monster = -1;

  bool ok = true;

  for (ll i = j; i < n - 1;) {
    if (s[i + 1] == '#') {
      s[i + 1] = '.';
      monster++;

      if (monster >= i) {
        ok = false;
      }
    } else {
      monster++;
      i++;
      if (monster >= i) {
        ok = false;
      }
    }
  }

  if (ok) {
    cout << "JAY" << endl;
  } else {
    cout << "JEFF" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

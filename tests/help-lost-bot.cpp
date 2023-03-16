#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  if (x1 == x2) {
    if (y2 > y1)
      cout << "up" << endl;
    else
      cout << "down" << endl;
  } else if (y1 == y2) {
    if (x2 > x1)
      cout << "right" << endl;
    else
      cout << "left" << endl;
  } else {
    cout << "sad" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

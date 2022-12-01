#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n, k, s;
  cin >> n >> k >> s;

  if ((n - 1) * k < s) {
    cout << "NO" << endl;
    return;
  }
  if (k > s) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES\n";
  if (s % k == 0) {
    ll d = s / k;
    ll h = 1;
    for (ll i = 0; i < k; ++i) {
      if (h == 1) {
        h += d;
        cout << h << " ";
      } else {
        h -= d;
        cout << h << " ";
      }
    }
    cout << endl;
    return;
  }

  ll x = s / k;
  ll y = x + 1;
  ll x_cnt = k * (x + 1) - s;
  ll y_cnt = k - x_cnt;

  ll h = 1;
  for (ll i = 0; i < y_cnt; ++i) {
    if (h == 1) {
      h += y;
      cout << h << " ";
    } else {
      h -= y;
      cout << h << " ";
    }
  }

  ll base_h = (h == 1 + y) ? (h - x) : 1;

  for (ll i = 0; i < x_cnt; ++i) {
    if (h == base_h) {
      h += x;
      cout << h << " ";
    } else {
      h -= x;
      cout << h << " ";
    }
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

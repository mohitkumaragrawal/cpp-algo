#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll N;
  cin >> N;

  vector<bool> vis(N + 1);

  ll left = 1, right = N;
  while (left <= right) {
    ll X = (right - left + 1);
    if (X == 1) {
      cout << "! " << left << endl;
      break;
    } else if (X == 2) {
      cout << "? " << left << " " << left << endl;

      ll y;
      cin >> y;

      if (y == left) {
        cout << "! " << y << endl;
      } else {
        cout << "! " << right << endl;
      }

      break;
    }

    ll len;
    if (X % 2 == 0) {
      len = (X / 2) + 1;
    } else {
      len = (X / 2);
      if ((len % 2) == 0) len++;
    }

    for (ll i = left; i < left + len; ++i) vis[i] = false;
    cout << "? " << left << " " << left + len - 1 << endl;

    for (ll i = 0; i < len; ++i) {
      ll z;
      cin >> z;

      vis[z] = true;
    }

    ll good_count = 0;
    for (ll i = left; i < left + len; ++i) {
      if (vis[i]) good_count++;
    }

    if (good_count % 2 == 0) {
      left = left + len;
    } else {
      right = left + len - 1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

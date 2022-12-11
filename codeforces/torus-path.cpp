#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n;
  cin >> n;
  ll sum = 0;
  ll m = 1e+18;

  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < n; ++j) {
      ll x;
      cin >> x;
      sum += x;

      if (i + j == n - 1) m = min(m, x);
    }
  }

  cout << sum - m << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

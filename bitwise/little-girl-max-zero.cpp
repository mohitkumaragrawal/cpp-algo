#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll l, r;
  cin >> l >> r;

  ll k = -1;

  for (ll i = 0; i < 63; ++i) {
    ll mask = 1LL << i;

    if (((r & mask) != 0) && ((l & mask) == 0)) k = i;
  }

  ll ans = (1LL << (k + 1)) - 1;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

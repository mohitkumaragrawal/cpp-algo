#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll calc(ll x) {
  ll ans = 0;
  ll p = 1;
  while (p <= x) {
    ans += (x / p);
    p *= 10;
  }

  return ans;
}

void solve() {
  ll l, r;
  cin >> l >> r;

  cout << calc(r) - calc(l) << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

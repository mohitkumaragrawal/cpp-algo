#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  for (ll& i : a) cin >> i;

  vector<ll> pre_ones(n);
  pre_ones[0] = a[0];
  for (ll i = 1; i < n; ++i) {
    pre_ones[i] = pre_ones[i - 1] + a[i];
  }

  ll initial_inv = 0;
  for (ll i = 0; i < n; ++i) {
    if (a[i] == 0) continue;
    ll ones = (pre_ones[n - 1] - pre_ones[i]);
    ll zeros = (n - i - 1) - ones;

    initial_inv += zeros;
  }

  ll ans = initial_inv;

  for (ll i = 0; i < n; ++i) {
    if (a[i] == 0) {
      ll curr_inv = pre_ones[i];
      ll ones = (pre_ones[n - 1] - pre_ones[i]);
      ll new_inv = (n - i - 1) - ones;

      ans = max(ans, initial_inv + new_inv - curr_inv);
    } else {
      ll ones = (pre_ones[n - 1] - pre_ones[i]);
      ll curr_inv = (n - i - 1) - ones;
      ll new_inv = pre_ones[i] - 1;

      ans = max(ans, initial_inv + new_inv - curr_inv);
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

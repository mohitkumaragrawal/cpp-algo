#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n, c, d;
  cin >> n >> c >> d;

  vector<ll> arr(n);
  for (ll& i : arr) cin >> i;

  sort(arr.begin(), arr.end());

  ll M = *max_element(all(arr));
  if (M >= c) {
    cout << "Infinity" << endl;
    return;
  }

  if (d * M < c) {
    cout << "Impossible" << endl;
    return;
  }

  ll low = 0, high = d + 1;
  ll ans = 1;

  while (low <= high) {
    ll k = (low + high) / 2;

    ll m = d / (k + 1);
    ll l = d - m * (k + 1);

    ll seg_sum = 0;
    for (ll i = 1; i <= k + 1; ++i) {
      if (n - i < 0) break;
      seg_sum += arr[n - i];
    }

    ll left_sum = 0;
    for (ll i = 1; i <= l; ++i) {
      if (n - i < 0) break;
      left_sum += arr[n - i];
    }

    ll total_sum = seg_sum * m + left_sum;

    if (total_sum >= c) {
      ans = k;
      low = k + 1;
    } else {
      high = k - 1;
    }
  }

  if (ans == d + 1) {
    cout << "Infinity" << endl;
  } else {
    cout << ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

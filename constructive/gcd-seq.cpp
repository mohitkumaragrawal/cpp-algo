#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n;
  cin >> n;

  ll arr[n];
  for (ll i = 0; i < n; ++i) cin >> arr[i];

  ll g = arr[0];
  for (ll i = 1; i < n; ++i) g = __gcd(g, arr[i]);

  ll m = *min_element(arr, arr + n);

  if (m != g) {
    cout << "-1\n";
    return;
  }

  cout << 2 * n << endl;
  for (ll i = 0; i < n; ++i) {
    cout << m << " " << arr[i] << " ";
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

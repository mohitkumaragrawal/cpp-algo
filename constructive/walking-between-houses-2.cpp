#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n, k, s;
  cin >> n >> k >> s;

  if (s < k || s > k * (n - 1)) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";

  ll arr[k];
  for (ll i = 0; i < k; ++i) arr[i] = 1;
  s -= k;
  ll i = 0;
  while (s) {
    ll delta = min(n - 2, s);
    arr[i] += delta;
    s -= delta;
    i++;
  }
  ll h = 1;
  for (i = 0; i < k; ++i) {
    if (h + arr[i] > n) {
      h -= arr[i];
    } else {
      h += arr[i];
    }
    cout << h << " ";
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

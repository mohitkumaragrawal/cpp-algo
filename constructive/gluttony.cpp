#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n;
  cin >> n;

  pair<ll, ll> prr[25];
  ll arr[25];
  for (ll i = 0; i < n; ++i) {
    cin >> arr[i];
    prr[i].first = arr[i];
    prr[i].second = i;
  }
  sort(prr, prr + n);
  sort(arr, arr + n);
  for (ll i = 0; i < n; ++i) {
    prr[i].first = arr[(i + 1) % n];
  }

  ll ans[25];
  for (ll i = 0; i < n; ++i) {
    ans[prr[i].second] = prr[i].first;
  }
  for (ll i = 0; i < n; ++i) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

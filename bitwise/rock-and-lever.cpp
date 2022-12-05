#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n;
  cin >> n;

  vector<ll> arr(n);
  for (ll i = 0; i < n; ++i) cin >> arr[i];

  map<ll, ll> mp;
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    ll x = __builtin_clzll(arr[i]);
    ans += mp[x];
    mp[x]++;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

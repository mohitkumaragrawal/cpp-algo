#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll arr[200005], pre[200005];

void solve() {
  ll n;
  cin >> n;

  for (ll i = 0; i < n; ++i) cin >> arr[i];
  pre[0] = arr[0];
  for (ll i = 1; i < n; ++i) pre[i] = pre[i - 1] + arr[i];

  ll ans = 0;
  map<ll, ll> mp;
  ll mx_freq = 0;

  for (ll i = n - 1; i >= 0; --i) {
    mp[pre[i]]++;
    mx_freq = max(mx_freq, mp[pre[i]]);

    if (arr[i] == 0) {
      ans += mx_freq;
      mx_freq = 0;
      mp.clear();
    }
  }
  ans += mp[0];
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

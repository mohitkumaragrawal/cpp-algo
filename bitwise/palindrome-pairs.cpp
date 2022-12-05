#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll masks[100005];

ll compute_bitmask(const string& str) {
  ll res = 0;
  for (char ch : str) {
    ll pos = ch - 'a';
    res ^= (1 << pos);
  }
  return res;
}

void solve() {
  ll n;
  cin >> n;

  for (ll i = 0; i < n; ++i) {
    string s;
    cin >> s;

    masks[i] = compute_bitmask(s);
  }

  map<ll, ll> mp;
  ll ans = 0;

  for (ll i = 0; i < n; ++i) {
    ans += mp[masks[i]];
    for (ll j = 0; j < 26; ++j) {
      ans += mp[masks[i] ^ (1 << j)];
    }

    mp[masks[i]]++;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

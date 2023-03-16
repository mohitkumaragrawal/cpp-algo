#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n;
  cin >> n;
  vector<ll> v(n);

  for (ll i = 0; i < n; ++i) cin >> v[i];

  ll cnt = 0;

  map<ll, ll> mp;

  for (ll i = 0; i < n; ++i) {
    mp[v[i]]++;
    if (abs(v[i]) > 1) ++cnt;
  }

  if (cnt > 1) {
    cout << "no\n";
    return;
  }

  vector<ll> v2;
  set<ll> s;
  for (auto [k, v] : mp) {
    for (ll i = 0; i < min(v, 2LL); ++i) {
      v2.push_back(k);
      s.insert(k);
    }
  }

  bool ok = true;
  for (ll i = 0; i < v2.size(); ++i) {
    for (ll j = i + 1; j < v2.size(); ++j) {
      ll el = v2[i] * v2[j];
      if (!s.count(el)) {
        ok = false;
      }
    }
  }

  if (!ok) {
    cout << "no\n";
  } else {
    cout << "yes\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

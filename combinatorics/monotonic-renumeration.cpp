#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

const ll MOD = 998244353;
ll binexp(ll a, ll b, ll p = MOD) {
  if (b < 0) return 0;
  ll res = 1;
  while (b > 0) {
    if (b & 1) b--, res = (res * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return res;
}

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];

  ll cnt = 0;
  map<ll, ll> last;
  for (ll i = 0; i < n; ++i) last[a[i]] = i;

  ll group_end = 0;
  for (ll i = 0; i < n; ++i) {
    group_end = max(group_end, last[a[i]]);

    if (group_end == i) {
      ++cnt;
      ++group_end;
    }
  }

  ll ans = binexp(2, cnt - 1);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

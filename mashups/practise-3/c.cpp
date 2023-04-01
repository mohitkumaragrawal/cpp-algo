#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  for (auto x : v) out << x << " ";
  return out;
}

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(all(a));
  a.erase(unique(all(a)), a.end());

  vector<ll> b(a.size() - 1);
  for (ll i = 0; i < b.size(); ++i) {
    b[i] = a[i + 1] - a[i];
  }

  sort(all(b));

  vector<ll> pre_b(b.size());
  partial_sum(all(b), pre_b.begin());

  ll q;
  cin >> q;

  while (q--) {
    ll l, r;
    cin >> l >> r;
    ll x = r - l + 1;

    ll id = lower_bound(all(b), x) - b.begin();
    ll res = ((id > 0) ? pre_b[id - 1] : 0LL) + (a.size() - id) * x;
    cout << res << " ";
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

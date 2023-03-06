#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#ifdef _DEBUG
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve() {
  ll n;
  cin >> n;

  ll a[n], b[n];

  for (ll i = 0; i < n; ++i) cin >> a[i];
  for (ll i = 0; i < n; ++i) cin >> b[i];

  ll a_idx[n + 1], b_idx[n + 1];
  for (ll i = 0; i < n; ++i) {
    a_idx[a[i]] = i;
    b_idx[b[i]] = i;
  }

  auto F = [](ll size) { return size * (size + 1) / 2; };

  ll l = a_idx[1], r = b_idx[1];
  if (l > r) swap(l, r);

  ll ans = 1 + F(l) + F(n - r - 1) + F(r - l - 1);

  for (ll i = 2; i <= n; ++i) {
    ll L = a_idx[i], R = b_idx[i];
    if (L > R) swap(L, R);
    L = min(L, l);
    R = max(R, r);

    if (!((a_idx[i] >= l && a_idx[i] <= r) ||
          (b_idx[i] >= l && b_idx[i] <= r))) {
      //
      vector<ll> v = {a_idx[i], b_idx[i], l, r};
      sort(all(v));
      v.erase(unique(all(v)), v.end());

      auto l_idx = find(all(v), l) - v.begin();
      auto r_idx = find(all(v), r) - v.begin();

      ll l_nxt = (l_idx > 0) ? v[l_idx - 1] : -1;
      ll r_nxt = (r_idx < v.size() - 1) ? v[r_idx + 1] : n;

      ll ways = (r_nxt - r) * (l - l_nxt);

      ans += ways;
    }

    l = L;
    r = R;
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

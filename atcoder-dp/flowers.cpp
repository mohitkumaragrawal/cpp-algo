#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll tree[800005], n;
ll dp[200005];

ll query(ll id, ll tl, ll tr, ll ql, ll qr) {
  if (tl > qr || ql > tr) return 0;
  if (ql <= tl && tr <= qr) return tree[id];

  ll mid = (tl + tr) / 2;
  ll mx1 = query(2 * id, tl, mid, ql, qr);
  ll mx2 = query(2 * id + 1, mid + 1, tr, ql, qr);

  return max(mx1, mx2);
}

void update(ll id, ll tl, ll tr, ll p, ll v) {
  if (p < tl || p > tr) return;

  if (tl == tr) {
    tree[id] = v;
    return;
  }

  ll mid = (tl + tr) / 2;
  update(2 * id, tl, mid, p, v);
  update(2 * id + 1, mid + 1, tr, p, v);

  tree[id] = max(tree[2 * id], tree[2 * id + 1]);
}

void solve() {
  cin >> n;

  ll h[n], a[n];
  for (ll i = 0; i < n; ++i) cin >> h[i];
  for (ll i = 0; i < n; ++i) cin >> a[i];

  for (ll i = 0; i < n; ++i) {
    dp[i] = a[i] + query(1, 1, n, 1, h[i] - 1);
    update(1, 1, n, h[i], dp[i]);
  }

  ll ans = query(1, 1, n, 1, n);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

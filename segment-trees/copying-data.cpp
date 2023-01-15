#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll n, m;
ll a[100005], b[100005];
ll lazy[4 * 100005];

const ll INVALID = -1e15;

void update(ll x, ll ql, ll qr, ll id, ll tl, ll tr) {
  if (ql > tr || qr < tl) return;

  if (tl >= ql && tr <= qr) {
    lazy[id] = x + (tl - ql);
    return;
  }

  ll mid = (tl + tr) / 2;

  // partial overlap;
  if (lazy[id] != 0) {
    ll i = lazy[id];
    lazy[2 * id] = i;
    lazy[2 * id + 1] = i + (mid + 1 - tl);

    lazy[id] = 0;
  }

  update(x, ql, qr, 2 * id, tl, mid);
  update(x, ql, qr, 2 * id + 1, mid + 1, tr);
}

ll query(ll x, ll id, ll tl, ll tr) {
  if (tl > x || tr < x) {
    return INVALID;
  }

  if (tl == tr) {
    ll i = lazy[id];
    if (i == 0) return b[tl];
    return a[i];
  }

  ll mid = (tl + tr) / 2;

  if (lazy[id] != 0) {
    ll i = lazy[id];
    lazy[2 * id] = i;
    lazy[2 * id + 1] = i + (mid + 1 - tl);

    lazy[id] = 0;
  }

  if (x > mid) {
    return query(x, 2 * id + 1, mid + 1, tr);
  } else {
    return query(x, 2 * id, tl, mid);
  }
}

void solve() {
  cin >> n >> m;
  for (ll i = 1; i <= n; ++i) cin >> a[i];
  for (ll i = 1; i <= n; ++i) cin >> b[i];

  while (m--) {
    ll t;
    cin >> t;
    if (t == 2) {
      ll id;
      cin >> id;

      cout << query(id, 1, 1, n) << '\n';
    } else {
      ll x, y, k;
      cin >> x >> y >> k;

      update(x, y, y + k - 1, 1, 1, n);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}

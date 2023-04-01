#include <bits/stdc++.h>
#define all(x) begin(x), end(x)

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll tree[4000006];

void update(ll id, ll tl, ll tr, ll p, ll x) {
  if (p > tr || p < tl) return;

  if (tl == tr) {
    tree[id] += x;
    return;
  }

  ll mid = (tl + tr) / 2;
  update(2 * id, tl, mid, p, x);
  update(2 * id + 1, mid + 1, tr, p, x);

  tree[id] = tree[2 * id] + tree[2 * id + 1];
}

ll query(ll id, ll tl, ll tr, ll ql, ll qr) {
  if (ql > tr || tl > qr) return 0;
  if (ql <= tl && tr <= qr) return tree[id];
  ll mid = (tl + tr) / 2;

  ll s1 = query(2 * id, tl, mid, ql, qr);
  ll s2 = query(2 * id + 1, mid + 1, tr, ql, qr);
  return s1 + s2;
}

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];

  {
    vector<ll> b = a;
    sort(b.begin(), b.end());

    map<ll, ll> mp;

    for (ll i = 0; i < n; ++i) mp[b[i]] = i;
    for (ll i = 0; i < n; ++i) a[i] = mp[a[i]];
  }

  vector<ll> gr(n);
  update(1, 0, n - 1, a[0], 1);

  for (ll i = 1; i < n - 1; ++i) {
    gr[i] = query(1, 0, n - 1, a[i] + 1, n - 1);
    update(1, 0, n - 1, a[i], 1);
  }

  memset(tree, 0, sizeof(tree));
  update(1, 0, n - 1, a[n - 1], 1);

  for (ll i = n - 2; i > 0; --i) {
    gr[i] *= query(1, 0, n - 1, 0, a[i] - 1);
    update(1, 0, n - 1, a[i], 1);
  }

  ll ans = 0;
  for (ll i = 0; i < n; ++i) ans += gr[i];
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  solve();
}

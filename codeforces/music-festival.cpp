#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

vector<ll> tree;
vector<ll> lazy;

ll get_val(ll id) { return lazy[id] ? 0 : tree[id]; }

void push(ll id, ll tl, ll tr) {
  if (!lazy[id]) return;

  lazy[id] = false;
  tree[id] = 0;

  if (tl != tr) {
    lazy[2 * id] = true;
    lazy[2 * id + 1] = true;
  }
}

ll query(ll id, ll tl, ll tr, ll ql, ll qr) {
  if (tl > qr || ql > tr) return 0;
  if (ql <= tl && tr <= qr) {
    return get_val(id);
  }

  push(id, tl, tr);
  ll mid = (tl + tr) / 2;

  ll q1 = query(2 * id, tl, mid, ql, qr);
  ll q2 = query(2 * id + 1, mid + 1, tr, ql, qr);
  return max(q1, q2);
}

void update(ll id, ll tl, ll tr, ll p, ll x) {
  if (p < tl || p > tr) return;

  push(id, tl, tr);

  if (tl == tr) {
    tree[id] = x;
    return;
  }

  ll mid = (tl + tr) / 2;
  update(2 * id, tl, mid, p, x);
  update(2 * id + 1, mid + 1, tr, p, x);

  tree[id] = max(get_val(2 * id), get_val(2 * id + 1));
}

const ll MX = 200000;

void solve() {
  ll n;
  cin >> n;

  lazy[1] = true;

  vector<vector<ll>> a(n);
  for (ll i = 0; i < n; ++i) {
    ll k;
    cin >> k;

    vector<ll> b(k);
    for (ll j = 0; j < k; ++j) {
      cin >> b[j];
    }
    ll mx = 0;
    for (ll j = 0; j < k; ++j) {
      if (b[j] > mx) {
        mx = b[j];
        a[i].push_back(b[j]);
      }
    }
  }

  sort(all(a), [](const vector<ll>& a, const vector<ll>& b) {
    return a.back() < b.back();
  });

  for (ll i = 0; i < n; ++i) {
    auto& v = a[i];

    ll val = 0;
    for (ll j = 0; j < v.size(); ++j) {
      ll impression = (v.size() - j);
      impression += query(1, 0, MX, 0, v[j] - 1);

      val = max(val, impression);
    }

    ll mx_el = v[v.size() - 1];

    ll prev_val = query(1, 0, MX, mx_el, mx_el);
    ll new_val = max(prev_val, val);

    update(1, 0, MX, mx_el, new_val);
  }

  ll ans = tree[1];
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  tree.assign(4 * 200005, 0);
  lazy.assign(4 * 200005, 0);

  ll T;
  cin >> T;
  while (T--) solve();
}

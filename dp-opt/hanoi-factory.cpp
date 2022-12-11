#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

template <typename num_t>
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;

  void init(int s, long long* arr) {
    n = s;
    tree = vector<num_t>(4 * s, 0);
    lazy = vector<num_t>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = arr[l];

    int mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }

  void update(int l, int r, num_t v) {
    if (l > r) return;
    update(0, 0, n - 1, l, r, v);
  }

  num_t update(int i, int tl, int tr, int ql, int qr, num_t v) {
    eval_lazy(i, tl, tr);

    if (tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      lazy[i] = lazy[i].val + v.val;
      eval_lazy(i, tl, tr);
      return tree[i];
    }

    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = a.op(b);
  }

  num_t query(int l, int r) {
    if (l > r) return num_t::null_v;
    return query(0, 0, n - 1, l, r);
  }

  num_t query(int i, int tl, int tr, int ql, int qr) {
    eval_lazy(i, tl, tr);

    if (ql <= tl && tr <= qr) return tree[i];
    if (tr < ql || qr < tl) return num_t::null_v;

    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }

  void eval_lazy(int i, int l, int r) {
    tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
    if (l != r) {
      lazy[i * 2 + 1] = lazy[i].val + lazy[i * 2 + 1].val;
      lazy[i * 2 + 2] = lazy[i].val + lazy[i * 2 + 2].val;
    }

    lazy[i] = num_t();
  }
};
struct max_t {
  long long val;
  static const long long null_v = -9223372036854775807LL;

  max_t() : val(0) {}
  max_t(long long v) : val(v) {}
  max_t op(max_t& other) { return max_t(max(val, other.val)); }
  max_t lazy_op(max_t& v, int size) { return max_t(val + v.val); }
};

struct ring {
  ll a, b, h;
};
bool operator>(const ring& x, const ring& y) {
  return (x.b > y.b) || ((x.b == y.b) && x.a > y.a);
}

ll n, dp[100005], P[200005];
ring r[100005];

segtree<max_t> st;

void solve() {
  cin >> n;

  // read the input
  for (ll i = 0; i < n; ++i) {
    cin >> r[i].a >> r[i].b >> r[i].h;
  }

  {  // Compress the values of a[i] and b[i] for each ring from [0 - 2n]
    map<ll, ll> comp;
    for (ll i = 0; i < n; ++i) {
      comp[r[i].a] = comp[r[i].b] = 0;
    }
    ll cnt = 0;
    for (auto& [f, s] : comp) {
      s = cnt++;
    }
    for (ll i = 0; i < n; ++i) {
      r[i].a = comp[r[i].a];
      r[i].b = comp[r[i].b];
    }
  }

  // Sort the rings lexographically {b[i], a[i]} priority; because first we need
  // to put the rings in the decreasing of the outer radius and also when the
  // outer radius is the same we need to make the topmost ring of that outer
  // radius to have the minimum inner radius, i.e, place the thickest ring at
  // the top when the outer radius is the same; so the following rings are as
  // easy as possible to place on top of that ring
  sort(r, r + n, greater<ring>());

  dp[0] = r[0].h;

  st.init(2 * n, P);
  st.update(r[0].a, r[0].a, dp[0]);

  for (ll i = 1; i < n; ++i) {
    auto x = st.query(0, r[i].b - 1).val;
    dp[i] = r[i].h + x;

    ll val = st.query(r[i].a, r[i].a).val;
    if (dp[i] > val) st.update(r[i].a, r[i].a, dp[i] - val);
  }
  ll ans = *max_element(dp, dp + n);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}

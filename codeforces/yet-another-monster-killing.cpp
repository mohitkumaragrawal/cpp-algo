#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

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

struct max_t {
  long long val;
  static const long long null_v = -9223372036854775807LL;

  max_t() : val(0) {}
  max_t(long long v) : val(v) {}
  max_t op(max_t& other) { return max_t(max(val, other.val)); }
  max_t lazy_op(max_t& v, int size) { return max_t(val + v.val); }
};

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

ll n, m, a[200005], p[200005], e[200005];

segtree<max_t> st_monster, st_endurance;

// check if it is possible to kill from i to (i + k - 1) monsters in one day;
bool check(ll i, ll k) {
  ll j = i + k - 1;

  ll max_monster = st_monster.query(i, j).val;
  ll x = lower_bound(p, p + m, max_monster) - p;
  ll max_endurance = st_endurance.query(x, m - 1).val;

  return max_endurance >= k;
}

// find the max. no. of monsters that can be killed
ll max_monsters_to_kill(ll i) {
  ll low = 1, high = n - i;
  ll ans = 0;

  while (low <= high) {
    ll mid = (high + low) / 2;

    if (check(i, mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return ans;
}

void solve() {
  cin >> n;
  for (ll i = 0; i < n; ++i) cin >> a[i];  // O(n)

  st_monster.init(n, a);  // O(n)
  cin >> m;

  {
    vector<pair<ll, ll>> heros(m);
    for (ll i = 0; i < m; ++i) {  // O(m)
      cin >> heros[i].first >> heros[i].second;
    }

    sort(all(heros));  // O (m lg m)
    for (ll i = 0; i < m; ++i) {
      p[i] = heros[i].first;
      e[i] = heros[i].second;
    }

    st_endurance.init(m, e);  // O (m)
  }

  ll strongest_monster = st_monster.query(0, n - 1).val;
  ll strongest_hero = p[m - 1];

  if (strongest_monster > strongest_hero) {
    cout << "-1\n";
    return;
  }

  ll cnt_killed = 0;
  ll ans = 0;

  while (cnt_killed < n) {
    ll kill = max_monsters_to_kill(cnt_killed);
    cnt_killed += kill;

    assert(kill != 0);

    ans++;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

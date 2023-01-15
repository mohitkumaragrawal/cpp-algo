#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = int;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll n, m;
ll a[100005];

ll mx_tree[100005 * 4], mn_tree[100005 * 4], lazy[100005 * 4];

void build_tree(ll i, ll tl, ll tr) {
  if (tl == tr) {
    mx_tree[i] = a[tr];
    mn_tree[i] = a[tr];

    return;
  }

  ll mid = (tl + tr) / 2;
  build_tree(2 * i, tl, mid);
  build_tree(2 * i + 1, mid + 1, tr);

  ll mx1 = mx_tree[2 * i], mx2 = mx_tree[2 * i + 1];
  ll mn1 = mn_tree[2 * i], mn2 = mn_tree[2 * i + 1];

  mx_tree[i] = max(mx1, mx2);
  mn_tree[i] = min(mn1, mn2);
}

void init_tree() {
  fill(mn_tree, mn_tree + 4 * 100005, 1e15);
  fill(mx_tree, mx_tree + 4 * 100005, -1e15);
  build_tree(1, 0, n - 1);
}

ll query_min() { return mn_tree[1] + lazy[1]; }
ll query_max() { return mx_tree[1] + lazy[1]; }

void update_parents(ll i) {
  if (i == 1) return;
  ll itr = i / 2;

  while (itr != 0) {
    ll k = itr << 1;
    mn_tree[itr] = min(mn_tree[k] + lazy[k], mn_tree[k + 1] + lazy[k + 1]);
    mx_tree[itr] = max(mx_tree[k] + lazy[k], mx_tree[k + 1] + lazy[k + 1]);
    itr /= 2;
  }
}

void update_seg(ll i, ll tl, ll tr, ll ql, ll qr, ll x) {
  if (ql > tr || qr < tl) {
    return;
  }
  if (tl >= ql && tr <= qr) {
    lazy[i] += x;
    update_parents(i);
    return;
  }
  ll mid = (tl + tr) / 2;
  update_seg(2 * i, tl, mid, ql, qr, x);
  update_seg(2 * i + 1, mid + 1, tr, ql, qr, x);
}

void solve() {
  cin >> n >> m;
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
  }
  init_tree();

  vector<vector<ll>> seg_st, seg_lst;
  seg_st.resize(n + 1);
  seg_lst.resize(n + 1);

  vector<pair<ll, ll>> vp(m);

  for (ll i = 0; i < m; ++i) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;

    vp[i].first = x;
    vp[i].second = y;

    seg_st[x].push_back(y);
    seg_lst[y].push_back(x);

    if (x != 0) {
      update_seg(1, 0, n - 1, x, y, -1);
    }
  }

  ll ans = query_max() - query_min();
  ll ans_idx = 0;

  for (int i = 1; i < n; ++i) {
    for (auto y : seg_st[i]) {
      update_seg(1, 0, n - 1, i, y, 1);
    }

    for (auto x : seg_lst[i - 1]) {
      update_seg(1, 0, n - 1, x, i - 1, -1);
    }

    ll new_ans = query_max() - query_min();
    if (new_ans > ans) {
      ans = new_ans;
      ans_idx = i;
    }
  }

  vector<ll> taken;
  for (ll i = 0; i < m; ++i) {
    auto [st, en] = vp[i];
    if (!(ans_idx >= st && ans_idx <= en)) taken.push_back(i + 1);
  }

  cout << ans << endl;

  cout << taken.size() << '\n';
  for (auto idx : taken) cout << idx << " ";
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  solve();
}

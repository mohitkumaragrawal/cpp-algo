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

mt19937 mt(time(nullptr));
uniform_int_distribution<ll> uid;

struct treap {
  vector<treap*> child;

  treap(ll val) : data(val) {
    priority = uid(mt);
    subtree_size = 1;

    child.resize(2);
    to_prop = 0;

    res = data;
  }

  ll priority;
  ll subtree_size;
  ll data;
  ll res;
  ll to_prop;
};

ll size(treap* t) {
  if (t == nullptr) return 0;
  return t->subtree_size;
}

ll get_res(treap* t) {
  if (t == nullptr) return 0;
  return t->res;
}

void recalc(treap* t) {
  if (t == nullptr) return;

  t->subtree_size = 1;
  for (int i = 0; i < 2; ++i) t->subtree_size += size(t->child[i]);

  t->res = t->data + t->to_prop * t->subtree_size;
  for (int i = 0; i < 2; ++i) t->res += get_res(t->child[i]);
}

void prop(treap* t) {
  if (t == nullptr) return;

  t->data += t->to_prop;
  for (int i = 0; i < 2; ++i) {
    if (t->child[i]) {
      t->child[i]->to_prop += t->to_prop;
      recalc(t->child[i]);
    }
  }
  t->to_prop = 0;
  recalc(t);
}

treap* merge(treap* left, treap* right) {
  if (left == nullptr) return right;
  if (right == nullptr) return left;

  if (left->priority < right->priority) {
    prop(left);
    left->child[1] = merge(left->child[1], right);
    recalc(left);
    return left;
  } else {
    prop(right);
    right->child[0] = merge(left, right->child[0]);
    recalc(right);
    return right;
  }
}

vector<treap*> split(treap* t, ll left_size) {
  if (t == nullptr) return {nullptr, nullptr};
  if (left_size == size(t)) return {t, nullptr};
  if (left_size == 0) return {nullptr, t};

  prop(t);

  if (left_size <= size(t->child[0])) {
    auto left_split = split(t->child[0], left_size);
    t->child[0] = left_split[1];
    recalc(t);

    return {left_split[0], t};
  } else {
    auto right_split = split(t->child[1], left_size - size(t->child[0]) - 1);
    t->child[1] = right_split[0];
    recalc(t);

    return {t, right_split[1]};
  }
}

template <typename Itr>
treap* make_treap(Itr begin, Itr end) {
  if (begin == end) return nullptr;

  treap* left = new treap(*begin);
  begin++;

  left = merge(left, make_treap(begin, end));

  return left;
}

treap* range_add(treap* t, ll left, ll right, ll x) {
  auto s1 = split(t, left);
  auto s2 = split(s1[1], (right - left + 1));

  dbg(size(s2[0]), get_res(s2[0]));

  prop(s2[0]);
  s2[0]->to_prop = x;
  recalc(s2[0]);

  dbg(size(s2[0]), get_res(s2[0]));

  return merge(s1[0], merge(s2[0], s2[1]));
}

pair<ll, treap*> query(treap* t, ll left, ll right) {
  auto s1 = split(t, left);
  auto s2 = split(s1[1], (right - left + 1));

  auto res = s2[0]->res;

  return {res, merge(s1[0], merge(s2[0], s2[1]))};
}

ll n;
ll a[100005];

treap* t;

void solve() {
  cin >> n;
  for (ll i = 0; i < n; ++i) cin >> a[i];

  t = make_treap(a, a + n);

  while (true) {
    ll type, l, r, x;
    cin >> type >> l >> r;

    if (type == 1) {
      auto [res, new_t] = query(t, l, r);
      t = new_t;

      cout << res << endl;
    } else {
      cin >> x;
      t = range_add(t, l, r, x);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

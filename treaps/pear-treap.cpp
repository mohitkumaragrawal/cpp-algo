#include <bits/stdc++.h>
using namespace std;

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

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

mt19937 mt(time(nullptr));
uniform_int_distribution<ll> uid;

const ll MOD = 1e9 + 7;
ll binexp(ll a, ll b, ll p = MOD) {
  if (b < 0) return 0;
  ll res = 1;
  while (b > 0) {
    if (b & 1) b--, res = (res * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return res;
}

inline ll modinv(ll x, ll p = MOD) { return binexp(x, p - 2, p); }
template <ll mod>
struct MODINT_ {
  ll value;
  MODINT_() = default;
  MODINT_(ll x) : value(x % mod) {}
  MODINT_(const MODINT_& m) : value(m.value % mod) {}
  MODINT_& operator=(const MODINT_& m) {
    value = m.value;
    return *this;
  }
  ll inverse_value() const { return modinv(value, mod); }
  MODINT_& operator+=(const MODINT_& m) {
    value = (value + m.value) % mod;
    return *this;
  }
  MODINT_& operator-=(const MODINT_& m) {
    value = (mod + value - m.value) % mod;
    return *this;
  }
  MODINT_& operator*=(const MODINT_& m) {
    value = (value * m.value) % mod;
    return *this;
  }
  MODINT_& operator/=(const MODINT_& m) {
    value = (value * m.inverse_value()) % mod;
    return *this;
  }
  MODINT_& operator++() {
    value++;
    value %= mod;
    return *this;
  }
  MODINT_& operator--() {
    value--;
    value %= mod;
    return *this;
  }
  MODINT_ operator*(const MODINT_& b) { return MODINT_(value * b.value); }
  MODINT_ operator*(ll b) { return MODINT_(value * b); }
  MODINT_ operator-(const MODINT_& b) { return MODINT_(mod + value - b.value); }
  MODINT_ operator-(ll b) { return MODINT_(mod + value - b); }
  MODINT_ operator+(const MODINT_& b) { return MODINT_(value + b.value); }
  MODINT_ operator+(ll b) { return MODINT_(value + b); }
  MODINT_ operator/(const MODINT_& b) {
    return MODINT_(value * modinv(b.value, mod));
  }
  MODINT_ operator/(ll b) { return MODINT_(value * modinv(b, mod)); }
};
template <ll mod>
ostream& operator<<(ostream& out, const MODINT_<mod>& m) {
  out << m.value % mod;
  return out;
}
template <ll mod>
istream& operator>>(istream& in, MODINT_<mod>& m) {
  ll x;
  in >> x;
  m.value = (x % mod);
  return in;
}

using MODINT = MODINT_<MOD>;

struct treap {
  vector<treap*> child;

  treap(char val) : data(val) {
    priority = uid(mt);
    subtree_size = 1;

    child.resize(2);

    forward_hash = (val - 'a' + 1);
    backward_hash = (val - 'a' + 1);
  }

  ll priority;
  ll subtree_size;

  char data;

  MODINT forward_hash;
  MODINT backward_hash;
};

ll size(treap* t) {
  if (t == nullptr) return 0;
  return t->subtree_size;
}

ll p31[300005];
void init_powers() {
  p31[0] = 1;
  for (ll i = 1; i <= 300000; ++i) p31[i] = (31LL * p31[i - 1]) % MOD;
}

void recalc(treap* t) {
  if (t == nullptr) return;

  t->subtree_size = 1;
  for (int i = 0; i < 2; ++i) t->subtree_size += size(t->child[i]);

  t->forward_hash = 0;

  ll pw = 0;
  ll c1 = t->data - 'a' + 1;

  if (t->child[0]) {
    t->forward_hash += t->child[0]->forward_hash;
    pw += size(t->child[0]);
  }
  t->forward_hash += (c1 * p31[pw]) % MOD;
  if (t->child[1]) {
    t->forward_hash += t->child[1]->forward_hash * p31[1 + pw];
  }

  pw = 0;
  t->backward_hash = 0;

  if (t->child[1]) {
    t->backward_hash += t->child[1]->backward_hash;
    pw += size(t->child[1]);
  }
  t->backward_hash += (c1 * p31[pw]) % MOD;
  if (t->child[0]) {
    t->backward_hash += t->child[0]->backward_hash * p31[1 + pw];
  }
}

treap* merge(treap* left, treap* right) {
  if (left == nullptr) return right;
  if (right == nullptr) return left;

  if (left->priority < right->priority) {
    left->child[1] = merge(left->child[1], right);
    recalc(left);
    return left;
  } else {
    right->child[0] = merge(left, right->child[0]);
    recalc(right);
    return right;
  }
}

vector<treap*> split(treap* t, ll left_size) {
  if (t == nullptr) return {nullptr, nullptr};
  if (left_size == size(t)) return {t, nullptr};
  if (left_size == 0) return {nullptr, t};

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

void inorder(treap* t) {
  if (t == nullptr) return;
  inorder(t->child[0]);
  cout << t->data;
  inorder(t->child[1]);
}

void solve() {
  ll n, q;
  cin >> n >> q;

  string s;
  cin >> s;

  treap* t = make_treap(all(s));

  while (q--) {
    ll type;
    cin >> type;

    if (type == 1) {
      ll l, r;
      cin >> l >> r;
      l--;
      r--;

      auto s1 = split(t, l);
      auto s2 = split(s1[1], (r - l + 1));

      t = merge(s1[0], s2[1]);

    } else if (type == 2) {
      ll p;
      char c;
      cin >> c >> p;

      p--;
      auto s1 = split(t, p);
      treap* mid = new treap(c);

      t = merge(s1[0], merge(mid, s1[1]));

    } else if (type == 3) {
      ll l, r;
      cin >> l >> r;
      l--;
      r--;

      auto s1 = split(t, l);
      auto s2 = split(s1[1], (r - l + 1));

      if (s2[0]->forward_hash.value == s2[0]->backward_hash.value) {
        cout << "yes\n";
      } else {
        cout << "no\n";
      }

      t = merge(s1[0], merge(s2[0], s2[1]));
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  init_powers();

  solve();
}

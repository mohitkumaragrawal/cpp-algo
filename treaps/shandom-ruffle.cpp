#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = int;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

mt19937 mt(time(nullptr));
uniform_int_distribution<ll> uid;

struct treap {
  vector<treap*> child;

  treap(ll val) : data(val) {
    priority = uid(mt);
    subtree_size = 1;

    child.resize(2);
  }

  ll priority;
  ll subtree_size;
  ll data;
};

ll size(treap* t) {
  if (t == nullptr) return 0;
  return t->subtree_size;
}

void recalc(treap* t) {
  if (t == nullptr) return;

  t->subtree_size = 1;
  for (int i = 0; i < 2; ++i) t->subtree_size += size(t->child[i]);
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

vector<ll> inorder_res;
void inorder(treap* t) {
  if (t == nullptr) return;

  inorder(t->child[0]);
  inorder_res.push_back(t->data);
  inorder(t->child[1]);
}

treap* t;

void solve() {
  ll n;
  cin >> n;

  for (ll i = 1; i <= n; ++i) {
    t = merge(t, new treap(i));
  }

  for (ll i = 0; i < n; ++i) {
    ll a, b;
    cin >> a >> b;

    if (a >= b) continue;

    a--;
    b--;

    ll len = min(b - a, n - b);

    auto s1 = split(t, a);
    auto s2 = split(s1[1], len);
    auto s3 = split(s2[1], (b - a) - len);
    auto s4 = split(s3[1], len);

    swap(s2[0], s4[0]);
    treap* new_t =
        merge(s1[0], merge(s2[0], merge(s3[0], merge(s4[0], s4[1]))));

    t = new_t;
  }

  inorder(t);
  for (ll x : inorder_res) cout << x << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

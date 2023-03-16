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

struct node_data {
  ll l, r, ans, ans_rev, cnt[2];
  bool flipped = false;
};

string s;
node_data nul_node = {-1, -1, -1, -1, {0, 0}, 0};
vector<node_data> tree;

// common mistakes:
// 1. don't forget the push before moving on to the child nodes;
// 2. set the l, r values in build_tree
// 3. combine method should not deal with lazy propagation for better
// understanding and bug free code; it should be handled by recalc method;
//
// 4. in push, try predict the changes in the children before pushing their
// values; as it may causes TLE
//
// 5. in update queries, don't forget to recalc the parent recursively;

// combine is like merging two node_data into a single one.
// it is generally to be used in conjuinction with the query methods;
// and should not deal with the lazy propagation values;
node_data combine(node_data a, node_data b, bool flipped = false) {
  if (a.l == -1) return b;
  if (b.l == -1) return a;

  assert(a.r + 1 == b.l);

  node_data res;
  res.l = a.l;
  res.r = b.r;

  for (ll i = 0; i < 2; ++i) {
    res.cnt[i] = a.cnt[i] + b.cnt[i];
  }

  res.ans = a.ans + b.ans + a.cnt[1] * b.cnt[0];
  res.ans_rev = a.ans_rev + b.ans_rev + a.cnt[0] * b.cnt[1];

  if (flipped) {
    swap(res.ans, res.ans_rev);
    swap(res.cnt[0], res.cnt[1]);
  }

  res.flipped = flipped;

  return res;
}

// calculate the value of the node, taking into account the propagation values
// using the values of its child nodes and also defines the base case when l ==
// r, if it's possible it should use combine (only if it helps)
void recalc(ll id) {
  if (tree[id].l == tree[id].r) {
    tree[id].ans = tree[id].ans_rev = 0;
    tree[id].cnt[0] = tree[id].cnt[1] = 0;

    if (s[tree[id].l] == '0')
      tree[id].cnt[0] = 1;
    else
      tree[id].cnt[1] = 1;

    if (tree[id].flipped) {
      swap(tree[id].ans, tree[id].ans_rev);
      swap(tree[id].cnt[0], tree[id].cnt[1]);
    }
  } else {
    tree[id] = combine(tree[2 * id], tree[2 * id + 1], tree[id].flipped);
  }
}

// push the lazy propagation values to its chld nodes making appropriate
// changes, also defines the base case for which it touches the original
// array
void push(ll id) {
  if (!tree[id].flipped) return;

  tree[id].flipped = false;

  if (tree[id].l == tree[id].r) {
    if (s[tree[id].l] == '0') {
      s[tree[id].l] = '1';
    } else {
      s[tree[id].l] = '0';
    }

    recalc(id);
  } else {
    tree[2 * id].flipped ^= 1;
    tree[2 * id + 1].flipped ^= 1;

    recalc(2 * id);
    recalc(2 * id + 1);
  }
}

// it's always the same, set the l and r of each node_data and recalc itself
// after building the child nodes
void build_tree(ll id, ll l, ll r) {
  tree[id].l = l;
  tree[id].r = r;

  if (l == r) {
    recalc(id);
  } else {
    ll mid = (l + r) / 2;

    build_tree(2 * id, l, mid);
    build_tree(2 * id + 1, mid + 1, r);

    recalc(id);
  }
}

// it's also always the same but don't forget to push the lazy propagation
// values, before moving on to the child nodes;
node_data query(ll id, ll ql, ll qr) {
  if (tree[id].l > qr || ql > tree[id].r) return nul_node;
  if (ql <= tree[id].l && tree[id].r <= qr) return tree[id];

  push(id);
  return combine(query(2 * id, ql, qr), query(2 * id + 1, ql, qr));
}

// don't forget to push before moving on the child nodes;
void flip_range(ll id, ll ql, ll qr) {
  push(id);
  if (tree[id].l > qr || ql > tree[id].r) {
    return;
  }
  if (ql <= tree[id].l && tree[id].r <= qr) {
    tree[id].flipped = true;
    recalc(id);
    return;
  }

  flip_range(2 * id, ql, qr);
  flip_range(2 * id + 1, ql, qr);

  recalc(id);
}

void solve() {
  ll n, q;
  cin >> n >> q;

  tree.clear();
  tree.resize(4 * n + 1);

  cin >> s;

  build_tree(1, 0, n - 1);

  while (q--) {
    ll t, l, r;
    cin >> t >> l >> r;
    l--;
    r--;

    if (t == 1) {
      flip_range(1, l, r);
    } else {
      ll ans = query(1, l, r).ans;
      cout << ans << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

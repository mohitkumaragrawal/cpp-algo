#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

struct node {
  ll l, r;
  ll ans;
  ll cnt[2];
  bool flipped;
};

vector<node> tree;

ll n, q;
string s;

void recalc(ll id) {
  if (tree[id].l != tree[id].r) {
    tree[id].cnt[0] = tree[2 * id].cnt[0] + tree[2 * id + 1].cnt[0];
    tree[id].cnt[1] = tree[2 * id].cnt[1] + tree[2 * id + 1].cnt[1];

    tree[id].ans = tree[2 * id].ans + tree[2 * id + 1].ans +
                   tree[2 * id].cnt[1] * tree[2 * id + 1].cnt[0];
  } else {
    ll val = s[tree[id].l] - '0';
    tree[id].cnt[val] = 1;
    tree[id].cnt[1 - val] = 0;

    tree[id].ans = 0;
  }

  if (tree[id].flipped) {
    swap(tree[id].cnt[0], tree[id].cnt[1]);
  }
}

void push(ll id) {
  if (!tree[id].flipped) return;

  if (tree[id].l == tree[id].r) {
    tree[id].flipped = 0;

    ll idx = tree[id].l;
    s[idx] = (s[idx] == '0') ? '1' : '0';

    recalc(id);
    return;
  }

  push(2 * id);
  push(2 * id + 1);
  tree[2 * id].flipped = 1;
  tree[2 * id + 1].flipped = 1;

  recalc(2 * id);
  recalc(2 * id + 1);

  tree[id].flipped = 0;

  recalc(id);
}

void build_tree(ll id, ll l, ll r) {
  tree[id].l = l;
  tree[id].r = r;

  if (l == r) {
    ll val = s[l] - '0';
    tree[id].cnt[val] = 1;
    tree[id].cnt[1 - val] = 0;

    tree[id].ans = 0;
    tree[id].flipped = 0;

    return;
  }

  ll mid = (l + r) / 2;
  build_tree(2 * id, l, mid);
  build_tree(2 * id + 1, mid + 1, r);

  recalc(id);
}

void flip_range(ll id, ll ql, ll qr) {
  if (tree[id].l > qr || tree[id].r < ql) return;

  if (tree[id].l >= ql && tree[id].r <= qr) {
    tree[id].flipped ^= 1;
    recalc(id);
    return;
  }

  push(id);

  flip_range(2 * id, ql, qr);
  flip_range(2 * id + 1, ql, qr);

  recalc(id);
}

node query(ll id, ll ql, ll qr) {
  if (tree[id].l > qr || tree[id].r < ql) {
    node res;
    res.l = -1;
    res.r = -1;
    res.cnt[0] = 0;
    res.cnt[1] = 0;
    res.ans = 0;
    res.flipped = 0;
    return res;
  }

  if (tree[id].l >= ql && tree[id].r <= qr) return tree[id];

  push(id);

  node left = query(2 * id, ql, qr);
  node right = query(2 * id + 1, ql, qr);

  node res;
  res.l = left.l;
  res.r = right.r;

  res.cnt[0] = left.cnt[0] + right.cnt[0];
  res.cnt[1] = left.cnt[1] + right.cnt[1];

  res.ans = left.ans + right.ans + left.cnt[1] * right.cnt[0];

  return res;
}

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  tree.clear();

  cin >> n >> q;
  cin >> s;
  tree.resize(4 * n);

  build_tree(1, 0, n - 1);

  string str = s;

  auto find_res = [&](ll l, ll r) {
    ll ones = 0;
    ll ans = 0;
    for (ll i = l; i <= r; ++i) {
      if (str[i] == '1')
        ones++;
      else
        ans += ones;
    }

    return ans;
  };

  auto flip_str = [&](ll l, ll r) {
    for (ll i = l; i <= r; ++i) {
      if (str[i] == '1')
        str[i] = '0';
      else
        str[i] = '1';
    }
  };

  vector<tuple<ll, ll, ll>> vt;

  while (q--) {
    ll t, l, r;
    // cin >> t >> l >> r;

    t = rng() % 2 + 1;
    l = rng() % n + 1;
    r = rng() % n + 1;

    if (l > r) swap(l, r);

    vt.emplace_back(t, l, r);
    l--;
    r--;

    if (t == 1) {
      flip_range(1, l, r);
      flip_str(l, r);
    } else if (t == 2) {
      ll ans1 = query(1, l, r).ans;
      ll ans2 = find_res(l, r);

      cout << ans1 << " " << ans2 << endl;

      if (ans1 != ans2) {
        cout << "ERROR" << endl;
        cout << "State: " << str << endl;
        for (auto [t, l, r] : vt) {
          cout << t << " " << l << " " << r << endl;
        }
        return;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

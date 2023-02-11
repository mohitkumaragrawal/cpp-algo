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

struct treap {
  treap(int data) : data(data) {
    priority = mt();
    subtree_size = 1;
    child.assign(2, nullptr);

    suf[0] = suf[1] = pre[0] = pre[1] = mx[0] = mx[1] = cnt[0] = cnt[1] = 0;
    pre[data] = suf[data] = mx[data] = cnt[data] = 1;
  }

  vector<treap*> child;

  int priority;
  int subtree_size;
  int data;

  bool flipped = false;
  bool mirror = false;

  bool sorted = false;
  int zero_count = 0;  // meaningful only if sorted is set;

  int suf[2], pre[2], mx[2], cnt[2];

  friend void recalc(treap* t) {
    if (t == nullptr) return;

    t->subtree_size = 1;
    for (treap* ch : t->child) {
      t->subtree_size += size(ch);
    }

    if (t->sorted) {
      t->pre[0] = t->zero_count;
      t->suf[1] = t->subtree_size - t->zero_count;

      if (t->zero_count == 0) {
        t->pre[1] = t->suf[1];
      } else {
        t->pre[1] = 0;
      }

      if (t->zero_count == size(t)) {
        t->suf[0] = t->pre[0];
      } else {
        t->suf[0] = 0;
      }

      t->cnt[0] = t->mx[0] = t->zero_count;
      t->cnt[1] = t->mx[1] = size(t) - t->zero_count;

      return;
    }

    t->suf[0] = t->suf[1] = t->pre[0] = t->pre[1] = t->mx[0] = t->mx[1] = 0;
    t->cnt[0] = t->cnt[1] = 0;

    t->cnt[t->data]++;
    for (int i = 0; i < 2; ++i) {
      if (!t->child[i]) continue;
      for (int j = 0; j < 2; ++j) {
        t->cnt[j] += t->child[i]->cnt[j];
      }
    }

    for (int i = 0; i < 2; ++i) {
      if (t->child[0]) t->pre[i] = t->child[0]->pre[i];
      if (size(t->child[0]) == t->pre[i] && t->data == i) {
        t->pre[i] += 1;
        if (t->child[1]) t->pre[i] += t->child[1]->pre[i];
      }

      if (t->child[1]) t->suf[i] = t->child[1]->suf[i];
      if (size(t->child[1]) == t->suf[i] && t->data == i) {
        t->suf[i]++;
        if (t->child[0]) t->suf[i] += t->child[0]->suf[i];
      }

      for (int j = 0; j < 2; ++j) {
        if (t->child[j]) {
          t->mx[i] = max(t->mx[i], t->child[j]->mx[i]);
        }
      }

      if (t->data == i) {
        int newsz = 1;
        if (t->child[0]) newsz += t->child[0]->suf[i];
        if (t->child[1]) newsz += t->child[1]->pre[i];

        t->mx[i] = max(t->mx[i], newsz);
      }
    }

    if (t->flipped) {
      swap(t->mx[0], t->mx[1]);
      swap(t->pre[0], t->pre[1]);
      swap(t->suf[0], t->suf[1]);
      swap(t->cnt[0], t->cnt[1]);
    }

    if (t->mirror) {
      swap(t->pre[0], t->suf[0]);
      swap(t->pre[1], t->suf[1]);
    }
  }

  friend void prop(treap* t) {
    if (t == nullptr) return;
    if (t->flipped) {
      t->flipped = false;
      t->data ^= 1;

      for (int j = 0; j < 2; ++j) {
        if (!t->child[j]) continue;

        if (t->child[j]->sorted) prop(t->child[j]);
        t->child[j]->flipped = !t->child[j]->flipped;
        recalc(t->child[j]);
      }

      recalc(t);
    }

    if (t->mirror) {
      t->mirror = false;
      swap(t->child[0], t->child[1]);

      for (int j = 0; j < 2; ++j) {
        if (!t->child[j]) continue;

        if (t->child[j]->sorted) prop(t->child[j]);
        t->child[j]->mirror = !t->child[j]->mirror;
        recalc(t->child[j]);
      }
      recalc(t);
    }

    if (t->sorted) {
      t->sorted = false;

      for (int i = 0; i < 2; ++i) {
        if (!t->child[i]) continue;

        t->child[i]->flipped = false;
        t->child[i]->mirror = false;
        t->child[i]->sorted = true;
      }

      if (t->zero_count > size(t->child[0])) {
        t->data = 0;
        if (t->child[0]) {
          t->child[0]->zero_count = size(t->child[0]);
        }
        if (t->child[1]) {
          t->child[1]->zero_count = t->zero_count - 1 - size(t->child[0]);
        }
      } else {
        t->data = 1;
        if (t->child[0]) {
          t->child[0]->zero_count = t->zero_count;
        }
        if (t->child[1]) {
          t->child[1]->zero_count = 0;
        }
      }
      recalc(t->child[0]);
      recalc(t->child[1]);

      recalc(t);
    }
  }

  friend int size(treap* t) {
    if (t == nullptr) return 0;
    return t->subtree_size;
  };

  friend vector<treap*> split(treap* t, int left_size) {
    if (t == nullptr) return {nullptr, nullptr};
    if (left_size == 0) return {nullptr, t};
    if (left_size == t->subtree_size) return {t, nullptr};

    prop(t);

    if (size(t->child[0]) >= left_size) {
      auto s = split(t->child[0], left_size);
      t->child[0] = s[1];
      recalc(t);

      return {s[0], t};
    } else {
      auto s = split(t->child[1], left_size - 1 - size(t->child[0]));
      t->child[1] = s[0];
      recalc(t);

      return {t, s[1]};
    }
  }

  friend treap* merge(treap* left, treap* right) {
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

  friend int result(treap* t) {
    if (!t) return 0;
    return max(t->mx[0], t->mx[1]);
  }
};

void inorder(treap* t) {
  if (t == nullptr) return;

  inorder(t->child[0]);

  ll type = 0;
  if (t->flipped) type |= 1;
  if (t->mirror) type |= 2;
  if (t->sorted) type |= 4;

  cout << type << " ";

  inorder(t->child[1]);
}

void solve() {
  int n, q;
  cin >> n >> q;

  string data;
  cin >> data;

  treap* T = nullptr;
  for (char ch : data) {
    T = merge(T, new treap(ch - '0'));
  }

  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    l--;
    r--;

    if (t == 1) {
      auto s1 = split(T, l);
      auto s2 = split(s1[1], (r - l + 1));
      if (s2[0]) {
        prop(s2[0]);
        s2[0]->flipped = true;
        recalc(s2[0]);
      }
      T = merge(s1[0], merge(s2[0], s2[1]));

      cout << result(T) << endl;

    } else if (t == 2) {
      auto s1 = split(T, l);
      auto s2 = split(s1[1], (r - l + 1));
      if (s2[0]) {
        prop(s2[0]);
        s2[0]->mirror = true;
        recalc(s2[0]);
      }
      T = merge(s1[0], merge(s2[0], s2[1]));

      cout << result(T) << endl;

    } else if (t == 3) {
      auto s1 = split(T, l);
      auto s2 = split(s1[1], (r - l + 1));
      if (s2[0]) {
        prop(s2[0]);
        s2[0]->sorted = true;
        s2[0]->zero_count = s2[0]->cnt[0];

        recalc(s2[0]);
      }
      T = merge(s1[0], merge(s2[0], s2[1]));
      cout << result(T) << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}

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

const int MX = 1e6 + 5;

int uop[4 * MX], ucl[4 * MX], tree[4 * MX];
string s;

void build_tree(int id, int tl, int tr) {
  if (tl == tr) {
    if (s[tl] == '(') {
      uop[id] = 1;
    } else {
      ucl[id] = 1;
    }
    return;
  }
  int mid = (tl + tr) / 2;

  int x = 2 * id;
  int y = x + 1;

  build_tree(x, tl, mid);
  build_tree(y, mid + 1, tr);

  int k = min(uop[x], ucl[y]);

  tree[id] = tree[x] + tree[y] + 2 * k;
  uop[id] = uop[x] + uop[y] - k;
  ucl[id] = ucl[x] + ucl[y] - k;
}

tuple<int, int, int> query(int id, int tl, int tr, int ql, int qr) {
  if (ql > tr || qr < tl) return {0, 0, 0};

  if (ql <= tl && tr <= qr) {
    return {tree[id], uop[id], ucl[id]};
  }

  int mid = (tl + tr) / 2;
  auto [s1, uop1, ucl1] = query(2 * id, tl, mid, ql, qr);
  auto [s2, uop2, ucl2] = query(2 * id + 1, mid + 1, tr, ql, qr);

  int k = min(uop1, ucl2);
  return {s1 + s2 + 2 * k, uop1 + uop2 - k, ucl1 + ucl2 - k};
}

void solve() {
  cin >> s;
  build_tree(1, 0, s.size() - 1);

  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;

    int ans = get<0>(query(1, 0, s.size() - 1, x - 1, y - 1));
    cout << ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

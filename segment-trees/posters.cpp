#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int lazy[4 * 10000007];
void shift(int id) {
  if (lazy[id]) {
    lazy[2 * id] = lazy[2 * id + 1] = lazy[id];
    lazy[id] = 0;
  }
}

void update(int ql, int qr, int clr, int id = 1, int tl = 0,
            int tr = 10000000) {
  if (ql > tr || tl > qr) return;
  if (ql <= tl && tr <= qr) {
    lazy[id] = clr;
    return;
  }

  shift(id);
  int mid = (tl + tr) / 2;
  update(ql, qr, clr, 2 * id, tl, mid);
  update(ql, qr, clr, 2 * id + 1, mid + 1, tr);
}

set<int> s;

void query(int id = 1, int ql = 0, int qr = 10000000) {
  if (lazy[id]) {
    s.insert(lazy[id]);
    return;
  }

  if (ql == qr) return;

  int mid = (ql + qr) / 2;
  query(2 * id, ql, mid);
  query(2 * id + 1, mid + 1, qr);
}

void solve() {
  int q;
  cin >> q;

  for (int i = 1; i <= q; ++i) {
    int l, r;
    cin >> l >> r;

    update(l, r, i);
  }

  query();
  s.erase(0);
  cout << s.size() << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) {
    update(0, 10000000, 0);
    solve();
  }
}

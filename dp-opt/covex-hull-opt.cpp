#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

const ll is_query = -(1LL << 62);
struct line {
  ll m, b;
  mutable function<const line*()> succ;
  bool operator<(const line& rhs) const {
    if (rhs.b != is_query) return m < rhs.m;
    const line* s = succ();
    if (!s) return 0;
    ll x = rhs.m;
    return b - s->b < (s->m - m) * x;
  }
};

struct dynamic_hull
    : public multiset<line> {  // will maintain upper hull for maximum
  const ll inf = LLONG_MAX;
  bool bad(iterator y) {
    auto z = next(y);
    if (y == begin()) {
      if (z == end()) return 0;
      return y->m == z->m && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()) return y->m == x->m && y->b <= x->b;

    /* compare two lines by slope, make sure denominator is not 0 */
    ll v1 = (x->b - y->b);
    if (y->m == x->m)
      v1 = x->b > y->b ? inf : -inf;
    else
      v1 /= (y->m - x->m);
    ll v2 = (y->b - z->b);
    if (z->m == y->m)
      v2 = y->b > z->b ? inf : -inf;
    else
      v2 /= (z->m - y->m);
    return v1 >= v2;
  }
  void insert_line(ll m, ll b) {
    auto y = insert({m, b});
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad(y)) {
      erase(y);
      return;
    }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
  }
  ll eval(ll x) {
    auto l = *lower_bound((line){x, is_query});
    return l.m * x + l.b;
  }
};

dynamic_hull hull;
ll n, a[200005], b[200005], dp[200005], p[200005];
void solve() {
  cin >> n;
  for (ll i = 0; i < n; ++i) cin >> a[i];
  for (ll i = 0; i < n; ++i) cin >> b[i];

  p[0] = a[0];
  for (ll i = 1; i < n; ++i) p[i] = p[i - 1] + a[i];

  dp[0] = 0;
  hull.insert_line(0, 0);

  for (ll i = 1; i < n; ++i) {
    dp[i] = p[i] * b[i] - hull.eval(b[i]);
    hull.insert_line(p[i - 1], -dp[i]);
  }

  for (ll i = 0; i < n; ++i) cout << dp[i] << " \n"[i == n - 1];
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}

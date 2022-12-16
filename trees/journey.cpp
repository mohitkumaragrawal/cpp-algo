#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
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

using ll = long long;
using lld = long double;
using ull = unsigned long long;

lld ans = 0;
vector<vector<ll>> G;
ll n;

void dfs(ll node, ll parent, ll depth, lld prob) {
  ll cc = 0;
  for (ll child : G[node])
    if (child != parent) cc++;

  if (cc == 0) {
    dbg(node, parent, depth, prob);

    ans += prob * depth;
    return;
  }

  for (ll child : G[node]) {
    if (child == parent) continue;
    dfs(child, node, 1 + depth, prob * (1.0 / cc));
  }
}

void solve() {
  cin >> n;
  G.resize(n);

  for (ll i = 0; i < n - 1; ++i) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  dfs(0, -1, 0, 1);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cout << fixed << setprecision(12);

  solve();
}

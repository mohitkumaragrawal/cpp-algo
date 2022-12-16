#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

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

vector<vector<ll>> G;
ll n, H[300005], D[300005];

void dfs(ll node, ll parent) {
  ll diam = 0;
  vector<ll> height;

  for (ll child : G[node]) {
    if (child == parent) continue;

    dfs(child, node);

    diam = max(diam, D[child]);
    height.push_back(H[child]);
  }

  sort(all(height), greater<ll>());

  ll diam2 = 0;
  if (height.size() == 1) {
    diam2 = 1 + height[0];
  } else if (height.size() > 1) {
    diam2 = 2 + height[0] + height[1];
  }
  if (!height.empty()) H[node] = 1 + height[0];

  D[node] = max(diam, diam2);
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

  dfs(0, -1);
  ll ans = 3 * D[0];
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}

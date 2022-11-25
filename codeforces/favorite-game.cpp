#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

vector<vector<pair<ll, ll>>> G;
ll n, a, b;

void dfs(ll node, vector<ll>& v, vector<bool>& vis) {
  vis[node] = true;

  if (node == b && v[b] != 0) {
    return;
  }

  for (auto [nd, wt] : G[node]) {
    if (vis[nd]) continue;
    v[nd] = v[node] ^ wt;

    dfs(nd, v, vis);
  }
}

void solve() {
  cin >> n >> a >> b;
  a--;
  b--;

  G.clear();
  G.resize(n);

  for (ll i = 0; i < n - 1; ++i) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;

    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }

  vector<ll> a_xr(n, -1), b_xr(n);
  a_xr[a] = 0;
  b_xr[b] = 0;

  vector<bool> a_vis(n, false), b_vis(n, false);
  dfs(a, a_xr, a_vis);
  dfs(b, b_xr, b_vis);

  if (a_xr[b] == 0) {
    cout << "YES" << endl;
    return;
  }

  for (ll i = 0; i < n; ++i) {
    if (i == b) continue;
    if (b_xr[i] == 0) {
      cout << "YES" << endl;
      return;
    }
  }

  set<ll> values;
  for (ll i = 0; i < n; ++i) {
    if (i == b || i == a || a_xr[i] == -1) continue;
    values.insert(a_xr[i]);
  }

  for (ll i = 0; i < n; ++i) {
    if (i == a || i == b) continue;

    if (values.find(b_xr[i]) != values.end()) {
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll n;
vector<vector<ll>> G;

void dfs(ll node, ll prev, ll dist, vector<pair<ll, ll>>& vpr) {
  vpr.push_back({node, dist});
  for (ll next : G[node]) {
    if (next != prev) dfs(next, node, dist + 1, vpr);
  }
}

void solve() {
  cin >> n;
  G.resize(n);
  for (ll i = 0; i < n - 1; ++i) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  if (n == 1) {
    cout << "0\n";
    return;
  }

  vector<pair<ll, ll>> vpr;
  dfs(0, -1, 0, vpr);
  ll x = 0;

  {
    ll dist = 0;
    for (auto pr : vpr) {
      if (pr.second > dist) {
        x = pr.first;
        dist = pr.second;
      }
    }
  }

  vpr.clear();
  dfs(x, -1, 0, vpr);

  ll dist = 0;
  for (auto pr : vpr) {
    if (pr.second > dist) {
      x = pr.first;
      dist = pr.second;
    }
  }

  cout << 3 * dist << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

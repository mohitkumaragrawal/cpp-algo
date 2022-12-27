#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll n, d;
vector<vector<ll>> G;

// first[i]: deepest node that first should visit;
// second[i]: deepest node that second should visist;
ll parent[200005], first[200005], second[200005], depth[200005];

// first_vis[i]: should first visit this node;
// second_vis[i]: should second visit this node;
bool first_vis[200005], second_vis[200005];

ll dp[200005];

void dfs(ll node, ll par, ll dep) {
  parent[node] = par;
  depth[node] = dep;

  for (ll child : G[node]) {
    if (child != par) {
      dfs(child, node, dep + 1);
    }
  }

  if (first_vis[node]) {
    first[node] = node;
  }
  for (ll child : G[node]) {
    if (child != par) {
      if (depth[first[child]] >= depth[first[node]]) {
        first[node] = first[child];
      }
    }
  }

  if (second_vis[node]) {
    second[node] = node;
  }
  for (ll child : G[node]) {
    if (child != par) {
      if (depth[second[child]] >= depth[second[node]]) {
        second[node] = second[child];
      }
    }
  }
}

void dp_dfs(ll node) {
  for (ll child : G[node]) {
    if (child != parent[node]) {
      dp_dfs(child);

      dp[node] += dp[child];

      ll f_dist = depth[first[child]] - depth[node];
      ll s_dist = depth[second[child]] - depth[node];

      if (f_dist > 0 && s_dist > 0) {
        dp[node] += 4;
        continue;
      }

      if (f_dist > 0 || s_dist > 0) {
        dp[node] += 2;

        if (f_dist > d || s_dist > d) {
          dp[node] += 2;
        }
      }
    }
  }
}

void solve() {
  cin >> n >> d;
  G.resize(n);
  for (ll i = 0; i < n - 1; ++i) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;

    G[u].push_back(v);
    G[v].push_back(u);
  }

  ll m1;
  cin >> m1;
  for (ll i = 0; i < m1; ++i) {
    ll u;
    cin >> u;
    u--;
    first_vis[u] = true;
  }

  ll m2;
  cin >> m2;
  for (ll i = 0; i < m2; ++i) {
    ll u;
    cin >> u;
    u--;
    second_vis[u] = true;
  }

  dfs(0, -1, 0);
  dp_dfs(0);

  cout << dp[0] << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}

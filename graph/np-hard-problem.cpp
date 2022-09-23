#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll N, M;
vector<vector<ll>> G;
vector<int> color;

bool color_dfs(int node, int parent, int clr) {
  if (color[node] != -1) {
    // this node is already visisted and colored;
    if (color[node] == clr) {
      return true;
    } else {
      return false;
    }
  }

  if (G[node].size() == 0) return true;

  color[node] = clr;
  int child_color = clr ^ 1;
  for (auto child : G[node]) {
    if (child == parent) continue;
    if (!color_dfs(child, node, child_color)) return false;
  }
  return true;
}

int main() {
  cin >> N >> M;
  G.resize(N + 1);

  for (ll i = 0; i < M; ++i) {
    ll u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  color.assign(N + 1, -1);
  bool success = true;
  for (int i = 1; i <= N; ++i) {
    if (color[i] != -1) continue;
    success &= color_dfs(i, -1, 1);
  }

  if (!success) {
    cout << -1 << endl;
  } else {
    vector<ll> zeros, ones;
    for (ll i = 1; i <= N; ++i) {
      if (color[i] == 0) {
        zeros.push_back(i);
      } else if (color[i] == 1) {
        ones.push_back(i);
      }
    }

    cout << zeros.size() << endl;
    for (auto x : zeros) cout << x << " ";
    cout << endl;
    cout << ones.size() << endl;
    for (auto y : ones) cout << y << " ";
    cout << endl;
  }
}

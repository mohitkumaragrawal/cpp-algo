#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> G;
vector<bool> visisted;
vector<int> low, tin;
vector<pair<int, int>> bridges;
int timer;

void bridge_dfs(int node, int p = -1) {
  visisted[node] = true;
  tin[node] = low[node] = timer;
  timer++;

  for (int child : G[node]) {
    if (p == child) continue;

    if (visisted[child]) {
      // back edge from node - child;
      low[node] = min(low[node], tin[child]);

    } else {
      // forward edge from node-child;

      bridge_dfs(child, node);
      low[node] = min(low[node], low[child]);

      // edge (node - child) is a bridge if and only if low[child] > tin[node]
      if (tin[node] < low[child]) {
        // there is a bridge from (node - child)
        bridges.push_back({node, child});
      }
    }
  }
}

void find_bridges() {
  visisted.assign(N + 1, false);
  tin.assign(N + 1, -1);
  low.assign(N + 1, -1);
  timer = 0;

  for (int i = 1; i <= N; ++i) {
    if (!visisted[i]) bridge_dfs(i);
  }

  for (auto pr : bridges) {
    cout << "BRIDGE " << pr.first << " - " << pr.second << endl;
  }
}

int main() {
  int M;
  cin >> N >> M;

  G.resize(N + 1);

  while (M--) {
    int u, v;
    cin >> u >> v;

    G[u].push_back(v);
    G[v].push_back(u);
  }

  find_bridges();
}
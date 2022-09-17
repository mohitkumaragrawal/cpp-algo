#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> G;
vector<bool> visited;
vector<int> dp;
vector<int> tin;

int timer;
void bridge_dfs(int node, int parent) {
  visited[node] = true;
  tin[node] = timer++;

  for (auto child : G[node]) {
    if (child == parent) continue;

    if (visited[child]) {
      // child must be an ancestor of node in DFS tree
      // so we have a backedge from child going down to node;
      if (tin[child] < tin[node]) {
        dp[node]++;
        dp[child]--;
      }

    } else {
      bridge_dfs(child, node);

      dp[node] += dp[child];
    }
  }

  if (dp[node] == 0 && parent != -1) {
    cout << "bridge " << parent << " -- " << node << endl;
  }
}

void find_bridge() {
  visited.assign(N + 1, false);
  dp.assign(N + 1, 0);
  tin.assign(N + 1, 0);

  for (int i = 1; i <= N; ++i) {
    if (!visited[i]) bridge_dfs(i, -1);
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

  find_bridge();
}
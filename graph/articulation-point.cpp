#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
int N;

vector<bool> visited;
vector<int> tin, low;
vector<int> result;

int timer;
void articulation_dfs(int node, int parent) {
  visited[node] = true;

  tin[node] = low[node] = timer++;

  // children are the direct descendents of this node which is connected with a
  // forward edge in the dfs tree
  int children = 0;
  for (auto child : G[node]) {
    if (child == parent) continue;

    if (visited[child]) {
      // back edge;
      low[node] = min(low[node], tin[child]);
    } else {
      children++;
      articulation_dfs(child, node);

      if (low[child] >= tin[node] && parent != -1) {
        // node is an articulation point;
        result.push_back(node);
      }

      low[node] = min(low[node], low[child]);
    }
  }

  if (parent == -1 && children > 0) {
    result.push_back(node);
  }
}

void find_articulation_point() {
  cin >> N;
  int M;
  cin >> M;

  G.resize(N + 1);

  while (M--) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  visited.assign(N + 1, false);
  tin.assign(N + 1, -1);
  low.assign(N + 1, -1);

  for (int i = 1; i <= N; ++i) {
    if (!visited[i]) articulation_dfs(i, -1);
  }

  cout << "Ariculation Points : ";
  for (auto el : result) cout << el << " ";
  cout << endl;
}
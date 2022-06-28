#include <iostream>
#include <vector>
using namespace std;

struct graph {
  int N, E;
  vector<vector<int>> ad;
  vector<bool> visisted;

  void take_input() {
    cin >> N >> E;
    ad.resize(N + 1);
    visisted.resize(N + 1, false);

    for (int i = 0; i < E; ++i) {
      int u, v;
      cin >> u >> v;

      ad[u].push_back(v);
      ad[v].push_back(u);
    }
  }

  bool cycle_dfs(int node, int parent) {
    if (visisted[node]) return false;

    visisted[node] = true;
    for (int child : ad[node]) {
      if (child == parent) continue;

      if (visisted[child]) return true;
      if (cycle_dfs(child, node)) {
        return true;
      }
    }
    return false;
  }

  bool has_cycle() {
    for (int i = 1; i <= N; ++i) {
      if (visisted[i]) continue;

      if (cycle_dfs(i, -1)) return true;
    }
    return false;
  }
};

int main() {
  graph g;
  g.take_input();

  if (g.has_cycle()) {
    cout << "HAS CYCLE" << endl;
  } else {
    cout << "ACYCLIC" << endl;
  }
}
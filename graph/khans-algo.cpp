#include <bits/stdc++.h>
using namespace std;

struct Graph {
  Graph(int n) : nodes(n) { g.resize(n); }

  vector<int> khans_algo() {
    vector<int> indegree(nodes, 0);

    for (int i = 0; i < nodes; ++i) {
      for (int to : g[i]) {
        indegree[to]++;
      }
    }

    queue<int> q;
    for (int i = 0; i < nodes; ++i) {
      if (indegree[i] == 0) q.push(i);
    }

    vector<int> result;
    while (!q.empty()) {
      int el = q.front();
      q.pop();

      result.push_back(el);
      for (int to : g[el]) {
        indegree[to]--;
        if (indegree[to] == 0) q.push(to);
      }
    }
    return result;
  }

  void topo_dfs(int n, vector<int>& result, vector<bool>& visited) {
    if (visited[n]) return;

    visited[n] = true;
    for (int child : g[n]) {
      topo_dfs(child, result, visited);
    }

    result.push_back(n);
  }

  vector<int> topological_sort() {
    vector<int> result;
    vector<bool> visited(nodes, false);

    for (int i = 0; i < nodes; ++i) {
      topo_dfs(i, result, visited);
    }

    reverse(result.begin(), result.end());
    return result;
  }

  int nodes;
  vector<vector<int>> g;
};

int main() {
  freopen("khans-algo.txt", "r", stdin);
  int N, E;
  cin >> N >> E;
  Graph graph(N);

  while (E--) {
    int u, v;
    cin >> u >> v;
    graph.g[u].push_back(v);
  }

  auto sorted = graph.khans_algo();
  cout << "Khan's Algorithm: ";
  for (int el : sorted) cout << el << " ";
  cout << endl;

  auto topo_sort = graph.topological_sort();
  cout << "Topological Sort: ";
  for (int el : topo_sort) cout << el << " ";
  cout << endl;
}
#include <iostream>
#include <vector>

using namespace std;

void dfs(int N, vector<vector<int>>& graph, vector<bool>& visited, int node) {
  if (visited[node]) return;
  visited[node] = true;

  for (int nd : graph[node]) {
    dfs(N, graph, visited, nd);
  }
}

int main() {
  int N, E;
  cin >> N >> E;

  vector<vector<int>> graph(N + 1);

  for (int _ = 0; _ < E; ++_) {
    int n1, n2;
    cin >> n1 >> n2;

    graph[n1].push_back(n2);
    graph[n2].push_back(n1);
  }

  vector<bool> visisted(N + 1, false);
  int cc = 0;

  for (int i = 1; i <= N; ++i) {
    if (visisted[i]) continue;

    dfs(N, graph, visisted, i);
    cc++;
  }

  cout << cc << endl;
}
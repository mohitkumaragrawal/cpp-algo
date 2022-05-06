#include <iostream>
#include <vector>

using namespace std;

// now the color is either 0 or 1
bool isBipartite(const vector<vector<int>>& graph, vector<bool>& visisted,
                 vector<int>& clr, int node, int color) {
  if (visisted[node]) {
    return clr[node] == color;
  }

  visisted[node] = true;
  clr[node] = color;

  bool bipartite = true;
  int childColor = color ^ 1;

  for (int childNode : graph[node]) {
    bipartite &= isBipartite(graph, visisted, clr, childNode, childColor);
  }

  return bipartite;
}

int main() {
  int T;
  cin >> T;

  for (int scenario = 1; scenario <= T; ++scenario) {
    int N, E;
    cin >> N >> E;
    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < E; ++i) {
      int n1, n2;
      cin >> n1 >> n2;
      graph[n1].push_back(n2);
      graph[n2].push_back(n1);
    }

    vector<bool> visited(N + 1, false);
    vector<int> clr(N + 1, -1);

    bool bipartite = true;
    for (int i = 1; i <= N; ++i) {
      if (!visited[i]) {
        bipartite &= isBipartite(graph, visited, clr, i, 0);
      }
    }

    cout << "Scenario #" << scenario << ":" << endl;
    if (bipartite) {
      cout << "No suspicious bugs found!" << endl;
    } else {
      cout << "Suspicious bugs found!" << endl;
    }
  }
}
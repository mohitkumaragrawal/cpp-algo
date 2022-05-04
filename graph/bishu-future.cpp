#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, int node, int dist, vector<int>& distance,
         vector<bool>& visisted) {
  if (visisted[node]) return;
  visisted[node] = true;
  for (auto nd : graph[node]) {
    distance[nd] = dist + 1;
    dfs(graph, nd, distance[nd], distance, visisted);
  }
}

int main() {
  int N;
  cin >> N;

  vector<vector<int>> graph(N + 1);

  for (int i = 1; i <= (N - 1); ++i) {
    int n1, n2;
    cin >> n1 >> n2;

    graph[n1].push_back(n2);
    graph[n2].push_back(n1);
  }

  vector<int> distance(N + 1, 0);
  vector<bool> visisted(N + 1, false);
  dfs(graph, 1, 0, distance, visisted);

  int Q;
  cin >> Q;

  int GFCountry = INT_MAX;   // the country of the girlfriend;
  int GFDistance = INT_MAX;  // how far is his girlfriend?? probably not too far

  while (Q--) {
    int q;
    cin >> q;

    if (distance[q] < GFDistance) {
      GFCountry = min(GFCountry, q);
    }
  }

  cout << GFCountry << endl;
}
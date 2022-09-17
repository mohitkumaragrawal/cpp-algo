#include <bits/stdc++.h>
using namespace std;

void assign_group(int node, int group, vector<vector<int>>& G,
                  vector<bool>& visited, vector<int>& gr) {
  if (visited[node]) return;
  visited[node] = true;
  gr[node] = group;

  for (int child : G[node]) {
    assign_group(child, group, G, visited, gr);
  }
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> G(N + 1);
  while (M--) {
    int size;
    cin >> size;

    if (size == 0) continue;

    int first;
    cin >> first;

    for (int i = 1; i < size; ++i) {
      int el;
      cin >> el;
      G[first].push_back(el);
      G[el].push_back(first);
    }
  }
  vector<int> gr(N + 1, -1);
  vector<bool> visited(N + 1, false);

  int tmp = 1;
  for (int i = 1; i <= N; ++i) {
    if (!visited[i]) {
      assign_group(i, tmp, G, visited, gr);
      tmp++;
    }
  }

  map<int, int> fr;
  for (int i = 1; i <= N; ++i) {
    fr[gr[i]]++;
  }

  for (int i = 1; i <= N; ++i) {
    cout << fr[gr[i]] << " ";
  }
  cout << endl;
}
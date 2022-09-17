#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& jmp, vector<bool>& visited) {
  if (visited[node]) return;

  visited[node] = true;
  int child_node = node + jmp[node];
  dfs(child_node, jmp, visited);
}

int main() {
  int N, t;
  cin >> N >> t;

  vector<int> jmps(N + 1);
  for (int i = 1; i < N; ++i) cin >> jmps[i];
  jmps[N] = 0;

  vector<bool> visited(N, false);
  dfs(1, jmps, visited);

  if (visited[t]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
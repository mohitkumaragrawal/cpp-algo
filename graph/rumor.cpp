#include <bits/stdc++.h>
using namespace std;

long N, M;
vector<long> C;
vector<vector<long>> G;
vector<bool> visisted;

// returns the minimum cost of its connected component;
long dfs(long node) {
  if (visisted[node]) return C[node];

  visisted[node] = true;
  long result = C[node];
  for (auto child : G[node]) {
    result = min(result, dfs(child));
  }
  return result;
}

int main() {
  cin >> N >> M;
  C.resize(N + 1);
  G.resize(N + 1);
  visisted.resize(N + 1, false);

  for (long i = 1; i <= N; ++i) {
    cin >> C[i];
  }

  for (long i = 0; i < M; ++i) {
    long x, y;
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  unsigned long long cost = 0;
  for (long i = 1; i <= N; ++i) {
    if (!visisted[i]) cost += dfs(i);
  }
  cout << cost << endl;
}

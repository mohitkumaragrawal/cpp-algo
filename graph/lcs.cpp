#include <iostream>
#include <vector>

#define LOG 14

using namespace std;

int N;
vector<vector<int>> children;
vector<vector<int>> up;
vector<int> depth;

int lcs(int n1, int n2) {
  if (depth[n1] < depth[n2]) swap(n1, n2);

  int k = depth[n1] - depth[n2];

  for (int j = 0; j < LOG; ++j) {
    if (k & (1 << j)) {
      n1 = up[n1][j];
    }
  }

  if (n1 == n2) return n1;

  for (int j = LOG - 1; j >= 0; --j) {
    if (up[n1][j] != up[n2][j]) {
      n1 = up[n1][j];
      n2 = up[n2][j];
    }
  }
  return up[n1][0];
}

void dfs(int node) {
  for (auto ch : children[node]) {
    depth[ch] = depth[node] + 1;
    up[ch][0] = node;

    for (int j = 1; j < LOG; ++j) {
      up[ch][j] = up[up[ch][j - 1]][j - 1];
    }

    dfs(ch);
  }
}

void preprocessing() {
  depth.resize(N);
  depth[0] = 0;

  up.resize(N);
  for (int i = 0; i < N; ++i) up[i].resize(LOG);
  for (int i = 0; i < LOG; ++i) up[0][i] = 0;

  dfs(0);
}

int main() {
  cin >> N;
  children.resize(N);

  for (int i = 0; i < N; ++i) {
    int M;
    cin >> M;
    children[i].resize(M);
    for (auto& x : children[i]) cin >> x;
  }

  preprocessing();
  int Q;
  cin >> Q;

  while (Q--) {
    int n1, n2;
    cin >> n1 >> n2;
    cout << lcs(n1, n2) << endl;
  }
}
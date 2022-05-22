#include <bits/stdc++.h>
using namespace std;
int n, m;
bool vis[1000][1000];
vector<vector<int>> square;
void dfs(int i, int j) {
  static int n = square[0].size(), m = square.size();
  if (i < 0 || j < 0) return;
  if (i >= m || j >= n) return;
  if (vis[i][j] || square[i][j] == 0) return;
  vis[i][j] = true;

  dfs(i - 1, j);
  dfs(i + 1, j);

  dfs(i, j + 1);
  dfs(i, j - 1);
}
int main() {
  int count = 0;
  cin >> m >> n;

  for (int i = 0; i < m; i++) {
    vector<int> temp;
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    square.push_back(temp);
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (vis[i][j] || square[i][j] == 0) continue;
      dfs(i, j);
      count++;
    }
  }
  cout << count;
}
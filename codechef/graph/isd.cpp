#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i,
         int j) {
  int m = grid.size();
  int n = grid[0].size();
  if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || grid[i][j] == 0)
    return;

  visited[i][j] = true;
  dfs(grid, visited, i - 1, j);
  dfs(grid, visited, i + 1, j);
  dfs(grid, visited, i, j - 1);
  dfs(grid, visited, i, j + 1);
}

int main() {
  int m, n;
  cin >> m >> n;

  vector<vector<int>> grid(m, vector<int>(n));
  vector<vector<bool>> visited(m, vector<bool>(n, false));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) cin >> grid[i][j];
  }

  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 0 || visited[i][j]) continue;

      dfs(grid, visited, i, j);
      cnt++;
    }
  }
  cout << cnt << endl;
}
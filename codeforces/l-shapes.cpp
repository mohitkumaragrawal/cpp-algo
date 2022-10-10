#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> cc;
vector<string> grid;
vector<bool> vis;
vector<bool> na;

int N, M;

int h(int r, int c) { return (r * 50) + c; }

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int r, int c) {
  if (r < 0 || c < 0 || r >= N || c >= M) return false;
  return true;
}

bool dfs(int r, int c) {
  int hash = h(r, c);
  vis[hash] = true;
  if (na[hash]) return false;
  cc.push_back({r, c});

  bool result = true;
  for (int i = 0; i < 4; ++i) {
    int nr = r + dx[i], nc = c + dy[i];

    if (!valid(nr, nc) || vis[h(nr, nc)] || grid[nr][nc] == '.') continue;

    result &= dfs(nr, nc);
    if (!result) {
      return false;
    }
  }

  return result;
}

void mark_na(int r, int c) {
  int ddx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
  int ddy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

  for (int i = 0; i < 9; ++i) {
    int nr = r + ddx[i], nc = c + ddy[i];
    if (valid(nr, nc)) na[h(nr, nc)] = true;
  }
}

void solve() {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    string row;
    cin >> row;
    grid.push_back(row);
  }

  vis.assign(2500, false);
  na.assign(2500, false);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (grid[i][j] == '.') continue;
      if (vis[h(i, j)]) continue;

      cc.clear();
      bool result = dfs(i, j);
      if (!result) {
        cout << "NO" << endl;
        return;
      }

      if (cc.size() != 3) {
        cout << "NO" << endl;
        return;
      }

      int mx_row = cc[0].first, mx_col = cc[0].second;
      int mn_row = cc[0].first, mn_col = cc[0].second;
      for (int i = 1; i < 3; ++i) {
        mx_row = max(mx_row, cc[i].first);
        mn_row = min(mn_row, cc[i].first);

        mx_col = max(mx_col, cc[i].second);
        mn_col = min(mn_col, cc[i].second);
      }

      if ((mx_row - mn_row) != 1 || (mx_col - mn_col) != 1) {
        cout << "NO" << endl;
        return;
      }

      for (int i = 0; i < 3; ++i) {
        mark_na(cc[i].first, cc[i].second);
      }
    }
  }

  cout << "YES" << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    grid.clear();
    cc.clear();
    solve();
  }
}
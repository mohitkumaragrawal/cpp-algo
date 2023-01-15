#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using lld = long double;

vector<string> grid;
bool horz_flipped = false, vert_flipped = false;
int c_row = 1, c_col = 1;
bool on_finish = false;
int n, m;

inline char get_char(int row, int col) { return grid[row - 1][col - 1]; }

pair<int, int> query(char ch) {
  if (on_finish) return {-1, -1};

  cout << ch << endl;
  int x, y;
  cin >> x >> y;

  if (get_char(x, y) == 'F') {
    on_finish = true;
  }

  return {x, y};
}

void test_horz() {
  if (on_finish) return;
  auto [n_row, n_col] = query('R');
  if (n_col == 1) {
    horz_flipped = true;
  }
  c_col = n_col;
}

void test_vert() {
  if (on_finish) return;
  auto [n_row, n_col] = query('D');
  if (n_row == 1) {
    vert_flipped = 1;
  }
  c_row = n_row;
}

void move_horz(int dirn) {
  if (on_finish) return;
  if (horz_flipped) dirn *= -1;
  if (dirn == 1) {
    auto [n_row, n_col] = query('R');
    c_row = n_row;
    c_col = n_col;
  } else {
    auto [n_row, n_col] = query('L');
    c_row = n_row;
    c_col = n_col;
  }
}

void move_vert(int dirn) {
  if (on_finish) return;
  if (vert_flipped) dirn *= -1;
  if (dirn == 1) {
    auto [n_row, n_col] = query('D');
    c_row = n_row;
    c_col = n_col;
  } else {
    auto [n_row, n_col] = query('U');
    c_row = n_row;
    c_col = n_col;
  }
}

bool is_safe(int row, int col) {
  if (row < 1 || row > n) return false;
  if (col < 1 || col > m) return false;
  return get_char(row, col) != '*';
}

void solve() {
  cin >> n >> m;

  grid.resize(n);
  for (int i = 0; i < n; ++i) cin >> grid[i];

  queue<pair<int, int>> q;
  vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
  vector<vector<pair<int, int>>> parent(n + 1, vector<pair<int, int>>(m + 1));

  q.push({1, 1});

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    if (vis[r][c]) continue;
    vis[r][c] = true;

    if (get_char(r, c) == 'F') {
      c_row = r;
      c_col = c;
      break;
    }

    if (is_safe(r, c + 1) && !vis[r][c + 1]) {
      q.push({r, c + 1});
      parent[r][c + 1] = {r, c};
    }
    if (is_safe(r, c - 1) && !vis[r][c - 1]) {
      q.push({r, c - 1});
      parent[r][c - 1] = {r, c};
    }
    if (is_safe(r + 1, c) && !vis[r + 1][c]) {
      q.push({r + 1, c});
      parent[r + 1][c] = {r, c};
    }
    if (is_safe(r - 1, c) && !vis[r - 1][c]) {
      q.push({r - 1, c});
      parent[r - 1][c] = {r, c};
    }
  }

  vector<pair<int, int>> path;
  while (c_row != 1 || c_col != 1) {
    path.push_back({c_row, c_col});

    auto [p_row, p_col] = parent[c_row][c_col];
    c_row = p_row;
    c_col = p_col;
  }

  c_row = 1;
  c_col = 1;

  bool tested_horz = false, tested_vert = false;

  while (!on_finish) {
    auto [n_row, n_col] = path.back();
    path.pop_back();

    int del_row = n_row - c_row;
    int del_col = n_col - c_col;

    if (del_col != 0 && !tested_horz) {
      tested_horz = true;
      test_horz();

      del_row = n_row - c_row;
      del_col = n_col - c_col;
    }

    if (del_row != 0 && !tested_vert) {
      tested_vert = true;
      test_vert();

      del_row = n_row - c_row;
      del_col = n_col - c_col;
    }

    if (del_col != 0) {
      move_horz(del_col);
    }

    if (del_row != 0) {
      move_vert(del_row);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}

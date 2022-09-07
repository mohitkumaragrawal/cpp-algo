#include <bits/stdc++.h>
#define OUT(i) cout << "Case #" << i << ": "
using namespace std;

struct TestCase {
  TestCase(int test) : T(test) {}

  int calc_count(int i, int j) {
    if (grid[i][j] == '#') return -1;
    int count = 0;
    vector<pair<int, int>> kids = {
        {i - 1, j}, {i + 1, j}, {i, j + 1}, {i, j - 1}};

    for (auto kid : kids) {
      if (!valid(kid.first, kid.second)) continue;

      if (grid[kid.first][kid.second] != '#') count++;
    }
    return count;
  }

  int calc_count2(int i, int j) {
    int count = 0;
    vector<pair<int, int>> kids = {
        {i - 1, j}, {i + 1, j}, {i, j + 1}, {i, j - 1}};

    for (auto kid : kids) {
      if (!valid(kid.first, kid.second)) continue;

      if (cnt[kid.first][kid.second] != -1) count++;
    }
    return count;
  }

  bool valid(int i, int j) {
    if (i < 0 || j < 0 || i >= R || j >= C) return false;
    return true;
  }

  void put_rock(int i, int j) {
    if (cnt[i][j] <= 0) {
      cnt[i][j] = -1;
      return;
    }

    queue<pair<int, int>> q;
    q.push(make_pair(i, j));

    while (!q.empty()) {
      auto pr = q.front();
      q.pop();

      int m = pr.first, n = pr.second;
      if (cnt[m][n] == -1) continue;
      cnt[m][n] = -1;

      vector<pair<int, int>> kids = {
          {m - 1, n}, {m + 1, n}, {m, n + 1}, {m, n - 1}};

      for (auto kid : kids) {
        if (!valid(kid.first, kid.second)) continue;
        int kid_cnt = calc_count2(kid.first, kid.second);
        if (kid_cnt == 1) {
          q.push(kid);
        }
        if (kid_cnt == 0) cnt[kid.first][kid.second] = -1;
      }
    }
  }

  void solve() {
    cin >> R >> C;
    grid.resize(R, vector<char>(C));

    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        cin >> grid[i][j];
      }
    }
    cnt.resize(R, vector<int>(C, 0));

    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        int count = calc_count(i, j);
        if (count == 1) {
          if (grid[i][j] == '^') {
            OUT(T) << "Impossible" << endl;
            return;
          }
          ones.push_back(make_pair(i, j));
        }

        cnt[i][j] = count;
        if (count == 0) {
          cnt[i][j] = -1;
        }
      }
    }
    for (auto one : ones) {
      put_rock(one.first, one.second);
    }

    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (grid[i][j] == '#') continue;
        if (grid[i][j] == '^' && cnt[i][j] == -1) {
          OUT(T) << "Impossible" << endl;
          return;
        }

        if (cnt[i][j] != -1) grid[i][j] = '^';
      }
    }

    OUT(T) << "Possible" << endl;
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        cout << grid[i][j];
      }
      cout << endl;
    }
  }

  int T;
  int R, C;
  vector<vector<char>> grid;
  vector<vector<int>> cnt;
  vector<pair<int, int>> ones;
};

int main() {
  int tests;
  cin >> tests;

  for (int T = 1; T <= tests; ++T) {
    TestCase t(T);
    t.solve();
  }
}
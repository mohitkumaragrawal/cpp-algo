#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Plus {
  int row;
  int l;
  int k;
};

void mark_plus(vector<string>& v, const Plus& p) {
  int i = p.row, l = p.l, k = p.k;
  int col = l + (k-1)/2;
  int offset = k/2;
  for (int x = 0; x < k; ++x) {
    v[i][x+l] = 'X';
  }
  for (int x = -offset; x <= offset; ++x) {
    v[i+x][col] = 'X';
  }
}

vector<Plus> find_plus(vector<string>& v, int k, int amount = -1) {
  int offset = k / 2;

  vector<Plus> val;
  for (int i = offset; i < v.size() - offset; ++i) {

    auto tmpstr = string(k, 'G');
    vector<int> pos;
    
    auto tmppos = v[i].find(tmpstr, 0);
    while (tmppos != string::npos) {
      pos.push_back(tmppos);
      tmppos = v[i].find(tmpstr, tmppos + 1);
    }
    
    for (auto l: pos) {
      int col = l + (k-1)/2;
      bool verticle_line = true;
      for (int x = -offset; x <= offset; ++x) {
        if (v[i+x][col] != 'G') {
          verticle_line = false;
          break;
        }
      }
      if (verticle_line) {
        val.push_back({
          i, l, k
        });

        if (val.size() == amount) {
          return val;
        }
      }
    }
  }

  return val;
}

int main() {
  int m, n;
  cin >> m >> n;
  vector<string> grid(m);
  for (int i = 0; i < m; ++i) {
    cin >> grid[i];
  }
  // largest possible plus
  int l = min(m, n);
  if (l%2==0) l--;

  int ans = 0;

  for (int i = l; i >= 1; i-=2) {
    auto p1s = find_plus(grid, i);
    for (auto p1: p1s) {
      auto grid_copy = vector<string>(grid);
      mark_plus(grid_copy, p1);

      // time to find the other pluses;
      for (int j = i; j >= 1; j-=2) {
        auto p2s = find_plus(grid_copy, j, 1);
        if (p2s.size() != 0) {
          ans = max(ans, (2*i-1) * (2*j-1));
        }
      }
    }
  }

  cout << ans << endl;
}
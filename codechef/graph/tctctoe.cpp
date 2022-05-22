#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkWinner(string grid[3], char c) {
  for (int i = 0; i < 3; ++i) {
    if (grid[i][0] == c && grid[i][1] == c && grid[i][2] == c) return true;
    if (grid[0][i] == c && grid[1][i] == c && grid[2][i] == c) return true;
  }

  if (grid[0][0] == c && grid[1][1] == c && grid[2][2] == c) return true;
  if (grid[0][2] == c && grid[1][1] == c && grid[2][0] == c) return true;
  return false;
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    string grid[3];
    cin >> grid[0] >> grid[1] >> grid[2];

    int x = 0, o = 0;
    for (int i = 0; i < 3; ++i) {
      for (auto ch : grid[i]) {
        if (ch == 'X') x++;
        if (ch == 'O') o++;
      }
    }
    bool xwin = checkWinner(grid, 'X');
    bool owin = checkWinner(grid, 'O');

    if (x == o || x == o + 1) {
      if (xwin && owin) {
        cout << 3 << endl;
      } else {
        if (owin && (x > o)) {
          cout << 3 << endl;
        } else if (xwin && x == o) {
          cout << 3 << endl;
        } else if (xwin || owin || (x + o) == 9) {
          cout << 1 << endl;
        } else {
          cout << 2 << endl;
        }
      }
    } else {
      cout << 3 << endl;
    }
  }
}
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> state_after_n_seconds(vector<vector<char>>& initial_grid, int r, int c, int t) {
  if (t <= 1) return initial_grid;
  if (t % 2 == 0) {
    // grid full of bombs!
    return vector<vector<char>>(r, vector<char>(c, 'O'));
  }
  // state after 5, 9, 13, 17.. seconds are exactly same;
  if ((t-1)%4==0) {
    initial_grid = state_after_n_seconds(initial_grid, r, c, 3);
  }
  
  // and the state after 3, 7, 11, 15 seconds are same;
  auto result = vector<vector<char>>(r, vector<char>(c, 'O'));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      bool in_bomb_range = false;
      if (i > 0) {
        in_bomb_range = (initial_grid[i-1][j] == 'O');
      }
      if (j > 0) {
        in_bomb_range |= (initial_grid[i][j-1] == 'O');
      }
      if (i < r-1) {
        in_bomb_range |= (initial_grid[i+1][j] == 'O');
      }
      if (j < c-1) {
        in_bomb_range |= (initial_grid[i][j+1] == 'O');
      }
      in_bomb_range |= (initial_grid[i][j] == 'O');

      if (in_bomb_range) {
        result[i][j] = '.';
      }
    }
  }
  return result;
}

int main() {
  int r, c, t;
  cin >> r >> c >> t;
  vector<vector<char>> grid(r, vector<char>(c));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> grid[i][j];
    }
  }
  auto result = state_after_n_seconds(grid, r, c, t);
  for (int i = 0; i < r; ++i){
    for (int j = 0; j < c; ++j) {
      cout << result[i][j];
    }
    cout << endl;
  }
}
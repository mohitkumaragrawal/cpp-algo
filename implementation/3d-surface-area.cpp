#include <iostream>
#include <vector>
using namespace std;

int calculateSurfaceArea(int H, int W, vector<vector<int>>& mat) {
  int area = 2 * H * W; // area of floor and ceiling

  // calculate the area of walls;
  for (int k = 1; k <= 100; ++k) { // where k represents the height of block;
    int wallarea = 0;

    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (mat[i][j] < k) continue;

        bool hasTopBlock = false;
        bool hasLeftBlock = false;

        if (i > 0 && (mat[i-1][j] >= k)) {
          hasTopBlock = true;
        }

        if (j > 0 && (mat[i][j-1] >= k)) {
          hasLeftBlock = true;
        }

        wallarea += 4;
        if (hasLeftBlock) {
          wallarea -= 2;
        }

        if (hasTopBlock) {
          wallarea -= 2;
        }
      }
    }

    if (wallarea == 0) {
      break; // means there are no blocks at this height;
    } else {
      area += wallarea;
    }
  }

  return area;
}

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<int>> mat(H, vector<int>(W));
  for (int i =0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> mat[i][j];
    }
  }
  cout << calculateSurfaceArea(H, W, mat) << endl;
}
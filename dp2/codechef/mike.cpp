#include <bits/stdc++.h>
using namespace std;

int find_max_consecutive_ones(vector<int>& v) {
  int ans = 0;
  int ones = 0;
  
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] ==  1) {
      ones++;
    } else {
      ans = max(ans, ones);
      ones = 0;
    }
  }
  ans = max(ans, ones);
  
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, Q;
  cin >> M >> N >> Q;

  vector<vector<int>> grid(M, vector<int>(N));
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> grid[i][j];
    }
  }

  vector<int> result(M);

  for (int i = 0; i < M; ++i) {
    result[i] = find_max_consecutive_ones(grid[i]); 
  }

  while (Q--) {
    int x, y;
    cin >> x >> y;
    x--;y--;
    grid[x][y] ^= 1;

    result[x] = find_max_consecutive_ones(grid[x]);

    int ans = *max_element(result.begin(), result.end());
    cout << ans << endl;
  }
}

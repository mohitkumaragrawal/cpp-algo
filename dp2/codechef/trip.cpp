#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  if (N == 1) {
    // handle the weird case
    cout << 0 << " " << 1 << endl;
    return 0;
  }

  vector<int> stops(N);
  for (int& x : stops) cin >> x;

  vector<vector<int>> ways(N, vector<int>(1002, 0));

  ways[0][0] = 1;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 1001; ++j) {
      for (int k = i + 1; k < N; ++k) {
        int dist = stops[k] - stops[i];
        if (dist > M) break;
        ways[k][1 + j] += ways[i][j];
      }
    }
  }

  for (int i = 1; i < 1002; ++i) {
    if (ways[N - 1][i] != 0) {
      cout << i - 1 << " " << ways[N - 1][i] << endl;
      break;
    }
  }
}
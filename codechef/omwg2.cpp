#include <bits/stdc++.h>
using namespace std;
long sum, result;
int g[1002][1002];
int n, m;
int count1(int x, int y) {
  int sum = g[x + 1][y] + g[x - 1][y] + g[x][y - 1] + g[x][y + 1];
  return sum;
}

void dfs(int x, int y) {
  if (x < 1 || y < 1 || x > n || y > m) return;
  if (g[x][y]) return;
  g[x][y] = 1;

  result += count1(x, y);
  dfs(x - 1, y);
  dfs(x + 1, y);
  dfs(x, y + 1);
  dfs(x, y - 1);
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    result = 0;
    cin >> n >> m;
    dfs(1, 1);
    cout << result << endl;
  }
}
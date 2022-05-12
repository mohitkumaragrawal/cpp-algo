#include <limits.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int diff(const string& a, const string& b) {
  int ans = 0;
  for (int i = 0; i < a.size(); ++i) {
    ans += abs(a[i] - b[i]);
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto& s : grid) cin >> s;

    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        ans = min(ans, diff(grid[i], grid[j]));
      }
    }
    cout << ans << endl;
  }
}
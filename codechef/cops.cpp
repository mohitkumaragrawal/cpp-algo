#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int x, y, M;
    cin >> M >> x >> y;
    vector<int> arr(M);
    for (int& i : arr) cin >> i;

    int xy = x * y;

    int ans = 0;
    for (int i = 1; i <= 100; ++i) {
      bool safe = true;

      for (auto m : arr) {
        if (i >= (m - xy) && i <= (m + xy)) {
          safe = false;
          break;
        }
      }

      if (safe) {
        ans++;
      }
    }
    cout << ans << endl;
  }
}
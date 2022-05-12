#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int m, n;
    cin >> m >> n;
    int ans = 2 * m * n - m - n;
    cout << ans << endl;
  }
}
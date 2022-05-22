#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (auto& i : arr) cin >> i;

    int cnt = 0;
    long mask = 1;

    while (mask < INT_MAX) {
      bool has = false;
      for (auto x : arr) {
        if (x & mask) {
          has = true;
          break;
        }
      }
      if (has) cnt++;
      mask *= 2;
    }
    cout << cnt << endl;
  }
}
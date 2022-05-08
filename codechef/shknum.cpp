#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> pow2;
  pow2.push_back(1);

  while (pow2.back() < 1000000000) {
    pow2.push_back(pow2.back() * 2);
  }

  vector<int> arr;

  for (int i = 1; i < pow2.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      arr.push_back(pow2[i] + pow2[j]);
    }
  }

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;

    int low = 0;
    int high = arr.size() - 1;

    int Z = high;

    while (true) {
      if (low > high) break;
      int mid = (low + high) / 2;

      if (arr[mid] >= N) {
        Z = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    int ans = arr[Z] - N;
    if (Z > 0) ans = min(ans, N - arr[Z - 1]);

    cout << ans << endl;
  }
}
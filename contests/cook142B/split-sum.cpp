#include <limits.h>

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
    for (int& i : arr) cin >> i;

    long mask = 1;
    vector<pair<int, int>> vp;

    bool found = false;

    while (mask < (1 << 30)) {
      vp.clear();
      long sum = 0;
      long left = 1;
      long right = left;

      for (int idx = 0; idx < N; ++idx) {
        sum += arr[idx];
        long val = sum & mask;

        if (val == 0) {
          long prevval = (sum - arr[idx]) & mask;
          if (prevval != 0) {
            // we had a pair;
            vp.push_back(make_pair(left, right));
            left = right + 1;
            sum = arr[idx];
            right = left;
          }
        } else {
          right = idx + 1;
        }
      }
      vp.push_back(make_pair(left, right));
      left = right + 1;

      if (vp.size() > 1 && right == N) {
        found = true;
        break;
      }

      mask *= 2;
    }

    if (!found) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      cout << vp.size() << endl;

      for (auto pr : vp) {
        cout << pr.first << " " << pr.second << endl;
      }
    }
  }
}
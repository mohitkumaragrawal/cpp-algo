#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int long long

signed main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int& i : arr) {
      cin >> i;
    }

    int OddSum = 0, EvenSum = 0;

    for (int i : arr) {
      if (i & 1)
        OddSum += i;
      else
        EvenSum += i;
    }
    int Sum = OddSum + EvenSum;
    int avg = Sum / N;
    int nhalf = N / 2;

    if (Sum % nhalf != 0) {
      cout << "NO" << endl;
      continue;
    }

    int oe = Sum / nhalf;

    bool flag = false;
    for (int o = 1; o <= oe; o += 2) {
      int e = oe - o;
      int oddSum = o * nhalf;
      int evenSum = e * nhalf;

      if (abs(evenSum - EvenSum) == abs(oddSum - OddSum)) {
        flag = true;
        break;
      }
    }
    if (flag) {
      cout << "YES" << endl;
    }
  }
}
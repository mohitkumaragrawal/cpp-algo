#include <iostream>
#include <vector>

using namespace std;

#define sz 200001

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> arr(N);

    vector<int> l1(sz, -1);
    vector<int> l2(sz);

    for (int& x : arr) cin >> x;

    long ans = 0;
    for (int i = 0; i < N; ++i) {
      int el = arr[i];

      int lm = i - el + 1;
      if (lm < 0) lm = 0;

      int rm = lm + el - 1;

      int lM = i;
      int rM = lM + el - 1;

      if (rM >= N) {
        rM = N - 1;
        lM = rM - el + 1;
      }
      // (lm, rm) through (lM, rM) are accepted pairs, such that rm-lm+1 = el;

      if (l1[el] == -1) {
        // first of its kind
        l1[el] = lm;
        l2[el] = lM;
        continue;
      }

      if (l2[el] < lm) {
        // when there is gap in the range;
        ans += l2[el] - l1[el] + 1;
        l1[el] = lm;
        l2[el] = lM;
        continue;
      }

      // merge the range;
      l2[el] = lM;
    }

    for (int i = 1; i < sz; ++i) {
      if (l1[i] == -1) continue;
      ans += (l2[i] - l1[i] + 1);
    }

    cout << ans << endl;
  }
}
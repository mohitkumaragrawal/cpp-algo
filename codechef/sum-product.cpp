#include <bits/stdc++.h>
using namespace std;

#define long long long

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int& i: A) cin >> i;

    long ones = 0;
    long ans = 0;

    for (auto i: A) {
      if (i == 0) {
        if (ones != 0) {
          long tmp = ((ones + 1) * ones) / 2;
          ans += tmp;
          ones = 0;
        }
      } else {
        ones++;
      }
    }
    if (ones != 0) {
      long tmp = ((ones + 1) * ones) / 2;
      ans += tmp;
      ones = 0;
    }
    cout << ans << endl;
  }
}

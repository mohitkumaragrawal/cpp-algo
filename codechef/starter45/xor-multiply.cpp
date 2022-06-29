#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, A, B;
    cin >> N >> A >> B;

    int ans = 0;
    vector<int> unequals;

    for (int i = 0; i < N; ++i) {
      int mask = 1 << i;

      bool hasA = (A & mask) != 0;
      bool hasB = (B & mask) != 0;

      if (!hasA && !hasB) {
        ans |= mask;
        continue;
      }

      if (hasA != hasB) {
        unequals.push_back(mask);
      }
    }
    if (unequals.empty()) {
      cout << ans << endl;
      continue;
    }

    for (int i = 0; i < unequals.size() - 1; ++i) {
      if (A & unequals[i]) {
        ans |= unequals[i];
      }
    }
    if (B & unequals.back()) {
      ans |= unequals.back();
    }
    cout << ans << endl;
  }
}

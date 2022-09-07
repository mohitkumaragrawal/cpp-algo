#include <bits/stdc++.h>
#define OUT(i) cout << "Case #" << i << ": "
using namespace std;

int main() {
  int T;
  cin >> T;

  for (int i = 1; i <= T; ++i) {
    int N, K;
    cin >> N >> K;

    vector<int> S(N);
    for (int& i : S) cin >> i;

    if (N > 2 * K) {
      OUT(i) << "NO" << endl;
      continue;
    }

    int freq[101] = {0};
    for (auto x : S) freq[x]++;

    bool possible = true;
    for (int j = 1; j <= 100; ++j) {
      if (freq[j] > 2) possible = false;
    }

    if (possible) {
      OUT(i) << "YES" << endl;
    } else {
      OUT(i) << "NO" << endl;
    }
  }
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N >> K;

    int last = N - 1;

    if (K == 0) {
      for (int i = 0; i < N / 2; ++i) {
        cout << i << " " << (i ^ last) << endl;
      }

      continue;
    }

    if (K == last) {
      if (N <= 4) {
        cout << -1 << endl;
        continue;
      }

      cout << (N - 1) << " " << (N - 2) << endl;
      cout << (N - 3) << " " << 1 << endl;
      cout << 0 << " " << 2 << endl;

      for (int i = 3; i < N / 2; ++i) {
        cout << i << " " << (i ^ last) << endl;
      }
      continue;
    }

    cout << K << " " << last << endl;
    int kc = K ^ last;
    for (int i = 1; i < (N / 2); ++i) {
      int j = i ^ last;

      if (i == kc || j == kc) {
        cout << 0 << " " << kc << endl;
        continue;
      }

      cout << i << " " << j << endl;
    }
  }
}
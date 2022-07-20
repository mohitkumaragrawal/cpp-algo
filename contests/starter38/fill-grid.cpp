#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int M, N;
    cin >> M >> N;

    int k1 = M % 2;
    int k2 = N % 2;

    if (k1 == 1 && k2 == 1) {
      cout << (M + N - 1) << endl;
    } else {
      cout << (k1 * N + k2 * M) << endl;
    }
  }
}
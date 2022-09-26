#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;

    int xr = 0;
    for (int i = 1; i <= N - 3; ++i) {
      xr ^= i;
      cout << i << " ";
    }
    if (xr != 0) {
      int l1 = 0;
      int l2 = (1 << 29) | xr;
      int l3 = (1 << 29);

      cout << l1 << " " << l2 << " " << l3 << endl;
    } else {
      int l1 = 1 << 29;
      int l2 = 2 << 29;
      int l3 = 3 << 29;
      cout << l1 << " " << l2 << " " << l3 << endl;
    }
  }
}
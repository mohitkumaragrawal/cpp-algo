#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int L, R;
    cin >> L >> R;

    int start = L;
    while (start & 1) {
      start++;
    }

    if (R - start + 1 < 4) {
      cout << -1 << endl;
      continue;
    }

    for (int i = 0; i <= 3; ++i) {
      cout << start + i << " ";
    }
    cout << endl;
  }
}

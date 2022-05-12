#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, X, K;
    cin >> N >> X >> K;

    int required = N * X;

    if (K >= required) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
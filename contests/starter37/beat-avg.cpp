#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N, M, X;
    cin >> N >> M >> X;

    if (X == M) {
      cout << 0 << endl;
    } else {
      int a = (N * X) / (X + 1);
      cout << a << endl;
    }
  }
}
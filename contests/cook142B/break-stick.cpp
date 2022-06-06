#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, X;
    cin >> N >> X;

    if (X > N) {
      cout << "NO" << endl;
      continue;
    }

    if (N % 2 == 0) {
      cout << "YES" << endl;
      continue;
    }

    if (X % 2 == 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
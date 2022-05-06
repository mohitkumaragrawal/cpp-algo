#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    int zero = 0, one = 0;

    while (N--) {
      int n;
      cin >> n;
      if (n == 0)
        zero++;
      else
        one++;
    }

    if (one >= zero) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
}
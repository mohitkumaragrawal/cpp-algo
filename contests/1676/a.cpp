#include <iostream>
#include <string>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    string x;
    cin >> x;

    int rSum = 0, lSum = 0;

    for (int i = 0; i < 3; ++i) {
      lSum += (x[i] - '0');
    }

    for (int i = 3; i < 6; ++i) {
      rSum += (x[i] - '0');
    }

    if (lSum == rSum) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
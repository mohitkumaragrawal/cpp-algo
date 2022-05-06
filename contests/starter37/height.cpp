#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int X, H;
    cin >> X >> H;

    if (X >= H) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
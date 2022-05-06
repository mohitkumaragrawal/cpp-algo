#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int X, Y, Z;

    cin >> X >> Y >> Z;

    int diff = (Z - Y);
    if (diff <= 0) {
      cout << 0 << endl;
    } else {
      cout << diff / X << endl;
    }
  }
}
#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int w, x, y, z;
    cin >> w >> x >> y >> z;
    int t = w + y * z;
    if (t > x) {
      cout << "overflow" << endl;
    } else if (t == x) {
      cout << "filled" << endl;
    } else {
      cout << "unfilled" << endl;
    }
  }
}
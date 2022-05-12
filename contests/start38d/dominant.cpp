#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    int s = a + b + c;

    bool d = false;

    d |= (2 * a > s);
    d |= (2 * b > s);
    d |= (2 * c > s);

    if (d) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int x;
    cin >> x;

    if (x > 30) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
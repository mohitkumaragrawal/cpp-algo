#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
      int x;
      cin >> x;
      sum += x;
    }

    if (sum % 2 == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

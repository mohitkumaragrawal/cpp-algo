#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;

    uint64_t ans = 0;

    int k = N;
    while (k > 0) {
      ans += k * k;
      k -= 2;
    }
    cout << ans << endl;
  }
}
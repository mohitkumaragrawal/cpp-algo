#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#define endl '\n'

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;

    if (N == 1 || N == 2) {
      cout << 1 << endl;
    } else {
      uint64_t n = N;
      uint64_t ans = 1 + (n - 2) * (n - 1);
      cout << ans << endl;
    }
  }
}
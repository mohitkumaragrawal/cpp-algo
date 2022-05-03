#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    int x, y;
    cin >> x >> y;

    // find a and b such that x . b^a = y

    if (x == y) {
      cout << 1 << " " << 1 << endl;
    } else if (x > y || (y % x) != 0) {
      cout << 0 << " " << 0 << endl;
    } else {
      // when x < y;

      int t = y / x;

      // map<int, int> pf;

      // for (int i = 2; i * i <= t; ++i) {
      //   while (t % i == 0) {
      //     t /= i;
      //     pf[i]++;
      //   }
      // }

      cout << 1 << " " << t << endl;
    }
  }
}
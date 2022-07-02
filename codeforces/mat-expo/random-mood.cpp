#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

double binexp(double x, int p) {
  double r = 1;
  while (p > 0) {
    if (p & 1)
      r *= x, p--;
    else
      x *= x, p /= 2;
  }
  return r;
}

int main() {
  int n;
  double p;
  cin >> n >> p;

  // ans = (1/2) [ 1 + (1-2p)^n ]
  double ans = 0.5 * (1 + binexp((1 - 2 * p), n));
  cout << fixed << setprecision(10) << ans << endl;
}

#include <iostream>
using namespace std;

#define int unsigned long long

int f(int n) {
  if (n == 2) return 0;
  int b = (n / 2);
  if (n % 2 == 0) b--;
  if (b % 2 == 0 && (n - b) % 2 == 0) b--;
  return b * (n - b) - 1;
}

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int g(int n) {
  int ans = 0;
  for (int i = 1; i <= n / 2; ++i) {
    int x = gcd(i, n - i);
    int val = (i / x) * (n - i) - x;
    if (val > ans) ans = val;
  }
  return ans;
}

signed main() {
  // int T;
  // cin >> T;
  // while (T--) {
  //   int n;
  //   cin >> n;
  //   cout << f(n) << " " << g(n) << endl;
  // }

  for (int i = 1; i < 10000; ++i) {
    if (f(i) != g(i)) cout << i << " ";
  }
}
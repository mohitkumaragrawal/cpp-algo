#include <array>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 50000

array<int, MAXN + 1> pow10;

void init_powers() {
  pow10[0] = 1;
  for (int i = 1; i < pow10.size(); ++i) {
    pow10[i] = (pow10[i - 1] * 10) % 41;
  }
}

bool is_divisible_by_41(int a0, int a1, int c, int n) {
  vector<int> a(n);
  a[0] = a0;
  a[1] = a1;

  for (int i = 2; i < n; ++i) {
    a[i] = (c * a[i - 1] + a[i - 2]) % 10;
  }

  int rem = 0;
  for (int i = 0; i < n; ++i) {
    rem = (rem + a[i] * pow10[n - i - 1]) % 41;
  }

  return rem == 0;
}

int main() {
  init_powers();

  int T;
  cin >> T;

  while (T--) {
    int a0, a1, c, n;
    cin >> a0 >> a1 >> c >> n;

    if (is_divisible_by_41(a0, a1, c, n)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
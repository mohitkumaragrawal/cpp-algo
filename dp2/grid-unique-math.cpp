#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

template <int sz = 1000001> struct factorial_gen {
  factorial_gen() {
    data[0] = 1;

    for (int i = 1; i < sz; ++i) {
      data[i] = (i * data[i - 1]) % MOD;
    }
  }

  long long operator()(int i) { return data[i]; }

private:
  long long data[sz];
};

long long binary_expo(long base, long pow) {
  long result = 1;
  while (pow > 0) {
    if (pow & 1)
      result = (result * base) % MOD;
    pow >>= 1;
    base = (base * base) % MOD;
  }
  return result;
}

long long inv_modulo(long num) { return binary_expo(num, MOD - 2); }

int main() {
  int T;
  cin >> T;

  factorial_gen<> factorial;

  while (T--) {
    int m, n;
    cin >> m >> n;

    auto ans = factorial(m + n - 2);
    ans = (ans * inv_modulo(factorial(m - 1))) % MOD;
    ans = (ans * inv_modulo(factorial(n - 1))) % MOD;

    cout << ans << endl;
  }
}

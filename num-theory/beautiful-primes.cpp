#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;

using ull = uint64_t;

ull binexp(ull base, ull pow, ull m) {
  ull result = 1;
  while (pow > 0) {
    if (pow & 1) {
      pow--;
      result = (result * base) % m;
    } else {
      base = (base * base) % m;
      pow /= 2;
    }
  }
  return result;
}

ull calc_divisor_sum(vector<ull>& primes, vector<ull>& powers, ull n) {
  ull result = 1;
  for (ull i = 0; i < n; ++i) {
    ull sum = 0;
    for (int j = 1; j <= powers[i]; ++j) {
      sum = (sum + binexp(primes[i], j, mod)) % mod;
    }
    result = (result * sum) % mod;
  }
  return result;
}

int main() {
  int t; cin >> t;
  while(t--) {
    ull n; cin >> n;
    vector<ull> primes(n), powers(n);
    for (auto i = 0; i < n; ++i) {
      cin >> primes[i];
    }
    for (auto i = 0; i < n; ++i) {
      cin >> powers[i];
    }
    cout << calc_divisor_sum(primes, powers, n);
  }
}

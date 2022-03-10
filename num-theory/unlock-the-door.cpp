#include <iostream>
#include <array>

using namespace std;

#define mod 1000000007
#define upper_limit 100001

using ull = uint64_t;

array<ull, upper_limit> fact;

ull binexp(ull base, ull pow) {
  ull result = 1;
  while (pow > 0) {
    if (pow & 1) {
      pow--;
      result = (result *  base) % mod;
    } else {
      pow /= 2;
      base = (base * base) % mod;
    }
  }
  return result;
}

ull inv_mod(ull n) {
  return binexp(n, mod - 2);
}

// (n!) / (n-r)!
ull permutation(ull n, ull r) {
  ull result = fact[n];
  result = (result * inv_mod(fact[n-r])) % mod;
  return result;
}

int main() {
  fact[0] = 1;
  for (int i = 1; i < upper_limit; ++i) {
    fact[i] = (i * fact[i-1]) % mod;
  }

  int t;
  cin >> t;
  while (t--) {
    ull n, k;
    cin >> n >> k;

    if (n == k) {
      cout << fact[n] << endl;
    } else
    cout << permutation(k, n) << endl;
  }
}
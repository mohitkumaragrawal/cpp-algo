#include <iostream>
using namespace std;

/**
 * Non-Deterministic primality test(meaning it will have some error).
 * because the converse of Fermat's little theorem is mostly true but not 
 * always. So we can detect whether a number is prime or not with a minimal
 * error but it runs faster than deterministic approach
 */

// we are using 64-bit integer;
using number = int64_t;

number mul_mod(number a, number b, number mod) {
  number result = 0;
  a %= mod;
  b %= mod;
  while (b > 0) {
    if (b & 1) {
      b--;
      result = (result + a) % mod;
    } else {
      b /= 2;
      a  = (a * 2) % mod;
    }
  }

  return result;
}

number bin_exp(number base, number power, number mod) {
  number result = 1;
  while (power > 0) {
    if (power & 1) {
      power--;
      result = mul_mod(result, base, mod);
    } else {
      power /= 2;
      base = mul_mod(base, base, mod);
    }
  }
  return result;
}

bool fermats_primailty_test(number p, int itr = 4) {
  if (p <= 4) {
    return (p == 2) || (p == 3);
  }
  while (itr--) {
    number base = 2 + rand() % (p - 3);
    if (bin_exp(base, p-1, p) != 1) return false;
  }
  return true;
}

int main() {
  while (true) {
    number p; cin >> p;
    if (fermats_primailty_test(p)) {
      cout << "fermat's prime" << endl;
    } else {
      cout << "composite" << endl;
    }
  }
}
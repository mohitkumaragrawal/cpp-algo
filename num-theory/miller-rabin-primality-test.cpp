#include <iostream>
#include <vector>

using namespace std;
using number = int64_t;

vector<int> millerBase32 = {2, 3, 5, 7};
vector<int> millerBase64 = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

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

number miller_rabin_primality_test(number p) {
  number prev = p - 1;
  
  // prev can be represented as (2 ** s). d where d is odd;
  number s = 0, d;
  while (prev % 2 == 0) {
    prev /= 2;
    s++;
  }
  d = prev;

  for (int base: millerBase64) {
    number t = bin_exp()
  }
}

#include <iostream>
#include <cmath>
using namespace std;

long binary_expo(long base, long pow, long mod) {
  long result= 1;
  while (pow > 0) {
    if (pow & 1) {
      pow--;
      result *= base;
      result %= mod;
    } else {
      pow >>= 1;
      base *= base;
      base %= mod;
    }
  }
  return result;
}

// using fermet's little theorem, we know
// a^(p-1) = a (mod p) where p is prime and, (a,p) are co-primes;
// or, a^(p-2) = a^(-1) (mod p);
long modulo_inverse(long a, long p) {
  return binary_expo((a%p), p-2, p) % p;
}

int main() {
  while (true) {
    long a, p;
    cin >> a >> p;
    cout << modulo_inverse(a, p) << endl;
  }
}
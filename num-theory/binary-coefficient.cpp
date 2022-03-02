#include <iostream>
#include <array>

#include "shared/factorial-generator.hpp"
#include "shared/binary-exponentiation.hpp"

#define MOD 1000000007

using namespace std;

factorial_generator<size_t, 100'008>  factorial;
binary_exponentiation<size_t>         bin_expo;

size_t modulo_inv(size_t a, size_t p) {
  auto exp = bin_expo(a, p-2);
  return exp % p;
}

size_t binary_coefficient(size_t n, size_t k) {
  if (k <= 0 || k >= n) return 0;
  auto n_fac = factorial(n), k_fac = factorial(k), nk_fac = factorial(n-k);
  auto tmp = (n_fac * modulo_inv(k_fac, MOD)) % MOD;
  return (tmp * modulo_inv(nk_fac, MOD)) % MOD;
}

int main() {
  cout << "Begins" << endl;

  while (true) {
    size_t n, k;
    cin >> n >> k;
    cout << binary_coefficient(n, k) << endl;
  }
  return 0;
}
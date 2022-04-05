#include <map>
#include <iostream>
#include <array>

#define UPPER_LIMIT 1000001
using namespace std;
using ull = uint64_t;

array<ull, UPPER_LIMIT> sieve;

map<ull, ull> prime_factorize(ull n) {
  map<ull, ull> result;
  if (n >= UPPER_LIMIT || n <= 1) return result;

  while(true) {
    if (sieve[n] == n) {
      result[n]++;
      break;
    }

    ull factor = n / sieve[n];
    result[factor]++;
    n = sieve[n];
  }
  return result;
}

void init_sieve() {
  for (ull i = 0; i < UPPER_LIMIT; ++i) {
    sieve[i] = i;
  }

  for (ull i = 2; i * i < UPPER_LIMIT; ++i) {
    if (sieve[i] != i) continue; // not prime;

    for (ull j = i*i; j < UPPER_LIMIT; j += i) {
      if (sieve[j] != j)  continue; // marked earlier;
      sieve[j] /= i;
    }
  }
}

ull phi(ull n, map<ull, ull>& pf) {
  ull result = n;

  for (auto pr: pf) {
    result = (result / pr.first) * (pr.first - 1);
  }
  return result;
}

ull divisors_count(ull n, map<ull, ull>& pf) { 
  ull result = 1;

  for (auto pr: pf) {
    result *= (pr.second + 1);
  }
  return result;
}

int main() {
  int Q;
  cin >> Q;
  init_sieve();

  while (Q--) {
    ull n;
    cin >> n;

    auto pf = prime_factorize(n);
    ull p = phi(n, pf);
    ull d = divisors_count(n, pf);

    ull result = n - p - d + 1;

    cout << result;
  }
}
#include <iostream>
#include <map>
#include <vector>
#include <array>
using namespace std;

#define UPPER_LIMIT 1000001
#define mod 1000000007

using ull = uint64_t;

// where n is less that 10^6
array<ull, UPPER_LIMIT> sieve;
array<ull, UPPER_LIMIT> factorial_array;

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

void init_fact() {
  factorial_array[0] = 1;
  factorial_array[1] = 1;

  for (ull i = 2; i <= UPPER_LIMIT; ++i) {
    factorial_array[i] = (i * factorial_array[i-1]) % mod;
  }
}


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

ull factorial(ull n) {
  if (n <= 1000000) {
    return factorial_array [n];
  }

  ull result = 1;
  for (ull i = 2; i <= n; ++i) {
    result = (result * i) % mod;
  }
  return result;
}

ull inverse_mod(ull a) {
  return binexp(a, (mod-2));
}

ull choose(ull n, ull r) {
  ull result = factorial(n);
  result = (result * inverse_mod(factorial(r))) % mod;
  result = (result * inverse_mod(factorial(n-r))) % mod;
  return result;
}


int main() {
  freopen("joseph-and-array.txt", "r", stdin);
  init_sieve();
  init_fact();

  ull n, k;
  cin >> n >> k;

  vector<ull> a(n);
  for (ull i = 0; i < n; ++i) cin >> a[i];

  ull ways = 1;

  map<ull, ull> pf;
  for (ull i = 0; i < n; ++i) {
    auto tmp = prime_factorize(a[i]);
    for (auto pr: tmp) {
      pf[pr.first] += pr.second;
    }
  }

  for (auto pr: pf) {
    ways = (ways * choose(pr.second + k - 1, k - 1)) % mod;
  }

  cout << ways << endl;
}
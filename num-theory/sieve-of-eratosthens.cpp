#include <iostream>
#include <vector>
#include <array>
#include <map>

using namespace std;

#define UPPER_LIMIT 100000

struct SieveOfEratostens {
  SieveOfEratostens() {
    cout << "INIT" << endl;
    init_sieve();
  }

  // where n is less that 10^6
  map<int, int> prime_factorize(int n) {
    map<int, int> result;
    if (n >= UPPER_LIMIT || n <= 1) return result;

    while(true) {
      if (sieve[n] == n) {
        result[n]++;
        break;
      }

      int factor = n / sieve[n];
      result[factor]++;
      n = sieve[n];
    }
    return result;
  }
private:
  array<int, UPPER_LIMIT> sieve;

  void init_sieve() {
    for (int i = 0; i < UPPER_LIMIT; ++i) {
      sieve[i] = i;
    }

    for (int i = 2; i * i < UPPER_LIMIT; ++i) {
      if (sieve[i] != i) continue; // not prime;

      for (int j = i*i; j < UPPER_LIMIT; j += i) {
        if (sieve[j] != j)  continue; // marked earlier;
        sieve[j] /= i;
      }
    }
  }
};

void printPrimeFactorization(const map<int, int>& pf) {
  if (pf.empty()) return;

  for (auto el: pf) {
    cout << el.first << "^" << el.second << " ";
  } cout << endl;
}

int main() {
  SieveOfEratostens sieve;
  cout << "H" << endl;

  while (true) {
    int n; cin >> n;
    auto factoriaztion = sieve.prime_factorize(n);
    printPrimeFactorization(factoriaztion);
  }
}
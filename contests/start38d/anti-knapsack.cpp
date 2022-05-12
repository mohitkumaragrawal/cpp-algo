#include <array>
#include <iostream>

using namespace std;

array<bool, 20001> sieve;

void init_sieve() {
  for (int i = 0; i < sieve.size(); ++i) sieve[i] = true;
  sieve[0] = sieve[1] = false;

  for (int i = 2; i * i < sieve.size(); ++i) {
    if (!sieve[i]) continue;

    for (int j = i * i; j < sieve.size(); j += i) {
      sieve[j] = false;
    }
  }
}

int main() {
  init_sieve();

  int T;
  cin >> T;

  while (T--) {
    int N, K;
    cin >> N >> K;

    // find a prime that is not a factor of k;

    int p;
    for (int i = 2; i < sieve.size(); ++i) {
      if (!sieve[i]) continue;

      if (K % i != 0) {
        p = i;
        break;
      }
    }

    for (int i = 1; i <= N; ++i) {
      cout << i * p << " ";
    }
    cout << endl;
  }
}
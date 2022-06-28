#include <iostream>
using namespace std;

bool prime[1000001];
int prime_counter[1000001];

bool pp[1000001];
int pp_counter[1000001];

void init_sieve() {
  prime[0] = prime[1] = false;
  for (int i = 2; i <= 1000000; ++i) {
    prime[i] = true;
  }

  for (int i = 2; i * i <= 1000000; ++i) {
    if (!prime[i]) continue;
    for (int j = i * i; j <= 1000000; j += i) {
      prime[j] = false;
    }
  }

  prime_counter[0] = 0;
  for (int i = 1; i <= 1000000; ++i) {
    if (prime[i])
      prime_counter[i] = 1 + prime_counter[i - 1];
    else
      prime_counter[i] = prime_counter[i - 1];
  }

  for (int i = 0; i <= 1000000; ++i) {
    pp[i] = prime[prime_counter[i]];
  }

  pp_counter[0] = 0;
  for (int i = 1; i <= 1000000; ++i) {
    if (pp[i]) {
      pp_counter[i] = 1 + pp_counter[i - 1];
    } else {
      pp_counter[i] = pp_counter[i - 1];
    }
  }
}

int main() {
  init_sieve();
  int T;
  cin >> T;

  while (T--) {
    int L, R;
    cin >> L >> R;

    cout << pp_counter[R] - pp_counter[L - 1] << endl;
  }
}
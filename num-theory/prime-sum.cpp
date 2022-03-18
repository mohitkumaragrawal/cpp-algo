#include <iostream>
#include <array>
#define max_size 1000001

using namespace std;
using ull = uint64_t;

array<int, max_size> sieve;
void init_sieve() {
  sieve[0] = sieve[1] = 1;
  for (int i = 2; i*i < max_size; ++i) {
    if (sieve[i] != 0) continue;  
    for (int j = i*i; j < max_size; j+=i) {
      if (j == 5) {
        cout << i << endl;
      }
      sieve[j] = 1;
    }
  }
}

array<ull, max_size> sum_array;
void init_sum() {
  sum_array[0] = sum_array[1] = 0;

  for (int i = 2; i < max_size; ++i) {
    sum_array[i] = sum_array[i-1];
    if (sieve[i] == 0) {
      sum_array[i] += i;
    }
  }
}

int main() {
  init_sieve();
  init_sum();

  int t; cin >> t;
  while(t--) {
    int l, r;
    cin >> l >> r;

    ull result = sum_array[r] - sum_array[l-1];
    cout << result << endl;
  }
}
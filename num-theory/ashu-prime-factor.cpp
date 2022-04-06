#include <array>
#include <iostream>

using namespace std;

// min_prime[j] is the minimum prime factor of j;
array<int, 1000001> min_prime;

void init_sieve() {
  min_prime[0] = min_prime[1] = 0;
  for (int i = 2; i < min_prime.size(); ++i) {
    min_prime[i] = i;
  }
  for (int i = 2; i * i < min_prime.size(); ++i) {
    if (min_prime[i] != i) continue;
    for (int j = i * i; j < min_prime.size(); j += i) {
      if (min_prime[j] != j) continue;
      min_prime[j] = i;
    }
  }
}

array<int, 1000001> ans;
void init_answers() {
  for (int i = 0; i < ans.size(); ++i) ans[i] = 0;

  for (int i = 0; i < min_prime.size(); ++i) {
    ans[min_prime[i]]++;
  }
}

int main() {
  init_sieve();
  init_answers();
  int T;
  cin >> T;
  while (T--) {
    int X;
    cin >> X;
    cout << ans[X] << endl;
  }
}
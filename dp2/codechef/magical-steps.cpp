#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;

  vector<bool> is_prime(10000001, true);
  const auto sz = is_prime.size();
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i * i < is_prime.size(); ++i) {
    if (!is_prime[i]) continue;

    for (int j = i * i; j < is_prime.size(); j += i) {
      is_prime[j] = false;
    }
  }

  vector<int> prime_counter(sz);
  prime_counter[0] = 0;
  for (int i = 1; i < sz; ++i) {
    if (is_prime[i]) {
      prime_counter[i] = 1 + prime_counter[i - 1];
    } else {
      prime_counter[i] = prime_counter[i - 1];
    }
  }

  while (T--) {
    int X, Y;
    cin >> X >> Y;
    int ans = (Y - X) - (prime_counter[Y] - prime_counter[X + 1]);
    cout << ans << endl;
  }
}
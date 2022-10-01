#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

vector<bool> sieve;

void init_sieve() {
  sieve.assign(10000001, true);
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
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll N, K;
  cin >> N >> K;

  vector<ll> arr(N);
  for (ll &i : arr) {
    cin >> i;
    i = !!sieve[i];
  }

  ll ans = 0;
  ll l = 0, r = 0, sum = arr[l];

  while (r < N - 1 && sum + arr[r + 1] <= K) {
    r++;
    sum += arr[r];
  }
  ans += (r - l + 1);
  for (l = 1; l < N; ++l) {
    sum -= arr[l - 1];

    while (r < N - 1 && sum + arr[r + 1] <= K) {
      r++;
      sum += arr[r];
    }
    ans += (r - l + 1);
  }

  cout << ans << endl;
}
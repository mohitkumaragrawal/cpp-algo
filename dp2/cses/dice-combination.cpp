#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e+9 + 7;

int main() {
  ll N;
  cin >> N;

  vector<ll> arr(1000001);
  arr[0] = 1;

  for (ll i = 1; i <= N; ++i) {
    for (ll j = 1; j <= 6; ++j) {
      if (i - j < 0) break;
      arr[i] += arr[i - j];

      if (arr[i] > MOD << 6) {
        arr[i] %= MOD;
      }
    }
  }
  cout << arr[N] % MOD << endl;
}
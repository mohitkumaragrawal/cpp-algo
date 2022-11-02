#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MAX = 10000005;

ll divisor_sum[MAX], sq_divisor_sum[MAX];

void solve() {
  ll n;
  cin >> n;
  cout << ((divisor_sum[n] * divisor_sum[n]) - sq_divisor_sum[n]) / 2 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  for (ll i = 1; i < MAX; ++i) {
    for (ll j = i; j < MAX; j += i) {
      divisor_sum[j] += i;
      sq_divisor_sum[j] += i * i;
    }
  }
  ll T;
  cin >> T;
  while (T--) solve();
}

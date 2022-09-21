#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll calc_rank(ll num) {
  ll evens = 0;
  if (num >= 8) {
    evens = (num - 4) / 4;
  }
  ll odds = (num - 1) / 2;

  return evens + odds;
}

int main() {
  ll n;
  cin >> n;

  ll low = 3, high = 1e+11;
  ll ans = 0;

  while (high >= low) {
    ll mid = (low + high) / 2;

    ll rank = calc_rank(mid);
    if (rank >= n) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout << ans << endl;
}
#include <algorithm>
#include <iostream>
using namespace std;

using ll = long long;

void solve() {
  ll n, t1, t2;
  cin >> n >> t1 >> t2;

  ll low = 0, high = 1e9, x = high, y;

  // x = number of solutions generated by alice;
  while (low <= high) {
    ll mid = (low + high) / 2;
    ll y = mid * t1 / t2;
    if (mid + y >= n) {
      x = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }
  low = 0, high = 1e9, y = high;

  // y is the number of solutions generated by bob;
  while (low <= high) {
    ll mid = (low + high) / 2;
    ll x = mid * t2 / t1;
    if (mid + x >= n) {
      y = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }
  ll t = max(x * t1, y * t2);
  cout << min(n + 1, t / t1 + t / t2) << ' ' << t << '\n';
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    solve();
  }
}
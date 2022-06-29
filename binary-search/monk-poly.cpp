#include <iostream>
using namespace std;

using ll = long long;

int main() {
  ll T;
  cin >> T;
  while (T--) {
    ll A, B, C, K;
    cin >> A >> B >> C >> K;

    ll low = 0;
    ll high = 1;

    auto poly = [&](ll x) -> ll { return A * x * x + B * x + C; };

    while (poly(high) < K) {
      low = high + 1;
      high = high * 2;
    }

    ll ans = high;
    while (true) {
      if (low > high) break;

      ll mid = low + (high - low) / 2;

      if (poly(mid) < K) {
        // go higher;
        low = mid + 1;
      } else {
        ans = mid;
        // go lower;
        high = mid - 1;
      }
    }

    cout << ans << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll f[33];

void solve() {
  int N;
  cin >> N;

  fill(begin(f), end(f), 0);
  for (int i = 0; i < N; ++i) {
    ll x;
    cin >> x;

    ll cnt = 0;
    while (x > 0) {
      x /= 2;
      cnt++;
    }
    f[cnt]++;
  }

  ll ans = 0;
  for (int i = 0; i <= 32; ++i) {
    ans += (f[i] * (f[i] - 1)) / 2;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) solve();
}
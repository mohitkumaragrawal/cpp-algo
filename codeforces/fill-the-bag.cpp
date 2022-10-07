#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;

using ll = long long;

ll N, M, f[100];

ll lg(ll n) {
  ll ans = 0;
  while (n > 1) {
    ans++;
    n >>= 1;
  }
  return ans;
}

void solve() {
  cin >> N >> M;
  fill(all(f), 0);

  ll total_sum = 0;
  for (int i = 0; i < M; ++i) {
    ll x;
    cin >> x;
    total_sum += x;

    f[lg(x)]++;
  }

  if (total_sum < N) {
    cout << -1 << endl;
    return;
  }

  ll ans = 0;

  for (ll i = 0; i < 63; ++i) {
    ll mask = (1LL << i);

    if (!(N & mask)) {
      continue;
    }

    if (f[i]) {
      f[i]--;

      continue;
    }

    ll sum = 0;
    int j = 0;
    while (sum < mask && j < i) {
      sum += f[j] * (1 << j);
      j++;
    }

    if (sum >= mask) {
      for (int k = 0; k < j; ++k) f[k] = 0;
      f[0] = (sum - mask);

      continue;
    }

    // now split something to fulfill this :)
    j = i + 1;
    while (f[j] == 0) j++;

    for (int k = j; k > i; --k) {
      f[k]--;
      f[k - 1] += 2;

      ans++;
    }
    f[i]--;
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
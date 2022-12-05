#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

ll n;
ll arr[500005];
ll freq[65];

ll calc_and(ll c) {
  ll res = 0;

  for (ll j = 0; j < 60; ++j) {
    if ((c >> j) & 1) {
      ll place = (1LL << j) % MOD;
      res = (res + freq[j] * place) % MOD;
    }
  }
  return res;
}

ll calc_or(ll c) {
  ll res = 0;

  for (ll j = 0; j < 60; ++j) {
    ll place = (1LL << j) % MOD;
    ll f = ((c >> j) & 1) ? n : freq[j];

    res = (res + f * place) % MOD;
  }
  return res;
}

void solve() {
  cin >> n;

  memset(freq, 0, sizeof(freq));

  for (ll i = 0; i < n; ++i) {
    cin >> arr[i];
    for (ll j = 0; j < 60; ++j) {
      if ((arr[i] >> j) & 1) {
        freq[j]++;
      }
    }
  }

  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    ans = (ans + calc_and(arr[i]) * calc_or(arr[i])) % MOD;
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

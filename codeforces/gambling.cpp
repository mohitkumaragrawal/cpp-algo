#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll a_old[200005], a[200005], dp[200005], last_idx[200005], left_idx[200005];
ll N;

void solve() {
  cin >> N;
  for (ll i = 0; i < N; ++i) cin >> a_old[i];

  // Compress [1, 1e9] to [0, 1e5];

  map<ll, ll> comp;
  ll x = -1;
  for (ll i = 0; i < N; ++i) {
    if (comp.find(a_old[i]) == comp.end()) {
      comp[a_old[i]] = ++x;
    }
  }
  for (ll i = 0; i < N; ++i) {
    a[i] = comp[a_old[i]];
  }

  // Reset the value of dp, and the value of last_idx;

  fill(dp, dp + N, 1);
  fill(last_idx, last_idx + comp.size(), -1);

  // Calculate the value!

  for (ll i = 0; i < N; ++i) {
    ll val = a[i];

    left_idx[i] = i;

    if (last_idx[val] != -1) {
      ll j = last_idx[val];
      ll new_val = dp[j] + 1 - (i - j - 1);

      if (new_val > 1) {
        dp[i] = new_val;
        left_idx[i] = left_idx[j];
      }
    }

    last_idx[val] = i;
  }

  // Find the answer;

  ll ans = 1;
  ll right = 0;
  for (ll i = 0; i < N; ++i) {
    if (ans < dp[i]) {
      right = i;
      ans = dp[i];
    }
  }

  // Reconstruct the answer from the dp and output;

  ll left = left_idx[right];
  cout << a_old[right] << " " << left + 1 << " " << right + 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

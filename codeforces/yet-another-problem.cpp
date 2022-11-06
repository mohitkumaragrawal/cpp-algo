#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using namespace std;
using ll = long long;
using ull = unsigned long long;

ll arr[200005], pre_x[200005], zero_cnt[200005];
map<pair<ll, ll>, vector<ll>> mp;

ll N, Q;

ll calc_xor(ll left, ll right) {
  ll val = pre_x[right];
  if (left > 0) {
    val ^= pre_x[left - 1];
  }
  return val;
}

ll calc_moves(ll L, ll R) {
  ll length = R - L + 1;

  ll z_cnt = zero_cnt[R];
  if (L > 0) {
    z_cnt -= zero_cnt[L - 1];
  }
  if (z_cnt == length) {
    return 0;
  }

  ll val = calc_xor(L, R);
  if (val != 0) {
    return -1;
  }
  if (length & 1) {
    return 1;
  }

  if (arr[L] == 0 || arr[R] == 0) return 1;

  ll x = (L > 0) ? pre_x[L - 1] : 0;
  auto& vec = mp[{x, (L % 2)}];

  auto itr = lower_bound(all(vec), L);
  if (itr == vec.end()) return -1;

  if (*itr < R) {
    return 2;
  } else {
    return -1;
  }
}

void solve() {
  cin >> N >> Q;

  for (ll i = 0; i < N; ++i) cin >> arr[i];

  pre_x[0] = arr[0];
  for (ll i = 1; i < N; ++i) {
    pre_x[i] = pre_x[i - 1] ^ arr[i];
  }

  zero_cnt[0] = (arr[0] == 0) ? 1 : 0;
  for (ll i = 1; i < N; ++i) {
    zero_cnt[i] = zero_cnt[i - 1] + ((arr[i] == 0) ? 1 : 0);
  }

  for (ll i = 0; i < N; ++i) {
    ll val = pre_x[i];
    ll pr = i % 2;
    mp[{val, pr}].push_back(i);
  }

  while (Q--) {
    ll L, R;
    cin >> L >> R;
    L--;
    R--;

    cout << calc_moves(L, R) << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}

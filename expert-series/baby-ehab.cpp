#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll n;
ll arr[105];

ll calc_pow2(ll x) {
  ll ans = 0;
  while (x > 0 && x % 2 == 0) {
    ans++;
    x /= 2;
  }
  return ans;
}

void solve() {
  cin >> n;

  for (ll i = 0; i < n; ++i) cin >> arr[i];

  ll sum = 0;
  for (ll i = 0; i < n; ++i) {
    sum += arr[i];
  }

  if (sum % 2 == 1) {
    cout << 0 << endl;
    return;
  }

  bitset<200005> psum;
  psum[0] = 1;

  for (ll i = 0; i < n; ++i) {
    psum |= (psum << arr[i]);
  }

  if (!psum[sum / 2]) {
    cout << 0 << endl;
    return;
  }

  // remove the element with least power of 2;
  vector<ll> pow2(n);
  for (ll i = 0; i < n; ++i) {
    pow2[i] = calc_pow2(arr[i]);
  }

  ll id = min_element(all(pow2)) - pow2.begin() + 1;
  cout << 1 << endl;
  cout << id << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  solve();
}

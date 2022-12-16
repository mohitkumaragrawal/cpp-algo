#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll a[100005];
ll n, q;

// going upto 'x' giving low difficulty contests and then doing every contest
// proceeding;
bool check(ll x) {
  ll qq = q;
  for (ll i = x; i < n; ++i) {
    if (qq == 0) return false;
    if (a[i] > qq) {
      qq--;
    }
  }
  if (qq < 0) return false;

  return true;
}

void solve() {
  cin >> n >> q;

  for (ll i = 0; i < n; ++i) cin >> a[i];

  ll ans_idx = n - 1, low = 0, high = n - 1;
  while (low <= high) {
    ll mid = (low + high) / 2;
    if (check(mid)) {
      ans_idx = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  for (ll i = 0; i < ans_idx; ++i) {
    if (a[i] > q) {
      cout << '0';
    } else {
      cout << '1';
    }
  }
  for (ll i = ans_idx; i < n; ++i) {
    cout << '1';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

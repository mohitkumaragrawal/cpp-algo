#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll n, a[300005], right_exp[300005], left_exp[300005];

ll series_sum(ll start, ll count) {
  return start * count - count * (count - 1) / 2;
}

void solve() {
  cin >> n;
  for (ll i = 0; i < n; i++) cin >> a[i];

  left_exp[0] = a[0];
  vector<ll> st;
  st.push_back(0);

  for (ll i = 1; i < n; ++i) {
    while (!st.empty() && a[st.back()] > a[i] - (i - st.back())) {
      st.pop_back();
    }
    if (st.empty()) {
      left_exp[i] = series_sum(a[i], min(i + 1, a[i]));
    } else {
      ll j = st.back();
      left_exp[i] = series_sum(a[i], i - j) + left_exp[st.back()];
    }
    st.push_back(i);
  }

  right_exp[n - 1] = a[n - 1];
  st.clear();
  st.push_back(n - 1);

  for (ll i = n - 2; i >= 0; --i) {
    while (!st.empty() && a[st.back()] > a[i] - (st.back() - i)) {
      st.pop_back();
    }
    if (st.empty()) {
      right_exp[i] = series_sum(a[i], min(n - i, a[i]));
    } else {
      ll j = st.back();
      right_exp[i] = series_sum(a[i], j - i) + right_exp[st.back()];
    }
    st.push_back(i);
  }

  ll total = accumulate(a, a + n, 0LL);
  ll ans = total;

  for (ll i = 0; i < n; ++i) {
    ll cost = a[i] + (total - left_exp[i] - right_exp[i] + a[i]);
    ans = min(ans, cost);
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#ifdef _DEBUG
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  for (auto x : v) out << x << " ";
  return out;
}

void solve() {
  ll n;
  cin >> n;

  map<ll, vector<ll>> I;
  ll mx = 0;

  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x;

    I[x].push_back(i);
    mx = max(mx, x);
  }

  vector<ll> ans(n, mx);

  set<ll> sid;
  multiset<ll> diff;

  sid.insert(-1);
  sid.insert(n);
  diff.insert(n);

  for (auto& [x, vec] : I) {
    for (auto y : vec) {
      auto it = sid.lower_bound(y);
      ll y_bg = *it;
      it--;
      ll y_sm = *it;

      diff.erase(diff.lower_bound(y_bg - y_sm - 1));
      sid.insert(y);

      diff.insert(y_bg - y - 1);
      diff.insert(y - y_sm - 1);
    }

    ll mx_seg = *(--diff.end());

    ans[mx_seg] = min(ans[mx_seg], x);
  }

  ll mn = ans[0];
  for (ll i = 1; i < n; ++i) {
    mn = min(mn, ans[i]);
    ans[i] = mn;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

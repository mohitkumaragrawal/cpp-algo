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

void solve() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  vector<ll> d(n);
  for (ll i = 0; i < n; ++i) cin >> d[i];

  if (s[0] == 'B') {
    cout << -1 << endl;
    return;
  }

  ll ans = 0;
  ll tmp = -1;
  ll max_r = -1;

  for (ll i = 0; i < n; ++i) {
    if (s[i] == 'B' && i > max_r) {
      if (tmp >= i) {
        ans++;
        max_r = max(max_r, tmp);
        tmp = max(tmp, i + d[i]);
      } else {
        dbg(tmp, i);
        cout << -1 << endl;
        return;
      }
    } else {
      // max_r = max(max_r, i + d[i]);
      tmp = max(tmp, i + d[i]);
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

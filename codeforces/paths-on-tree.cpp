#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

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

map<pair<ll, ll>, ll> mp;
ll n, k;
ll s[200005];
vector<vector<ll>> G;

ll f(ll u, ll x) {
  if (mp.find({u, x}) != mp.end()) {
    return mp[{u, x}];
  }

  ll child_cnt = G[u].size();

  if (child_cnt == 0) {
    return s[u] * x;
  }

  ll t = x / child_cnt;

  if (x % child_cnt == 0) {
    ll ans = s[u] * x;
    for (ll ch : G[u]) ans += f(ch, t);

    mp[{u, x}] = ans;

    return ans;
  }

  ll dp1[child_cnt], dp2[child_cnt], diff[child_cnt];

  for (ll i = 0; i < child_cnt; ++i) {
    dp1[i] = f(G[u][i], t);
    dp2[i] = f(G[u][i], t + 1);

    diff[i] = dp2[i] - dp1[i];
  }

  ll ans = s[u] * x;
  for (ll i = 0; i < child_cnt; ++i) {
    ans += dp1[i];
  }

  ll extra = x % child_cnt;
  sort(diff, diff + child_cnt, greater<ll>());

  for (ll i = 0; i < extra; ++i) ans += diff[i];

  mp[{u, x}] = ans;
  return ans;
}

void solve() {
  cin >> n >> k;
  G.resize(n);

  for (ll i = 1; i < n; ++i) {
    ll p;
    cin >> p;
    p--;
    G[p].push_back(i);
  }

  for (ll i = 0; i < n; ++i) cin >> s[i];

  ll ans = f(0, k);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) {
    G.clear();
    mp.clear();

    solve();
  }
}

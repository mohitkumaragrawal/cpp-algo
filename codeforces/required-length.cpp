#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll INF = 9999999999999;

ll n, val;
map<ll, ll> dp;

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

ll op = 0;

ll req_length(ll x) {
  if (dp.find(x) != dp.end()) return dp[x];
  op++;

  string x_str = to_string(x);
  ll ans = INF;
  ll sz = x_str.size();

  if (sz == n) return 0;
  if (sz > n) return INF;

  set<ll> dig;
  for (char ch : x_str) {
    dig.insert(ch - '0');
  }

  for (ll d : dig) {
    if (d <= 1) continue;
    ans = min(ans, 1 + req_length(x * d));
  }

  return dp[x] = ans;
}

void solve() {
  cin >> n >> val;

  ll ans = req_length(val);
  cout << (ans == INF ? -1 : ans) << endl;

  dbg(op);
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

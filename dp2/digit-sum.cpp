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

ll p10[16];

ll digit_sum(ll x) {
  if (x == -1) return 0;
  ll dp[16][2];
  for (ll i = 0; i < 16; ++i) {
    dp[i][0] = dp[i][1] = -1;
  }

  vector<int> d;

  {
    ll i = x;
    while (i > 0) {
      d.push_back(i % 10);
      i /= 10;
    }
  }

  function<ll(ll, ll)> dp_calc = [&](ll n, int s) -> ll {
    if (n == -1) return 0LL;
    if (dp[n][s] != -1) return dp[n][s];

    ll s_cnt = (x % p10[n]) + 1;
    ll ns_cnt = p10[n];

    if (s == 0) {
      ll val = 0;
      for (ll i = 0; i <= 9; ++i) {
        val += ns_cnt * i + dp_calc(n - 1, 0);
      }

      return dp[n][s] = val;
    } else {
      ll val = 0;
      for (ll i = 0; i < d[n]; ++i) {
        val += ns_cnt * i + dp_calc(n - 1, 0);
      }
      val += s_cnt * d[n] + dp_calc(n - 1, 1);

      return dp[n][s] = val;
    }
  };

  dp_calc(d.size() - 1, 1);
  return dp[d.size() - 1][1];
}

void solve() {
  p10[0] = 1;
  for (ll i = 1; i < 16; ++i) p10[i] = 10 * p10[i - 1];

  ll l, r;
  cin >> l >> r;

  cout << digit_sum(r) - digit_sum(l - 1) << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

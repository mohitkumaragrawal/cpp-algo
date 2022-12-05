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

const ll MOD = 1e9 + 7;

ll pow2[100005];
void precomputation() {
  pow2[0] = 1;
  for (ll i = 1; i < 100005; ++i) {
    pow2[i] = (2 * pow2[i - 1]) % MOD;
  }
}

int dp[75][1 << 19];
ll c[75];

void solve() {
  vector<ll> primes = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29,
                       31, 37, 41, 43, 47, 53, 59, 61, 67};

  ll n;
  cin >> n;
  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    c[x]++;
  }

  dp[0][0] = 1;
  for (ll i = 0; i < 70; ++i) {
    ll val = i + 1;
    ll xr_val = 0;

    for (ll a = 0; a < primes.size(); ++a) {
      ll cnt = 0;
      while (val % primes[a] == 0) {
        cnt++;
        val /= primes[a];
      }
      if (cnt & 1) {
        xr_val |= (1 << a);
      }
    }

    for (ll j = 0; j < (1 << 19); ++j) {
      if (c[i + 1] == 0) {
        dp[i + 1][j] = (dp[i][j] + dp[i + 1][j]) % MOD;
        continue;
      }

      ll val1 = (dp[i][j] * pow2[c[i + 1] - 1]) % MOD;
      dp[i + 1][j] = (val1 + dp[i + 1][j]) % MOD;
      dp[i + 1][j ^ xr_val] = (val1 + dp[i + 1][j ^ xr_val]) % MOD;
    }
  }

  cout << dp[70][0] - 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  precomputation();
  solve();
}

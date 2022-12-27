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

ll n, k;
tuple<ll, ll, ll> visitors[1005];
tuple<ll, ll> table[1005];

ll dp[1005][1005];

// pair<ll, ll> parent[1005][1005];

ll parent_x[1005][1005];
ll parent_y[1005][1005];

void solve() {
  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    ll c, p;
    cin >> c >> p;

    visitors[i] = {c, p, i};
  }
  cin >> k;

  for (ll i = 1; i <= k; ++i) {
    ll x;
    cin >> x;

    table[i] = {x, i};
  }

  sort(visitors + 1, visitors + n + 1);
  sort(table + 1, table + k + 1);

  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < k; ++j) {
      // dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (dp[i + 1][j] < dp[i][j]) {
        dp[i + 1][j] = dp[i][j];

        parent_x[i + 1][j] = i;
        parent_y[i + 1][j] = j;
      }

      for (ll x = j + 1; x <= k; ++x) {
        auto [sz, _1] = table[x];
        auto [c, p, _2] = visitors[i + 1];

        dbg(sz, c, p, x);

        if (sz >= c) {
          // dp[i + 1][x] = max(dp[i + 1][x], dp[i][j] + p);

          if (dp[i][j] + p > dp[i + 1][x]) {
            dp[i + 1][x] = dp[i][j] + p;
            // parent[i + 1][x] = {i, j};

            parent_x[i + 1][x] = i;
            parent_y[i + 1][x] = j;
          }

          break;
        }
      }
    }
  }

  ll ans = 0;

  // for (ll i = 0; i <= n; ++i) {
  //   for (ll j = 0; j <= k; ++j) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << '\n';
  // }

  ll px = 0;
  ll py = 0;

  // for (ll i = 1; i <= k; ++i) {
  //   // ans = max(ans, dp[n][i]);
  //   if (dp[n][i] > ans) {
  //     ans = dp[n][i];
  //     last_table = i;
  //   }
  // }

  for (ll i = 1; i <= n; ++i) {
    for (ll j = 1; j <= k; ++j) {
      if (ans < dp[i][j]) {
        px = i;
        py = j;
        ans = dp[i][j];
      }
    }
  }

  vector<pair<ll, ll>> vpr;

  // cout << parent_x[3][2] << " " << parent_y[3][2] << endl;

  while (px != 0 || py != 0) {
    dbg("before", px, py);

    ll new_px = parent_x[px][py];
    ll new_py = parent_y[px][py];

    if (new_py != py) {
      dbg(px, py);
      vpr.push_back({px, py});
    }

    px = new_px;
    py = new_py;

    dbg("after", px, py);
  }

  cout << vpr.size() << " " << ans << '\n';
  for (auto [a, b] : vpr) {
    ll a_idx = get<2>(visitors[a]);
    ll b_idx = get<1>(table[b]);
    cout << a_idx << " " << b_idx << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

struct min_op {
  ll operator()(ll a, ll b) { return min(a, b); }
};
template <typename OperationT>
struct sparse_table {
  vector<vector<ll>> m;
  OperationT op;
  template <typename Itr>
  void init(Itr begin, Itr end) {
    ll sz = end - begin;
    ll lg = 63 - __builtin_clzll(sz);
    m.assign(sz, vector<ll>(lg + 1));
    for (ll j = 0; j <= lg; ++j) {
      ll len = (1 << j);
      for (ll i = 0; i + len - 1 < sz; ++i) {
        if (len == 1) {
          m[i][j] = *(begin + i);
        } else {
          m[i][j] = op(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
        }
      }
    }
  }
  ll query(ll L, ll R) {
    ll j = 63 - __builtin_clzll((R - L + 1));
    return op(m[L][j], m[R + 1 - (1 << j)][j]);
  }
};

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
  ll n, k, x;
  cin >> n >> k >> x;

  if (x < 0) {
    x = -x;
    k = n - k;
  }

  vector<ll> add_x(n + 1), sub_x(n + 1);
  for (ll i = 1; i <= n; ++i) {
    ll t;
    cin >> t;

    add_x[i] = t + x;
    sub_x[i] = t - x;
  }

  for (ll i = 1; i <= n; ++i) {
    add_x[i] += add_x[i - 1];
    sub_x[i] = max(0LL, sub_x[i] + sub_x[i - 1]);
  }

  ll ans = 0;

  // CASE 1: size of subarray >= k;

  for (ll i = 1; i <= n; ++i) {
    ll j = i - k + 1;
    if (j <= 0) continue;

    ll sm = add_x[i] - add_x[j - 1] + sub_x[j - 1];
    ans = max(ans, sm);
  }

  if (k > 0) {
    sparse_table<min_op> spt;
    spt.init(all(add_x));

    for (ll i = 1; i <= n; ++i) {
      ll j = max(-1LL, i - k);

      ans = max(ans, add_x[i] - spt.query(j + 1, i - 1));
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

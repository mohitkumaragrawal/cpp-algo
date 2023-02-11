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

ll n, k, A, B;
ll a[100005];

// find the no. of avengers whose position is <= x;
ll f(ll x) { return upper_bound(a, a + k, x) - a; }

ll optimize_region(ll l, ll r) {
  dbg(l, r);
  if (l > r) return 0;

  ll av = f(r) - f(l - 1);
  dbg(av);
  if (av == 0) return A;

  if (l == r) {
    return B * av;
  }

  ll ans1 = B * (r - l + 1) * av;

  ll mid = (l + r) / 2;
  ll ans2 = optimize_region(l, mid) + optimize_region(mid + 1, r);

  return min(ans1, ans2);
}

void solve() {
  cin >> n >> k >> A >> B;
  for (ll i = 0; i < k; ++i) cin >> a[i];

  sort(a, a + k);

  dbg("sorted");

  ll ans = optimize_region(1, (1 << n));
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}

// . . + + - . . . - - . . . + .
// 0 0 1 2 1 0 0 0-1-2 0 0 0 1 0
// 2 1 2 3 2 1 2 3 2 1 2 3 1 2 1

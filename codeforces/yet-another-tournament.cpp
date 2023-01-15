#include <bits/stdc++.h>
using namespace std;

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
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll n, m;
ll score[500005], p[500005];

bool compare(const pll& a, const pll& b) { return a.first < b.first; }

void solve() {
  cin >> n >> m;

  vector<pll> vp;

  for (ll i = 1; i <= n; ++i) score[i] = i;

  ll points = 0;

  for (ll i = 1; i <= n; ++i) {
    ll x;
    cin >> x;

    p[i] = x;

    if (x == 0) {
      score[i]--;
      points++;
      continue;
    }

    vp.push_back({x, i});
  }

  sort(all(vp));

  ll idx = 0;

  ll mx = 0;
  while (m > 0 && idx < n) {
    auto [prep, pos] = vp[idx];
    idx++;

    if (prep > m) break;
    m -= prep;

    mx = max(prep, mx);

    score[pos]--;
    points++;
  }

  ll rank = 0;

  if (points != n && score[points + 1] == points) rank = -1;

  if (points != n && score[points + 1] == points + 1) {
    if (mx + m >= p[points + 1]) {
      score[points + 1]--;
      rank = -1;
    }
  }

  rank += n - points + 1;
  cout << rank << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

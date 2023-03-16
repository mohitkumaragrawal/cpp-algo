#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  vector<ll> d(n);
  for (ll i = 0; i < n; ++i) cin >> d[i];

  vector<ll> B;
  for (ll i = 0; i < n; ++i) {
    if (s[i] == 'B') B.push_back(i);
  }
  reverse(all(B));

  vector<pll> vpr;
  for (ll i = 0; i < n; ++i) {
    if (s[i] == 'R' && d[i] > 0) {
      vpr.emplace_back(i + d[i], i + 1);
    }
  }

  if (B.empty()) {
    cout << 0 << endl;
    return;
  }

  if (vpr.empty()) {
    cout << -1 << endl;
    return;
  }

  sort(all(vpr));

  ll done = n + 1;
  ll ans = 0;

  ll final = vpr.size();

  for (auto idx : B) {
    if (idx >= done) continue;

    auto id = lower_bound(all(vpr), make_pair(idx, -1LL)) - vpr.begin();

    if (id >= vpr.size()) {
      cout << -1 << endl;
      return;
    }

    if (id >= final) {
      cout << -1 << endl;
      return;
    }

    ll min_lower = n + 1;
    ll nf = final;
    for (ll i = id; i < final; ++i) {
      if (vpr[i].second < min_lower) {
        min_lower = vpr[i].second;
        nf = i;
      }
    }

    if (min_lower > idx) {
      cout << -1 << endl;
      return;
    }

    final = nf;
    done = min_lower;
    ans++;
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

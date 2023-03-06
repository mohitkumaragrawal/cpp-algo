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

  vector<vector<ll>> adj(n + 1);
  for (ll i = 0; i < n - 1; i++) {
    ll u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  ll c = 0;
  map<vector<ll>, ll> mp;
  vector<ll> id(n + 1, 0);
  vector<bool> sym(n + 1, false);

  function<void(ll, ll)> dfs = [&](ll u, ll p) {
    vector<ll> v;
    for (auto x : adj[u]) {
      if (x != p) {
        dfs(x, u);
        v.push_back(id[x]);
      }
    }
    sort(all(v));

    if (mp.find(v) == mp.end()) {
      mp[v] = ++c;
    }
    id[u] = mp[v];

    set<ll> s;
    for (auto i : v) {
      if (s.count(i)) {
        s.erase(i);
      } else {
        s.insert(i);
      }
    }

    if (s.empty()) {
      sym[id[u]] = true;
    } else if (s.size() == 1) {
      ll ch = *(s.begin());
      if (sym[ch]) {
        sym[id[u]] = true;
      }
    } else {
      sym[id[u]] = false;
    }
  };

  dfs(1, 0);
  if (sym[id[1]]) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

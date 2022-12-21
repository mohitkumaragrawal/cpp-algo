#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll parent[2005], sz[2005];
bool valid[2005];

ll find_set(ll x) {
  if (x == parent[x]) return x;
  return parent[x] = find_set(parent[x]);
}

void union_set(ll a, ll b) {
  ll p1 = find_set(a);
  ll p2 = find_set(b);
  if (p1 == p2) return;

  if (sz[p2] > sz[p1]) swap(p1, p2);

  parent[p2] = p1;
  sz[p1] += sz[p2];
}

void solve() {
  for (ll i = 1; i <= 2000; ++i) {
    parent[i] = i;
    sz[i] = 1;
  }

  ll n;
  cin >> n;

  ll m;
  cin >> m;

  fill(valid, valid + n + 1, true);

  for (ll i = 0; i < m; ++i) {
    ll u, v;
    cin >> u >> v;
    union_set(u, v);
  }

  ll k;
  cin >> k;
  for (ll i = 0; i < k; ++i) {
    ll u, v;
    cin >> u >> v;

    if (find_set(u) == find_set(v)) {
      valid[find_set(u)] = false;
    }
  }

  ll ans = 0;
  for (ll i = 1; i <= n; ++i) {
    ll x = find_set(i);
    if (valid[x]) {
      ans = max(ans, sz[x]);
    }
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

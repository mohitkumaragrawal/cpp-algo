#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll n;

ll st[200005], ed[200005], tree[200005 * 4], parent[200005], sz[200005];
ll seg_size[200005], pre[200005];

ll find_set(ll u) {
  if (parent[u] == u) return u;
  return parent[u] = find_set(parent[u]);
}

void merge_set(ll u, ll v) {
  ll x = find_set(u);
  ll y = find_set(v);

  if (sz[x] < sz[y]) swap(x, y);
  parent[y] = x;
  sz[x] += sz[y];

  // update the range of x;

  st[x] = min(st[x], st[y]);
  ed[x] = max(ed[x], ed[y]);
}

void solve() {
  cin >> n;

  for (ll i = 1; i <= n; ++i) {
    parent[i] = i;
    sz[i] = 1;
  }

  ll prev_set = -1;
  ll covered = 0;

  for (ll i = 1; i <= n; ++i) {
    ll p, h;
    cin >> p >> h;

    st[i] = p;
    ed[i] = p + h;

    if (p <= covered) {
      merge_set(prev_set, i);

      covered = max(covered, p + h);
    } else {
      if (prev_set != -1) {
        ll u = find_set(prev_set);
        seg_size[u] = (ed[u] - st[u]);
      }

      prev_set = i;
      covered = p + h;
    }
  }

  ll u = find_set(prev_set);
  seg_size[u] = (ed[u] - st[u]);

  for (ll i = 1; i <= n; ++i) pre[i] = pre[i - 1] + seg_size[i];

  ll q;
  cin >> q;
  while (q--) {
    ll x, y;
    cin >> x >> y;

    ll s1 = find_set(x);
    ll s2 = find_set(y);

    ll seg = ed[s2] - st[s1];
    ll ans = seg - (pre[s2] - pre[s1 - 1]);

    cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}

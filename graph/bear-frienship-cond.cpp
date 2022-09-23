#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll N;

vector<ll> parent;
vector<ll> sz, nedges;

ll find_set(ll nd) {
  if (parent[nd] == nd) return nd;
  return parent[nd] = find_set(parent[nd]);
}

ll union_set(ll s1, ll s2) {
  ll p1 = find_set(s1);
  ll p2 = find_set(s2);

  if (p1 == p2) return p1;

  if (sz[p2] > sz[p1]) swap(p1, p2);
  parent[p2] = p1;
  sz[p1] += sz[p2];
  return p1;
}

ll get_size(ll nd) {
  ll root = find_set(nd);
  return sz[root];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll M;
  cin >> N >> M;
  nedges.assign(N + 1, 0);
  sz.assign(N + 1, 1);
  parent.resize(N + 1);
  for (ll i = 1; i <= N; ++i) parent[i] = i;

  while (M--) {
    ll x, y;
    cin >> x >> y;

    nedges[x]++, nedges[y]++;
    union_set(x, y);
  }

  bool is_valid = true;

  for (ll i = 1; i <= N; ++i) {
    ll cc = get_size(i);

    if (nedges[i] != cc - 1) {
      is_valid = false;
      break;
    }
  }

  if (!is_valid) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}
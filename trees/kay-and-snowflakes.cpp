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

ll n, q, parent[300005], centroid[300005], sz[300005];
vector<vector<ll>> children;

void DFS(ll node) {
  sz[node] = 1;
  for (ll child : children[node]) {
    DFS(child);
    sz[node] += sz[child];
  }

  ll cc = -1;
  ll half_size = sz[node] / 2;
  for (ll child : children[node]) {
    if (sz[child] > half_size) {
      cc = child;
      break;
    }
  }

  if (cc == -1) {
    centroid[node] = node;
  } else {
    ll x = centroid[cc];
    while ((sz[node] - sz[x]) > half_size) x = parent[x];
    centroid[node] = x;
  }
}

void solve() {
  cin >> n >> q;
  children.resize(n);

  for (ll i = 1; i < n; ++i) {
    ll p;
    cin >> p;
    p--;

    parent[i] = p;
    children[p].push_back(i);
  }

  DFS(0);
  while (q--) {
    ll y;
    cin >> y;
    y--;
    cout << centroid[y] + 1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll tree[(1 << 18) + 100];
ll n;

bool is_or(ll id) {
  if ((__builtin_clzll(n) & 1) == (__builtin_clzll(id) & 1)) {
    return false;
  }
  return true;
}

void refresh(ll i) {
  if (is_or(i)) {
    tree[i] = tree[2 * i] | tree[2 * i + 1];
  } else {
    tree[i] = tree[2 * i] ^ tree[2 * i + 1];
  }
}

void update(ll p, ll v) {
  ll id = p + n - 1;
  tree[id] = v;

  id /= 2;
  while (id > 0) {
    refresh(id);
    id /= 2;
  }
}

void solve() {
  ll m;
  cin >> n >> m;

  n = 1 << n;

  for (ll i = n; i < 2 * n; ++i) cin >> tree[i];

  for (ll i = n - 1; i >= 1; --i) {
    refresh(i);
  }

  while (m--) {
    ll p, v;
    cin >> p >> v;
    update(p, v);
    cout << tree[1] << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}

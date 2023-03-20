#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
ll nh;
vector<ll> a;
vector<vector<ll>> divisors;
set<ll, greater<ll>> ans;

set<pll> checked;

vector<ll> find_divisors(ll i) {
  vector<ll> D;

  for (ll j = 1; j * j <= i; j++) {
    if (i % j == 0) {
      D.push_back(j);
      D.push_back(i / j);
    }
  }

  sort(all(D));
  D.erase(unique(all(D)), D.end());

  return D;
}

void random_check() {
  ll i = rng() % n;
  ll j = rng() % n;

  if (i == j) return;

  // LOG(M)
  ll g = gcd(a[i], a[j]);

  // Sqrt(M), size of D is LOG(M)
  auto D = find_divisors(g);

  // N LOG(M)
  for (ll k = D.size() - 1; k >= 0; --k) {
    ll cnt = 0;
    ll num = D[k];

    if (!ans.empty()) {
      auto mx = *max_element(all(ans));

      if (num <= mx) break;
    }

    for (auto x : a) {
      if (x % num == 0) ++cnt;
    }

    if (cnt >= nh) {
      ans.insert(D[k]);
      break;
    }
  }
}

void solve() {
  cin >> n;
  nh = (n + 1) / 2;

  a.resize(n);
  divisors.resize(n);

  for (ll i = 0; i < n; ++i) cin >> a[i];

  for (ll i = 0; i < 10; ++i) random_check();

  if (ans.empty()) {
    cout << 1 << endl;
    return;
  }

  ll res = *max_element(all(ans));
  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

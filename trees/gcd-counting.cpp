#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

struct sieve_t {
  sieve_t(int n, bool gen_primes = false) {
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
      for (int j = i * i; j <= n; j += i) is_prime[j] = false;
    }
    if (gen_primes) {
      for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) primes.push_back(i);
      }
    }
  }
  vector<bool> is_prime;
  vector<int> primes;
};

sieve_t sieve(200000, true);

// Generate all the primes in (N lg N)
auto& primes = sieve.primes;

ll a[200005], vis[200005];
vector<vector<ll>> G;
vector<vector<ll>> val;

void dfs(ll curr, ll prev, ll dist, ll prime, vector<pair<ll, ll>>& vpr) {
  vis[curr] = prime;
  vpr.push_back({curr, dist});
  for (ll next : G[curr]) {
    if (next != prev && (a[next] % prime == 0))
      dfs(next, curr, dist + 1, prime, vpr);
  }
}

void solve() {
  ll n;
  cin >> n;

  G.resize(n);
  val.resize(200005);

  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
    val[a[i]].push_back(i);
  }

  for (ll i = 0; i < n - 1; ++i) {
    ll u, v;
    cin >> u >> v;

    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  ll ans = 0;

  // There are approx (N / lg N) primes numbers;
  // Every single vertex can be in atmost 6 forest;
  // So it's like finding the diameter of at forest
  // of at most '6n' nodes;

  for (ll p : primes) {
    vector<ll> inc;
    for (ll j = p; j <= 200000; j += p) {
      for (ll idx : val[j]) inc.push_back(idx);
    }

    for (ll i : inc) {
      if (vis[i] == p) continue;

      vector<pair<ll, ll>> vpr;
      dfs(i, -1, 1, p, vpr);

      // find the farthest node from i;
      ll nd1 = i, dist1 = 1;
      for (auto& pr : vpr) {
        if (pr.second > dist1) {
          nd1 = pr.first;
          dist1 = pr.second;
        }
      }

      vpr.clear();
      dfs(nd1, -1, 1, p, vpr);

      dist1 = 1;
      for (auto& pr : vpr) {
        if (pr.second > dist1) {
          nd1 = pr.first;
          dist1 = pr.second;
        }
      }

      ans = max(ans, dist1);
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

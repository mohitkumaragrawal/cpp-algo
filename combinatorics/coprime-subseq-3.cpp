#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;
const ll MX = 100000;

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

// dispf: distinct count of prime factors
ll pow2[100005], freq[100005], sieve[100005], dispf[100005], arr[100005];

void pre_computation() {
  pow2[0] = 1;
  for (ll i = 1; i <= MX; ++i) {
    pow2[i] = (2 * pow2[i - 1]) % MOD;
  }

  for (ll i = 0; i <= MX; ++i) sieve[i] = i;
  for (ll i = 2; i <= MX; ++i) {
    if (sieve[i] != i) continue;
    for (ll j = i; j <= MX; j += i) {
      dispf[j]++;
      if (sieve[j] == j) sieve[j] = i;
    }
  }
}

void update_freq(ll x) {
  set<ll> pf;
  ll k = x;
  while (k > 1) {
    pf.insert(sieve[k]);
    k /= sieve[k];
  }
  vector<ll> vpf;
  for (ll x : pf) vpf.push_back(x);

  // Size of vpf is at most 6

  // This runs in O(k * 2^k) which is at most 6 * 2^6 => 192 operations
  for (ll mask = 1; mask < (1 << vpf.size()); ++mask) {
    ll num = 1;
    for (ll pos = 0; pos < vpf.size(); ++pos) {
      if (mask & (1 << pos)) {
        num *= vpf[pos];
      }
    }
    freq[num]++;
  }
}

void solve() {
  ll n;
  cin >> n;

  for (ll i = 0; i < n; ++i) {
    cin >> arr[i];
    update_freq(arr[i]);
  }

  ll ans = 0;
  for (ll i = 2; i <= MX; ++i) {
    ll f = freq[i];

    if (dispf[i] & 1) {
      ans += pow2[f] - 1;
      ans %= MOD;
    } else {
      ans += MOD;
      ans -= pow2[f] - 1;
      ans %= MOD;
    }
  }

  ans = MOD + (pow2[n] - 1) - ans;
  ans %= MOD;

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  pre_computation();

  solve();
}

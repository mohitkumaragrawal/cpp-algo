#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
ll binexp(ll a, ll b, ll p = MOD) {
  if (b < 0) return 0;
  ll res = 1;
  while (b > 0) {
    if (b & 1) b--, res = (res * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return res;
}

inline ll modinv(ll x, ll p = MOD) { return binexp(x, p - 2, p); }
struct power_gen {
  power_gen(ll base, ll mod, ll size = 200005) : mod(mod) {
    pws.resize(size);
    inv_pws.resize(size);

    ll inv_x = modinv(base, mod);

    pws[0] = 1;
    inv_pws[0] = 1;
    for (int i = 1; i < size; i++) {
      pws[i] = (pws[i - 1] * base) % mod;
      inv_pws[i] = (inv_pws[i - 1] * inv_x) % mod;
    }
  }
  vector<ll> pws, inv_pws;
  ll mod;
};

power_gen p1(31, MOD), p2(31, 100000037LL);

vector<ll> gen_rolling_hash(const string& s, power_gen& pw) {
  vector<ll> res(s.size());
  for (int i = 0; i < s.size(); i++) {
    res[i] = (pw.pws[i] * (s[i] - 'a' + 1)) % pw.mod;
    if (i) res[i] = (res[i] + res[i - 1]) % pw.mod;
  }
  return res;
}

void solve() {
  ll n;
  string s;
  cin >> n >> s;

  vector<pair<vector<ll>, power_gen&>> hashes;

  hashes.emplace_back(gen_rolling_hash(s, p1), p1);
  hashes.emplace_back(gen_rolling_hash(s, p2), p2);

  set<vector<ll>> st;

  for (ll i = 0; i < n - 1; ++i) {
    vector<ll> vh;
    for (auto& [hash, pw] : hashes) {
      ll h1 = (i > 0) ? hash[i - 1] : 0;
      ll h2 = (pw.mod + hash[n - 1] - hash[i + 1]) % pw.mod;
      h2 = (h2 * pw.inv_pws[2]) % pw.mod;
      vh.push_back((h1 + h2) % pw.mod);
    }

    st.insert(vh);
  }

  cout << st.size() << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

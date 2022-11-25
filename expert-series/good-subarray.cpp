#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  vector<ll> c(n + 1);
  c[0] = 0;
  for (ll i = 1; i <= n; ++i) {
    c[i] = c[i - 1] + (s[i - 1] - '0') - 1;
  }

  ll ways = 0;
  map<ll, ll> mp;
  for (ll i = n; i >= 1; --i) {
    mp[c[i]]++;

    ways += mp[c[i - 1]];
  }

  cout << ways << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

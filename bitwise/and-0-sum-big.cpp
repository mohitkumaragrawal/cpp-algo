#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;
const ll MOD = 1e9 + 7;

void solve() {
  ll n, k;
  cin >> n >> k;

  ll ans = 1;
  while (k--) ans = (ans * n) % MOD;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

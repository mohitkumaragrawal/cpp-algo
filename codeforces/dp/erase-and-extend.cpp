#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

string get(const string& s, ull k) {
  string res = s;
  while (res.size() < k) res += s;
  while (res.size() > k) res.pop_back();
  return res;
}

void solve() {
  ll n, k;
  cin >> n >> k;

  string str;
  cin >> str;

  string pre;
  pre.push_back(str[0]);

  string ans = get(pre, k);
  for (ll i = 2; i <= n; ++i) {
    if (str[i - 1] > str[0]) break;

    pre.push_back(str[i - 1]);
    ans = min(ans, get(pre, k));
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

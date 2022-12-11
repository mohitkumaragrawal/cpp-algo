#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  string s;
  ll k;
  cin >> s >> k;
  ll res_size = s.size() - k;

  string res;
  ll idx = 0;

  {
    for (ll i = 1; i <= k; ++i) {
      if (s[i] == '0') continue;

      if (s[i] < s[idx]) {
        idx = i;
      }
    }
    res.push_back(s[idx]);
    k -= idx;
    idx++;
  }

  for (ll i = idx; i < s.size(); ++i) {
    if (k == 0) {
      res.push_back(s[i]);
      continue;
    }

    while (res.size() > 1 && k > 0 && s[i] < res.back()) {
      res.pop_back();
      k--;
    }
    res.push_back(s[i]);
  }
  cout << res.substr(0, res_size) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

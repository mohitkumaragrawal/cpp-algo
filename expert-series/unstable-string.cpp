#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  string s;
  cin >> s;
  ll n = s.size();

  ll left = 0, right = 0;
  ll last_idx = 0;

  while (last_idx < n && s[last_idx] == '?') ++last_idx;

  ll ans = 0;

  for (; right < n; ++right) {
    char ch = s[right];
    char lch;

    while (left < right) {
      if (last_idx > right) break;
      else lch = s[last_idx];

      if (ch == '?') break;
      ll len = (right - last_idx + 1);

      if (len & 1) {
        if (lch == ch) break;
      } else {
        if (lch != ch) break;
      }

      left = last_idx + 1;
      last_idx++;

      while (last_idx < n && s[last_idx] == '?') last_idx++;

    }
    ans += (right - left + 1);
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) solve();
}

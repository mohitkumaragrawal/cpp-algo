#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll dp[3003][3003];

// dp[i][j] = max{dp[i-1][j], dp[i][j-1], if s[i-1] == t[j-1] =>  1 +
// dp[i-1][j-1]}

void solve() {
  string s, t;
  cin >> s >> t;

  ll m = s.size(), n = t.size();

  for (ll i = 1; i <= s.size(); ++i) {
    for (ll j = 1; j <= t.size(); ++j) {
      dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
    }
  }

  string lcs;

  ll i = m, j = n;

  while (i > 0 && j > 0) {
    if (s[i - 1] == t[j - 1]) {
      lcs.push_back(s[i - 1]);
      i--;
      j--;
      continue;
    }
    if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }

  reverse(all(lcs));

  cout << lcs << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}

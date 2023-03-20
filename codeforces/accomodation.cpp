#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll count_doubles(string& s, ll mx_cnt, ll ones) {
  if (mx_cnt == 0) return 0;

  ll ans = 0;
  ll m = s.size();
  for (ll i = 0; i < m - 1; ++i) {
    if (s[i] == '#' || s[i + 1] == '#') continue;
    if (ans >= mx_cnt) return ans;

    ll cnt = (s[i] == '1') + (s[i + 1] == '1');
    if (cnt == ones) {
      ans++;
      s[i] = s[i + 1] = '#';
    }
  }
  return ans;
}

ll find_max(string s, ll m) {
  ll req = m / 4;
  ll ans = 0;

  req -= count_doubles(s, req, 0);

  ll del = count_doubles(s, req, 1);
  req -= del;
  ans += del;

  // del = count_doubles(s, req, 2);
  // req -= del;
  // ans += del;

  for (auto ch : s) {
    ans += (ch == '1');
  }
  return ans;
}

ll find_min(string s, ll m) {
  ll sum = 0;
  for (auto ch : s) {
    sum += (ch == '1');
  }

  ll del = 0;
  for (ll j = 2; j <= m; ++j) {
    if (s[j - 1] == '1' && s[j - 2] == '1') {
      del++;
      j++;
    }
  }

  del = min(del, m / 4);
  return sum - del;
}

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<string> vs(n);
  for (auto& s : vs) cin >> s;

  ll ans_mx = 0, ans_mn = 0;
  for (auto& s : vs) {
    ans_mn += find_min(s, m);
  }

  for (auto& s : vs) ans_mx += find_max(s, m);

  cout << ans_mn << " " << ans_mx << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

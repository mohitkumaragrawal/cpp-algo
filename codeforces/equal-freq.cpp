#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n;
  string s;
  cin >> n >> s;

  ll freq[26];
  fill(freq, freq + 26, 0);
  for (char ch : s) freq[ch - 'a']++;

  string alphabet;
  for (char ch = 'a'; ch <= 'z'; ++ch) alphabet.push_back(ch);

  sort(all(alphabet),
       [&](char a, char b) { return freq[a - 'a'] > freq[b - 'a']; });

  ll ans_diff = 1e10, ans_c = 1;

  auto calc_diff = [&](ll c, ll k) {
    ll res = 0;
    for (ll i = 0; i < 26; ++i) {
      ll f = k;
      if (i >= c) f = 0;
      // if (f > freq[alphabet[i]-'a'])
      ll delta = freq[alphabet[i] - 'a'] - f;
      res += max(delta, 0LL);
    }
    return res;
  };

  for (ll c = 1; c <= 26; ++c) {
    if (n % c != 0) continue;

    ll k = n / c;
    ll d = calc_diff(c, k);

    if (d < ans_diff) {
      ans_diff = d;
      ans_c = c;
    }
  }

  cout << ans_diff << endl;

  // regenerate the string;

  ll left[26];
  fill(left, left + 26, 0);
  ll k = n / ans_c;
  for (ll i = 0; i < ans_c; ++i) {
    left[alphabet[i] - 'a'] = k;
  }

  string ans(n, '0');

  for (int i = 0; i < n; ++i) {
    int j = s[i] - 'a';
    if (left[j]) {
      ans[i] = s[i];
      left[j]--;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (ans[i] != '0') continue;

    for (int j = 0; j < 26; ++j) {
      if (left[j]) {
        ans[i] = 'a' + j;
        left[j]--;
        break;
      }
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

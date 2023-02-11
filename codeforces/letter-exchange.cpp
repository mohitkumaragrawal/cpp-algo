#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const string letters = "win";

void solve() {
  ll n;
  cin >> n;

  string s[n];
  for (ll i = 0; i < n; ++i) cin >> s[i];

  map<pair<char, char>, vector<ll>> ex;
  vector<tuple<ll, char, ll, char>> ans;

  for (ll i = 0; i < n; ++i) {
    map<char, ll> freq;
    for (char ch : s[i]) freq[ch]++;

    vector<char> need, give;
    for (char ch : letters) {
      if (freq[ch] == 0) {
        need.push_back(ch);
      } else {
        for (ll j = 0; j < freq[ch] - 1; ++j) {
          give.push_back(ch);
        }
      }
    }

    for (ll j = 0; j < need.size(); ++j) {
      char c1 = need[j];
      char c2 = give[j];

      if (ex[{c2, c1}].empty()) {
        ex[{c1, c2}].push_back(i);
      } else {
        ll k = ex[{c2, c1}].back();
        ans.emplace_back(i, c2, k, c1);
        ex[{c2, c1}].pop_back();
      }
    }
  }
  char ch[3] = {'w', 'i', 'n'};
  if (ex[{'w', 'i'}].empty()) {
    swap(ch[0], ch[1]);
  }

  // there is a cycle  (01) -> (12) -> (20)
  for (ll j = 0; j < ex[{ch[0], ch[1]}].size(); ++j) {
    ll x = ex[{ch[0], ch[1]}][j];
    ll y = ex[{ch[1], ch[2]}][j];
    ll z = ex[{ch[2], ch[0]}][j];

    ans.emplace_back(x, ch[1], y, ch[2]);
    ans.emplace_back(x, ch[2], z, ch[0]);
  }

  cout << ans.size() << endl;
  for (auto [a, b, c, d] : ans) {
    cout << a + 1 << " " << b << " " << c + 1 << " " << d << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

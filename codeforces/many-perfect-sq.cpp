#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

vector<ll> squares;
vector<ll> sqs;

ll n, a[51];
void solve() {
  cin >> n;
  for (ll i = 0; i < n; ++i) cin >> a[i];

  unordered_map<ll, ll> mp;
  for (ll i = 0; i < n; ++i) {
    for (auto sq : squares) {
      if (sq >= a[i]) mp[sq - a[i]]++;
    }
  }

  ll ans = 0, ans_f = 0;
  for (auto [x, f] : mp) {
    if (f > ans_f) {
      ans_f = f;
      ans = x;
    }
  }
  cout << ans_f << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  for (ll i = 1; i <= 10; ++i) {
    for (ll j = 1; j <= 10; ++j) {
      if (j < i)
        cout << ".\t";
      else
        cout << j * j - i * i << "\t";
    }
    cout << endl;
  }
  return 0;

  for (ll i = 1; i <= 100005; ++i) {
    squares.push_back(i * i);
  }

  ll T;
  cin >> T;
  while (T--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll p10[11];

void solve() {
  string n;
  cin >> n;

  ll a = 0, b = 0;

  bool flag = false;

  for (ll i = 0; i < n.size(); ++i) {
    ll dig = n[n.size() - i - 1] - '0';
    if (dig % 2 == 0) {
      a += p10[i] * (dig / 2);
      b += p10[i] * (dig / 2);
      continue;
    }

    ll d1 = dig / 2;
    ll d2 = (dig + 1) / 2;

    if (flag) {
      a += p10[i] * d1;
      b += p10[i] * d2;
    } else {
      a += p10[i] * d2;
      b += p10[i] * d1;
    }

    flag = !flag;
  }

  cout << a << " " << b << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  p10[0] = 1;
  for (ll i = 1; i < 11; ++i) p10[i] = p10[i - 1] * 10;

  ll T;
  cin >> T;
  while (T--) solve();
}

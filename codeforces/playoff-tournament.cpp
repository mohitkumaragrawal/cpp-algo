#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n;
  string s;
  cin >> n >> s;

  ll one_count = 0, zero_count = 0;
  ll start = 1, end = (1 << n);

  for (ll i = 0; i < s.size(); ++i) {
    if (s[i] == '1') {
      start += (1 << one_count);
      one_count++;
    } else {
      end -= (1 << zero_count);
      zero_count++;
    }
  }

  for (ll i = start; i <= end; ++i) cout << i << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

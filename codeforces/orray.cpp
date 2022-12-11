#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

int a[200005], n;

void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<bool> taken(n, false);

  int x = 0;

  for (int i = 30; i >= 0; --i) {
    int mx = 0;
    int or_val = x | a[0];

    for (int j = 1; j < n; ++j) {
      if (taken[j]) continue;
      if (or_val < (x | a[j])) {
        mx = j;
        or_val = x | a[mx];
      }
    }

    if (taken[mx]) break;

    cout << a[mx] << " ";
    taken[mx] = true;
    x |= a[mx];
  }

  for (int i = 0; i < n; ++i) {
    if (!taken[i]) cout << a[i] << " ";
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

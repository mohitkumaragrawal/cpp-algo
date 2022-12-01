#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  string s;
  cin >> s;

  int horz = 0, vert = 0;
  for (char ch : s) {
    if (ch == '0') {
      cout << "1 " << vert + 1 << "\n";
      vert = (vert + 1) % 4;
    } else {
      cout << "4 " << 2 * horz + 1 << "\n";
      horz = 1 - horz;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

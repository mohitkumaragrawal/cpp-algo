#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll cnt[4];
  for (ll i = 0; i < 4; ++i) cin >> cnt[i];

  char mat[55][55];
  cnt[0]--;
  cnt[1]--;

  string order = "BCD";
  for (ll i = 0; i < 25; ++i) {
    for (ll j = 0; j < 50; ++j) {
      mat[i][j] = 'A';
      if (i % 2 == 1 && j % 2 == 1) {
        for (char ch : order) {
          if (cnt[ch - 'A'] > 0) {
            mat[i][j] = ch;
            cnt[ch - 'A']--;
            break;
          }
        }
      }
    }
  }
  order = "ACD";
  for (ll i = 25; i < 50; ++i) {
    for (ll j = 0; j < 50; ++j) {
      mat[i][j] = 'B';
      if (i % 2 == 0 && j % 2 == 1) {
        for (char ch : order) {
          if (cnt[ch - 'A'] > 0) {
            mat[i][j] = ch;
            cnt[ch - 'A']--;
            break;
          }
        }
      }
    }
  }

  cout << "50 50\n";
  for (ll i = 0; i < 50; ++i) {
    mat[i][50] = '\0';
    cout << mat[i] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

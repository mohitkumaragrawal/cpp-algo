#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll dp[33][8];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  dp[0][0] = 1;

  vector<pll> single_move;
  for (ll i = 0; i < 3; ++i) {
    ll c1 = (1 << i);
    single_move.emplace_back(c1, c1);

    ll c2 = (1 << i) | (1 << (i + 1));
    if (c2 < 8) single_move.emplace_back(c2, 0);
  }

  vector<pll> double_move;
  for (ll i = 0; i < single_move.size(); ++i) {
    for (ll j = i + 1; j < single_move.size(); ++j) {
      auto [c1, c2] = single_move[i];
      auto [c3, c4] = single_move[j];

      if ((c1 & c3) == 0 && (c2 & c4) == 0) {
        double_move.emplace_back(c1 | c3, c2 | c4);
      }
    }
  }

  vector<pll> triple_move;
  triple_move.emplace_back(7, 7);

  vector<pll> moves;
  moves.emplace_back(0, 0);
  for (auto x : single_move) moves.push_back(x);
  for (auto x : double_move) moves.push_back(x);
  for (auto x : triple_move) moves.push_back(x);

  for (ll i = 0; i < 30; ++i) {
    for (ll j = 0; j < 8; ++j) {
      if (dp[i][j] == 0) continue;

      for (auto [c1, c2] : moves) {
        if ((j & c1) == 0 && (j | c1) == 7) {
          dp[i + 1][c2] += dp[i][j];
        }
      }
    }
  }

  while (true) {
    ll x;
    cin >> x;
    if (x == -1) break;
    cout << dp[x][0] << endl;
  }
}

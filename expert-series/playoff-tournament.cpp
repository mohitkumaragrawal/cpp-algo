#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T, typename ComparatorFn = less<T>>
// using ordered_set = tree<T, null_type, ComparatorFn, rb_tree_tag,
//                          tree_order_statistics_node_update>;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll MOD = 1e9 + 7;

#ifdef _DEBUG
#define __dis cout << "\033[1;31m* (" << __LINE__ << "):\033[0m "
#define LOG(x) __dis << x << endl
#define __m(x) #x "=" << x << "\t"
#define DEBUG(x) __dis << __m(x) << endl
#define DEBUG2(x, y) __dis << __m(x) << __m(y) << endl
#define DEBUG3(x, y, z) __dis << __m(x) << __m(y) << __m(z) << endl
#define DEBUG4(x, y, z, w) __dis << __m(x) << __m(y) << __m(z) << __m(w) << end
#else
#define endl '\n'
#define LOG(X)
#define DEBUG(X)
#define DEBUG2(x, y)
#define DEBUG3(x, y, z)
#define DEBUG4(x, y, z, w)
#endif

#define pow2(k) (1 << (k))
constexpr int MAX_NODES = (1 << 20);

int game_to_node[MAX_NODES], value[MAX_NODES], node_to_game[MAX_NODES];

void solve() {
  int k;
  cin >> k;

  string F;
  cin >> F;

  for (int i = pow2(k); i < pow2(k + 1); ++i) {
    value[i] = 1;
  }

  int g = 0;
  for (int i = k - 1; i >= 0; --i) {
    for (int j = pow2(i); j < pow2(i + 1); ++j) {
      ++g;
      game_to_node[g] = j;
      node_to_game[j] = g;
    }
  }

  auto update_game = [&](int i) {
    char result = F[i - 1];
    int node = game_to_node[i];

    if (result == '?') {
      value[node] = value[2 * node] + value[2 * node + 1];
    } else if (result == '0') {
      value[node] = value[2 * node];
    } else {
      value[node] = value[2 * node + 1];
    }
  };

  for (ull i = 1; i <= F.size(); ++i) {
    update_game(i);
  }

  int Q;
  cin >> Q;

  while (Q--) {
    int game;
    char result;

    cin >> game >> result;
    F[game - 1] = result;
    update_game(game);

    int node = game_to_node[game] / 2;
    while (node >= 1) {
      update_game(node_to_game[node]);
      node /= 2;
    }

    cout << value[1] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

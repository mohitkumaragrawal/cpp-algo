#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using namespace std;
using ll = long long;
using ull = unsigned long long;
// const ll MOD = 1e9 + 7;
const ll INF = 1e+17;

// In debug mode show some additional information;
#ifdef _DEBUG
#define display cout << "\033[1;31m* (" << __LINE__ << "):\033[0m "
#define LOG(x) display << x << endl
#define _MC_(x) #x "=" << x << "\t"
#define DEBUG(x) display << _MC_(x) << endl
#define DEBUG2(x, y) display << _MC_(x) << _MC_(y) << endl
#define DEBUG3(x, y, z) display << _MC_(x) << _MC_(y) << _MC_(z) << endl
#define DEBUG4(x, y, z, w) \
  display << _MC_(x) << _MC_(y) << _MC_(z) << _MC_(w) << endl;
#else
#define display cout
#define LOG(x)
#define DEBUG(x)
#define DEBUG2(x, y)
#define DEBUG3(x, y, z)
#define DEBUG4(x, y, z, w)
#define endl '\n'
#endif

ll F[1000005], G[1000005], f[1000005];

void solve() {
  ll N;
  cin >> N;

  string str;
  cin >> str;

  f[N - 1] = (str[N - 1] == '*') ? 1 : 0;
  for (ll i = N - 2; i >= 0; --i) {
    f[i] = f[i + 1];
    if (str[i] == '*') {
      f[i]++;
    }
  }

  F[N - 1] = 0;
  for (ll i = N - 2; i >= 0; --i) {
    if (str[i] == '*') {
      F[i] = F[i + 1];
    } else {
      F[i] = F[i + 1] + f[i];
    }
  }

  G[0] = 0;
  for (ll i = 1; i < N; ++i) {
    if (str[i] == '*') {
      G[i] = G[i - 1];
    } else {
      G[i] = G[i - 1] + f[0] - f[i];
    }
  }

  ll ans = INF;

  for (ll i = 0; i < N; ++i) {
    ll new_ans = F[i] + G[i];
    DEBUG3(new_ans, F[i], G[i]);

    ans = min(ans, new_ans);
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;

  while (T--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#ifdef _DEBUG
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

ll query(ll l, ll r) {
  if (l == r) {
    return -1;
  }

  cout << "? " << l << " " << r << endl;
  ll res;
  cin >> res;
  return res;
}

void solve() {
  ll n;
  cin >> n;

  ll K = query(1, n);

  if (n == 2) {
    if (K == 1) {
      cout << "! " << 2 << endl;
    } else {
      cout << "! " << 1 << endl;
    }

    return;
  }

  ll L = n;
  if (K != n) {
    L = query(1, K);
  }

  if (L == K) {
    ll low = 2, high = K, ans = 1;

    while (high >= low) {
      ll mid = (low + high) / 2;

      bool cond = query(K - mid + 1, K) == K;

      if (cond) {
        ans = K - mid + 1;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    cout << "! " << ans << endl;
    return;
  } else {
    ll low = 2, high = n - K + 1, ans = n;

    while (high >= low) {
      ll mid = (low + high) / 2;

      bool cond = query(K, K + mid - 1) == K;

      if (cond) {
        ans = K + mid - 1;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    cout << "! " << ans << endl;
    return;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

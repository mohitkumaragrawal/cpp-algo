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

ll pow5[20];

// Calculate the number of booring numbers, whose number of digit is equal to
// number of digits in X and is less than or equals to X;
ll count_boring_numbers(ll X) {
  ll dp[20][2];
  for (int i = 0; i < 20; ++i) {
    dp[i][0] = dp[i][1] = -1;
  }

  auto x_str = to_string(X);
  int N = x_str.size();

  function<ll(ll dig, bool flag)> resolve = [&](ll dig, bool flag) -> ll {
    if (dp[dig][flag] != -1) return dp[dig][flag];

    if (dig == 0) return 1;
    if (dig == 1) {
      if (flag) {
        ll up = x_str.back() - '0';
        if (up == 0) return 0;
        if (N % 2 == 0) {
          return up / 2 + 1;
        } else {
          return (up - 1) / 2 + 1;
        }
      } else {
        return 5;
      }
    }

    ll up = 99;
    if (flag) {
      string tmp = x_str.substr(N - dig, 2);
      up = stoll(tmp);
    }

    ll ans = 0;
    for (int first = 1; first <= 9; first += 2) {
      for (int second = 0; second <= 9; second += 2) {
        ll num = (first * 10) + second;
        if (num > up) break;

        ans += resolve(dig - 2, flag && (num == up));
      }
    }

    return dp[dig][flag] = ans;
  };

  return resolve(N, true);
}

void init_pow() {
  pow5[0] = 1;
  for (ll i = 1; i < 20; ++i) pow5[i] = 5 * pow5[i - 1];
}

ll CountBoringNumbers(ll X) {
  string x_str = to_string(X);

  ll ans = count_boring_numbers(X);
  for (ull i = 1; i < x_str.size(); ++i) {
    ans += pow5[i];
  }
  return ans;
}

void solve(ll T) {
  ll L, R;
  cin >> L >> R;

  ll ans = CountBoringNumbers(R) - CountBoringNumbers(L - 1);
  OUT(T) << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  init_pow();

  ll T;
  cin >> T;

  for (ll i = 1; i <= T; ++i) solve(i);
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll max_idx[200005];
ll n, m;
string s, t;

bool check(ll w) {
  ll idx = 0;

  for (ll i = 0; i < n && idx < m - 1; ++i) {
    if (s[i] == t[idx]) {
      ll diff = max_idx[idx + 1] - i;
      if (diff >= w) {
        return true;
      }
      idx++;
    }
  }

  return false;
}

void solve() {
  cin >> n >> m;
  cin >> s >> t;

  ll idx = m - 1;
  for (ll j = n - 1; j >= 0; --j) {
    if (idx < 0) break;

    if (s[j] == t[idx]) {
      max_idx[idx] = j;
      --idx;
    }
  }

  ll low = 1, high = n - 1;
  ll ans = low;

  while (high >= low) {
    ll mid = (low + high) / 2;
    if (check(mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  solve();
}

// #include <bits/stdc++.h>
// using namespace std;
//
// using ll = long long;
//
// ll max_idx[200005];
// ll min_idx[200005];
//
// ll n, m;
// string s, t;
//
// void solve() {
//   cin >> n >> m;
//   cin >> s >> t;
//
//   ll idx = m - 1;
//
//   for (ll j = n - 1; j >= 0; --j) {
//     if (idx < 0) break;
//
//     if (s[j] == t[idx]) {
//       max_idx[idx] = j;
//       idx--;
//     }
//   }
//
//   idx = 0;
//   for (ll j = 0; j < n; ++j) {
//     if (idx >= m) break;
//
//     if (s[j] == t[idx]) {
//       min_idx[idx] = j;
//       idx++;
//     }
//   }
//
//   ll ans = 1;
//   for (ll i = 1; i < m; ++i) {
//     ans = max(ans, max_idx[i] - min_idx[i - 1]);
//   }
//   cout << ans << endl;
// }
//
// int main() {
//   ios_base::sync_with_stdio(false), cin.tie(NULL);
//   solve();
// }

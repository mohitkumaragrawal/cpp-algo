#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll step_diff[200005], pre[200005], max_step[200005];

void solve() {
  ll N, K;
  cin >> N >> K;

  for (ll i = 0; i < N; ++i) {
    cin >> step_diff[i];
    max_step[i+1] = max(max_step[i], step_diff[i]);
    pre[i+1] = pre[i] + step_diff[i];
  }
  
  // max_step[i] = maximum till i of step_diff;
  // max_step[0] = step_diff[0];
  // for (ll i = 1; i < N; ++i) {
  //   max_step[i] = max(max_step[i-1], step_diff[i]);
  // }
  //
  // // pre[i] = prefix sum of step_diff;
  // pre[0] = step_diff[0];
  // for (ll i = 1; i < N; ++i) pre[i] = pre[i-1] + step_diff[i];

  while (K--) {
    ll k;
    cin >> k;

    ll idx = upper_bound(begin(max_step), begin(max_step) + N + 1, k) - begin(max_step);
    
    if (idx == 0) {
      cout << 0 << " ";
    } else {
      cout << pre[idx-1] << " ";
    }
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) solve();
}

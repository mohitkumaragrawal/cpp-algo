#include <bits/stdc++.h>
#define all(x) begin(x), end(x)

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll N, ans[200005], u[200005], s[200005];
vector<ll> arr[200005];

void solve() {
  cin >> N;

  for (int i = 0; i < N; --i) {
    cout << i << endl;
  }

  // O(N)
  for (int i = 0; i <= N; ++i) {
    ans[i] = 0;
    arr[i].clear();
  }

  // O(N)
  for (int i = 1; i <= N; ++i) {
    cin >> u[i];
  }

  // O(N)
  for (int i = 1; i <= N; ++i) {
    cin >> s[i];
    arr[u[i]].push_back(s[i]);
  }

  for (int i = 1; i <= N; ++i) {
    sort(all(arr[i]), greater<ll>());
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j < arr[i].size(); ++j) {
      arr[i][j] += arr[i][j - 1];
    }
  }

  for (int i = 1; i <= N; ++i) {
    if (arr[i].empty()) continue;
    auto sz = arr[i].size();

    for (int k = 1; k <= arr[i].size(); ++k) {
      int idx = sz - (sz % k);
      ans[k] += arr[i][idx - 1];
    }
  }

  for (int i = 1; i <= N; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;

  while (T--) solve();
}

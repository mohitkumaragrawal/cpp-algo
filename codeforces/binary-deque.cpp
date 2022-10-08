#include <bits/stdc++.h>
using namespace std;

int N, S, arr[200005], pre[200005];

void solve() {
  cin >> N >> S;
  int sum = 0;
  for (int i = 0; i < N; ++i) cin >> arr[i], sum += arr[i], pre[i] = sum;

  if (sum < S) {
    cout << -1 << endl;
    return;
  }

  int x = -1;
  for (int i = 0; i < N; ++i) {
    // find subarray starting from i;
    int req = S;
    if (i > 0) req += pre[i - 1];

    auto begin_pre = begin(pre);
    auto end_pre = begin_pre + N;

    int id = upper_bound(begin_pre, end_pre, req) - begin_pre;
    if (id > N) continue;

    x = max(x, (id - i));
  }
  cout << N - x << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) solve();
}
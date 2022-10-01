#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    ll N;
    cin >> N;

    vector<ll> A(N);
    for (ll &i : A) cin >> i;
    vector<ll> B(N);
    for (ll &i : B) cin >> i;

    for (int i = 0; i < N; ++i) {
      ll val = *lower_bound(B.begin(), B.end(), A[i]) - A[i];
      cout << val << " ";
    }
    cout << endl;

    int idx = -1;
    for (int i = 0; i < N; ++i) {
      if (idx >= i) {
        cout << B[idx] - A[i] << " ";
        continue;
      }

      idx = i;
      for (int j = i + 1; j < N; ++j) {
        if (A[j] <= B[j - 1])
          idx = j;
        else
          break;
      }

      cout << B[idx] - A[i] << " ";
    }
    cout << endl;
  }
}

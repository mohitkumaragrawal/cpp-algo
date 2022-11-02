#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  ll N, K;
  cin >> N >> K;

  vector<ll> A(N + 1);
  for (ll i = 1; i <= N; ++i) cin >> A[i];

  vector<ll> B(N + 1);

  for (ll i = 1; i <= N; ++i) {
    ll x = A[i];

    if (x <= K) {
      ll res = N + 1;

      for (ll j = i - 1; j >= 1; --j) {
        if (A[j] > K) {
          res = A[j];
          break;
        }
      }

      B[x] = res;
    } else {
      ll res = 0;

      for (ll j = i - 1; j >= 1; --j) {
        if (A[j] <= K) {
          res = A[j];
          break;
        }
      }

      B[x] = res;
    }
  }

  for (ll i = 1; i <= N; ++i) {
    cout << B[i] << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) solve();
}

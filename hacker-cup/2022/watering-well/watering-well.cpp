#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const ull MOD = 1e9 + 7;
const ull CAP = 1e15;

struct TestCase {
  TestCase(ull test) : T(test) {}

  inline void output(ull out) { cout << "Case #" << T << ": " << out << endl; }

  void input() {
    cin >> N;
    A.resize(N);
    B.resize(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i] >> B[i];
    }

    cin >> Q;
    X.resize(Q);
    Y.resize(Q);
    for (int i = 0; i < Q; ++i) {
      cin >> X[i] >> Y[i];
    }
  }

  ull sq_sum(vector<ull>& vec) {
    ull res = 0;
    for (auto el : vec) {
      res += el * el;
      if (res > CAP) res %= MOD;
    }
    return res % MOD;
  }

  ull sum(vector<ull>& vec) {
    ull res = 0;
    for (auto el : vec) {
      res += el;
    }
    return res % MOD;
  }

  void solve() {
    input();
    ull ans = 0;
    ans += (N * ((sq_sum(X) + sq_sum(Y)) % MOD)) % MOD;
    ans = ans + ((Q * ((sq_sum(A) + sq_sum(B)) % MOD)) % MOD);
    ans += 10ull * MOD;

    ans -= (2ull * sum(A) * sum(X)) % MOD;
    ans -= (2ull * sum(B) * sum(Y)) % MOD;
    output(ans % MOD);
  }

  ull T;
  ull N, Q;
  vector<ull> A, B, X, Y;
};

int main() {
  freopen("ww-input.txt", "r", stdin);
  freopen("ww-output.txt", "w", stdout);
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    TestCase test(i);
    test.solve();
  }
}

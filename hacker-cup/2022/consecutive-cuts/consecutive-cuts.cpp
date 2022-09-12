#include <bits/stdc++.h>
using namespace std;

struct TestCase {
  TestCase(int test) : T(test) { input(); }
  inline void print(string s) { cout << "Case #" << T << ": " << s << endl; }

  void input() {
    cin >> N >> k;
    A.resize(N);
    B.resize(N);
    for (int& i : A) cin >> i;
    for (int& i : B) cin >> i;
  }

  bool check_order() {
    int i = 0, j = 0;

    while (B[j] != A[i]) j++;

    while (i < N) {
      int idx = i + j;
      if (idx >= N) idx -= N;
      if (A[i] != B[idx]) return false;

      i++;
    }
    return true;
  }

  void solve() {
    bool order = check_order();
    if (!order) {
      print("NO");
      return;
    }

    if (N == 1) {
      print("YES");
      return;
    }

    if (N == 2) {
      bool can_swap = (k % 2) != 0;
      bool swapped = (A[0] != B[0]);

      if (swapped == can_swap) {
        print("YES");
      } else {
        print("NO");
      }

      return;
    }

    if (k == 1) {
      if (A[0] != B[0]) {
        print("YES");
      } else {
        print("NO");
      }
      return;
    }

    if (k == 0) {
      if (A[0] == B[0]) {
        print("YES");
      } else {
        print("NO");
      }
      return;
    }

    print("YES");
  }

  int N, k;
  vector<int> A, B;
  int T;
};

int main() {
  freopen("cc-input.txt", "r", stdin);
  freopen("cc-output.txt", "w", stdout);
  int T;
  cin >> T;

  for (int i = 1; i <= T; ++i) {
    TestCase testCase(i);
    testCase.solve();
  }
}
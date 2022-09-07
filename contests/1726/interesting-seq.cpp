#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int N, int M) {
  if (N > M) {
    return vector<int>();
  }

  if (N % 2 != 0) {
    vector<int> ans(N, 1);
    ans[N - 1] = M - N + 1;
    return ans;
  }

  // N is even;
  if (M % 2 != 0) {
    // if M is odd, it is not possible;
    return vector<int>();
  }

  int n1 = N / 2, m1 = M / 2;
  vector<int> half(n1, 1);
  half[n1 - 1] = m1 - n1 + 1;

  vector<int> ans;
  for (int el : half) ans.push_back(el);
  for (int el : half) ans.push_back(el);
  return ans;
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N, M;
    cin >> N >> M;

    auto ans = solve(N, M);
    if (ans.size() == 0) {
      cout << "No" << endl;
      continue;
    }

    cout << "Yes" << endl;
    for (auto el : ans) cout << el << " ";
    cout << endl;
  }
}
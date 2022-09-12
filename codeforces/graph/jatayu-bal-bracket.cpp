#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int solve_helper(const string& str, int l, int r, const vector<int>& match) {
  if (r < l) return 0;

  int ans = 1;
  int idx = l;

  while (idx < r) {
    ans += solve_helper(str, idx + 1, match[idx] - 1, match);
    idx = 1 + match[idx];
  }

  return ans;
}

void solve() {
  int n;
  string str;
  cin >> n >> str;
  n = str.size();

  vector<int> matching(n);
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    if (str[i] == '(') {
      st.push(i);
    } else {
      int idx = st.top();
      st.pop();
      matching[idx] = i;
    }
  }

  int ans = solve_helper(str, 0, n - 1, matching);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) solve();
}
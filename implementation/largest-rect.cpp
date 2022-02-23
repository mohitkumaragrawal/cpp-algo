#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maximum_rectangle_in_histogram(vector<int>& a) {
  int n = a.size(), ans = 0, i = 0;
  a.push_back(0);

  stack<int> st;

  while ( i < n) {
    while (!st.empty() && a[st.top()] > a[i]) {
      int t = st.top();
      int h = a[t];
      st.pop();

      if (st.empty()) {
        ans = max(ans, i * h);
      } else {
        int len = i - st.top() - 1;
        ans = max(ans, h * len);

      }
    }
    st.push(i);
    i++;
  }

  return ans;
}

int main() {
  int N;
  cin >> N;

  vector<int> bars(N);
  for (auto& i: bars) cin >> i;

  auto result = maximum_rectangle_in_histogram(bars);
  cout << result;
}
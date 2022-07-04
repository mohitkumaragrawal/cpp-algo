#include <deque>
#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;
    if (N == 3) {
      cout << -1 << endl;
      continue;
    }
    deque<int> ans;

    int largestEven = N;
    if (N & 1)
      largestEven--;

    int odd = 1;
    int even = 2;

    while (even <= largestEven) {
      /* cout << odd << " " << even << " "; */
      ans.push_back(even);
      even += 2;

      if (even > largestEven)
        break;
      /* cout << even << " "; */
      ans.push_back(even);
      even += 2;

      ans.push_back(odd);
      odd += 2;
    }

    deque<int> fronts;
    bool flag = false;

    while (odd <= N) {
      /* cout << odd << " "; */
      fronts.push_front(odd);
      odd += 2;
    }

    if (fronts.size() >= 2) {
      int sz = fronts.size();
      int a = fronts[sz - 1];
      int b = fronts[sz - 2];
      int lstTwo = a ^ b;
      if (lstTwo == 2) {
        flag = true;
      }
    }
    for (int i = 0; i < fronts.size(); ++i) {
      if (flag && i == fronts.size() - 1)
        break;
      cout << fronts[i] << " ";
    }
    for (int x : ans) {
      cout << x << " ";
    }
    if (flag)
      cout << fronts.back();
    cout << endl;
  }
}

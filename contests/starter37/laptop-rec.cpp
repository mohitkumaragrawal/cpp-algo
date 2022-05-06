#include <iostream>
#include <map>

using namespace std;

#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    map<int, int> mp;
    while (N--) {
      int n;
      cin >> n;
      mp[n]++;
    }

    int maxFreq = 0, ans = 0;
    bool confused = false;
    for (auto pr : mp) {
      if (pr.second > maxFreq) {
        maxFreq = pr.second;
        ans = pr.first;
        confused = false;
      } else if (pr.second == maxFreq)
        confused = true;
    }

    if (confused) {
      cout << "CONFUSED" << endl;
    } else {
      cout << ans << endl;
    }
  }
}
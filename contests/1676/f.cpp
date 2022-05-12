#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int& i : arr) cin >> i;

    map<int, int> mp;
    for (int x : arr) mp[x]++;

    vector<int> good;

    for (auto pr : mp) {
      if (pr.second >= k) good.push_back(pr.first);
    }

    if (good.empty()) {
      cout << -1 << endl;
      continue;
    }

    int al = 0, ar = 0;
    int l = 0, r = 0;

    while ((r + 1) < good.size()) {
      if (good[r + 1] - good[r] == 1) {
        r++;
        if (good[ar] - good[al] <= good[r] - good[l]) {
          ar = r;
          al = l;
        }
      } else {
        if (good[ar] - good[al] <= good[r] - good[l]) {
          ar = r;
          al = l;
        }

        r++;
        l = r;
      }
    }

    cout << good[al] << " " << good[ar] << endl;
  }
}
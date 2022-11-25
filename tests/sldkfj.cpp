#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);

const int N = 1e5 + 10;

int main() {
  fast;
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    vector<vector<int>> v;
    bool flag = 1;
    for (int i = 1; i < n; i++) {
      vector<int> temp;
      if (__gcd(arr[i - 1], arr[i]) != 1 && flag == 1) {
        temp.push_back(i);
        temp.push_back(i + 1);
        temp.push_back(mod);
        temp.push_back(min(arr[i], arr[i - 1]));
        arr[i] = min(arr[i], arr[i - 1]);
        arr[i - 1] = 1e9 + 7;
        v.push_back(temp);
        flag = 0;
      } else if (__gcd(arr[i - 1], arr[i]) != 1 && flag == 0) {
        temp.push_back(i);
        temp.push_back(i + 1);
        temp.push_back(min(arr[i], arr[i - 1]));
        arr[i] = 1e9 + 7;
        temp.push_back(mod);
        v.push_back(temp);
      }
    }
    cout << v.size() << "\n";
    for (auto it : v) {
      for (auto m : it) {
        cout << m << " ";
      }
      cout << "\n";
    }
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
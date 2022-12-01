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

  for (ll test = 1; test <= t; ++test) {
    int n, m;
    cin >> n >> m;
    int a[n + 1], b[n + 1], c[m + 1];
    map<int, int> mp1;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      if (mp1[b[i]] == 0) mp1[b[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
      cin >> c[i];
    }
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
      if (a[i] != b[i]) {
        mp[b[i]].push_back(i);
      }
    }
    vector<int> ans;
    bool flag = 1;
    int index = 1;
    for (int i = 1; i <= m;) {
      if (mp[c[i]].size() > 0) {
        int sz = mp[c[i]].size();
        int x = mp[c[i]][sz - 1];
        ans.push_back(x);
        a[x] = c[i];
        mp[c[i]].pop_back();
        i++;
      } else {
        index = i;
        flag = 0;
        while (i <= m && mp[c[i]].size() == 0) {
          i++;
        }
        if (i <= m) {
          int sz = mp[c[i]].size();
          int x = mp[c[i]][sz - 1];
          flag = 1;
          for (int j = index; j <= i; j++) {
            ans.push_back(x);
            a[x] = c[j];
          }
          mp[c[i]].pop_back();
          i++;
        }
      }
    }
    int ind = 0;
    if (flag == 0) {
      flag = 1;
      for (int i = index; i <= m;) {
        if (mp1[c[i]] == 0) {
          ind = i;
          while (i <= m && mp1[c[i]] == 0) {
            i++;
          }
          if (i <= m) {
            for (int j = ind; j <= i; j++) {
              ans.push_back(mp1[c[i]]);
              a[mp1[c[i]]] = c[i];
            }
            i++;
          } else {
            flag = 0;
            break;
          }
        } else {
          ans.push_back(mp1[c[i]]);
          a[mp1[c[i]]] = c[i];
          i++;
        }
      }
    }

    bool flag2 = false;
    for (ll i = 1; i <= n; ++i) {
      if (a[i] != b[i]) {
        cout << "NO\n";
        flag2 = true;
        break;
      }
    }

    if (flag2) {
      continue;
    }

    if (flag == 0) {
      cout << "NO"
           << "\n";
    } else {
      cout << "YES"
           << "\n";
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}

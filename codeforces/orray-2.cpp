#include "bits/stdc++.h"
using namespace std;

#define ll long long

#define forn(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define pb push_back
#define sz(a) (int)a.size()

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  forn(i, n) cin >> a[i];
  // we care at most about first log2(a) values
  int cur_or = 0;
  vector<bool> vis(n, false);
  for (int i = 0; i < min(31, n); ++i) {
    int mx = 0, idx = -1;
    for (int j = 0; j < n; ++j) {
      if (vis[j]) continue;
      if ((cur_or | a[j]) > mx) {
        mx = (cur_or | a[j]);
        idx = j;
      }
    }
    vis[idx] = true;
    cout << a[idx] << " ";
    cur_or |= a[idx];
  }
  forn(i, n) if (!vis[i]) cout << a[i] << " ";
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

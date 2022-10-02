#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int min_rot(string& a) {
  string b = a + a;
  return b.find(a, 1);
}

void solve() {
  int N;
  cin >> N;

  string s;
  cin >> s;

  vector<vector<int>> G(N);
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    x--;
    G[i].push_back(x);
    G[x].push_back(i);
  }

  string tmp;
  vector<bool> vis(N, false);
  function<void(int)> string_dfs = [&](int node) {
    tmp.push_back(s[node]);
    vis[node] = true;

    for (int child : G[node]) {
      if (vis[child]) continue;
      string_dfs(child);
    }
  };

  ll ans = 1;
  for (int i = 0; i < N; ++i) {
    if (vis[i]) continue;
    tmp.clear();
    string_dfs(i);

    ll x = min_rot(tmp);
    ans = (ans * x) / __gcd(ans, x);
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) solve();
}
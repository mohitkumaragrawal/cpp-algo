#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#ifdef _DEBUG
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int antCollisions(string &str) {
  while (!str.empty() && str.back() == 'R') str.pop_back();

  int idx = 0;
  while (idx < str.size() && str[idx] == 'L') idx++;

  int count = str.size() - idx;
  return count;

  // int df = 0;
  // for (int i = idx; i < str.size() - 1; ++i) {
  //   if (str[i] == 'R' && str[i + 1] == 'L') df++;
  // }
  //
  // dbg(df, idx, str.size(), str);
  //
  // // cout << df << endl;
  //
  // return str.size() - df - idx;
}

void solve() {
  string s;
  cin >> s;

  cout << antCollisions(s) << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

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

const int MAX = 1e9 + 10;

void solve() {
  int n;
  cin >> n;

  multiset<int> a;
  vector<int> b(n);

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    while (__builtin_ctz(x) > 0) x >>= 1;
    a.insert(x);
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  for (int el : b) {
    int itr = el;
    while (itr > 0) {
      if (a.count(itr) > 0) {
        a.erase(a.lower_bound(itr));
        break;
      }
      itr >>= 1;
    }
  }

  if (a.empty()) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

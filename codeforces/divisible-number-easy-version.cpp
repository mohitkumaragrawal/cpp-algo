#include <bits/stdc++.h>
using namespace std;

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

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  ll ab = a * b;

  for (ll x = a + 1; x <= c; ++x) {
    ll l = (x * ab) / __gcd(x, ab);
    ll y = l / x;

    y = y * (d / y);

    if (y > b) {
      cout << x << " " << y << '\n';
      return;
    }
  }
  cout << "-1 -1\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

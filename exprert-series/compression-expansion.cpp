
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll MOD = 1e9 + 7;

// In debug mode show some additional information;
#define endl '\n'
#ifdef _DEBUG
#define display cout << "\033[1;31m* (" << __LINE__ << "):\033[0m "
#define LOG(x) display << x << endl
#define _MC_(x) #x "=" << x << "\t"
#define DEBUG(x) display << _MC_(x) << endl
#define DEBUG2(x, y) display << _MC_(x) << _MC_(y) << endl
#define DEBUG3(x, y, z) display << _MC_(x) << _MC_(y) << _MC_(z) << endl
#define DEBUG4(x, y, z, w) display << _MC_(x) << _MC_(y) << _MC_(z) << _MC_(w) << endl;
#else
#define display cout
#define LOG(x)
#define DEBUG(x)
#define DEBUG2(x, y)
#define DEBUG3(x, y, z)
#define DEBUG4(x, y, z, w)
#endif

void solve () {
  ll n;
  cin >> n;

  vector<ll> st;
  while (n--) {
    ll x;
    cin >> x;

    if (x == 1) {
      st.push_back(x);
    } else {
      while (!st.empty() && st.back() != x-1) st.pop_back();

      if (st.empty()) {
        st.push_back(x);
      } else {
        st.pop_back();
        st.push_back(x);
      }
    }

    for (ll i = 0; i < st.size() - 1; ++i) {
      cout << st[i] << ".";
    }
    cout << st.back() << endl;
  }
}

int main() { 
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) solve();
}

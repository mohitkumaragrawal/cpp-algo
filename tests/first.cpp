#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n;
  cin >> n;

  set<string> st;

  for (ll i = 0; i < n; ++i) {
    string person, res;
    cin >> person >> res;

    if (res == "yes") {
      st.insert(person);

      ll cnt;
      cin >> cnt;

      for (ll j = 0; j < cnt; ++j) {
        string f;
        cin >> f;

        st.insert(f);
      }
    }
  }

  cout << st.size() << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

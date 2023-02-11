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
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll n;
ll a[100005], b[100005];
bool ok;

void fix_range(ll l, ll r) {
  ll mn = *min_element(b + l, b + r + 1);
  ll delta = 1 - mn;

  if (l > 0) {
    if (b[l] + delta == b[l - 1]) delta++;
  }

  ll mx = *max_element(b + l, b + r + 1);
  mx += delta;
  if (mx > 5) {
    ok = false;
    return;
  }

  for (ll i = l; i <= r; ++i) b[i] += delta;
}

void fill_range(ll l, ll r) {
  set<ll> st;
  for (ll i = 1; i <= 5; ++i) st.insert(i);

  if (l > 0) st.erase(b[l - 1]);
  if (r < n - 1) st.erase(b[r + 1]);

  ll arr[2];

  arr[0] = *st.begin();
  auto itr = st.begin();
  itr++;

  arr[1] = *itr;

  ll t = 0;

  for (ll i = l; i <= r; ++i) {
    b[i] = arr[t];
    t = (1 - t);
  }
}

void solve() {
  ok = true;
  cin >> n;
  for (ll i = 0; i < n; ++i) cin >> a[i];

  b[0] = 0;
  b[n] = 0;

  for (ll i = 1; i < n; ++i) {
    if (a[i] == a[i - 1])
      b[i] = 0;
    else if (a[i] > a[i - 1])
      b[i] = b[i - 1] + 1;
    else
      b[i] = b[i - 1] - 1;
  }

  ll z = 0;
  for (ll i = 1; i <= n; ++i) {
    if (b[i] == 0) {
      if (z < i - 1) {
        fix_range(z, i - 1);
      }
      z = i;
    }
  }

  if (!ok) {
    cout << "-1\n";
    return;
  }

  ll i = 0;
  while (i < n) {
    if (b[i] == 0) {
      ll j = i;
      while ((j + 1) < n && b[j + 1] == 0) j++;

      fill_range(i, j);
      i = j;
    }
    i++;
  }

  for (i = 0; i < n; ++i) {
    cout << b[i] << " \n"[i == n - 1];
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}

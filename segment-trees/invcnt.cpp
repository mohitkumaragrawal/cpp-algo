#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll count_inversion(ll* arr, ll l, ll r) {
  if (r > l) {
    ll mid = (l + r) / 2;

    ll leftinv = count_inversion(arr, l, mid);
    ll rightinv = count_inversion(arr, mid + 1, r);

    ll n1 = mid - l + 1;
    ll n2 = r - mid;

    ll* leftarr = new ll[n1];
    ll* rightarr = new ll[n2];

    for (ll j = 0; j < n1; ++j) {
      leftarr[j] = arr[j + l];
    }

    for (ll j = 0; j < n2; ++j) {
      rightarr[j] = arr[mid + 1 + j];
    }

    ll left = 0, right = 0, i = l;
    ll inv = leftinv + rightinv;

    while (left < n1 && right < n2) {
      if (leftarr[left] < rightarr[right]) {
        arr[i] = leftarr[left];
        ++i;
        ++left;
      } else {
        inv += (n1 - left);
        arr[i] = rightarr[right];
        ++i;
        ++right;
      }
    }

    while (left < n1) {
      arr[i] = leftarr[left];
      ++i;
      ++left;
    }

    while (right < n2) {
      arr[i] = rightarr[right];
      ++i;
      ++right;
    }

    delete[] leftarr;
    delete[] rightarr;

    return inv;
  }

  return 0;
}

ll n;
ll a[200005];

void solve() {
  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
  }

  ll inv = count_inversion(a, 0, n - 1);
  cout << inv << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

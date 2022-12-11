#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll a[100005];

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;

  ll MX = m * n - 4;
  priority_queue<ll> pq;

  for (ll i = 0; i < k; ++i) cin >> a[i];
  ll REQ = k;

  for (ll i = 0; i < k; ++i) {
    if (a[i] == REQ) {
      REQ--;

      while (!pq.empty() && pq.top() == REQ) {
        pq.pop();
        REQ--;
      }

      continue;
    }

    if (pq.size() == MX) {
      cout << "TIDAK\n";
      return;
    }

    pq.push(a[i]);
  }
  cout << "YA\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

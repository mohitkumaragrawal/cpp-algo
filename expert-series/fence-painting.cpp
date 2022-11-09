#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

ll N, M;
ll a[100005], b[100005], c[100005], ans[100005];
map<ll, vector<ll>> mp;

void solve() {
  cin >> N >> M;
  for (ll i = 0; i < N; ++i) cin >> a[i];
  for (ll i = 0; i < N; ++i) cin >> b[i];
  for (ll i = 0; i < M; ++i) cin >> c[i];

  bool last_one = false;
  for (ll i = 0; i < N; ++i) {
    if (b[i] == c[M - 1]) {
      last_one = true;
      ans[M - 1] = i;
      break;
    }
  }

  if (!last_one) {
    cout << "NO" << endl;
    return;
  }

  for (ll i = 0; i < N; ++i) {
    if (a[i] != b[i]) {
      mp[b[i]].push_back(i);
    }
  }

  for (ll i = M - 1; i >= 0; --i) {
    ll color = c[i];
    auto& vec = mp[color];

    if (vec.size() > 0) {
      ll idx = vec.back();
      vec.pop_back();

      a[idx] = color;
      ans[i] = idx;
    } else {
      ans[i] = ans[M - 1];
    }
  }

  bool success = true;
  for (ll i = 0; i < N; ++i) {
    if (a[i] != b[i]) {
      success = false;
      break;
    }
  }
  if (!success) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (ll i = 0; i < M; ++i) {
      cout << ans[i] + 1 << " ";
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

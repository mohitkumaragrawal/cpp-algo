#include <bits/stdc++.h>
#define all(x) begin(x), end(x)

using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

ll N;
ll arr[200005];

void solve() {
  cin >> N;
  for (ll i = 0; i < N; ++i) cin >> arr[i];


  priority_queue<ll, vector<ll>, greater<ll>> min_heap;
  ll sum = 0;

  for (ll i = 0; i < N; ++i) {
    if (sum + arr[i] >= 0) {
      sum += arr[i];
      min_heap.push(arr[i]);
    } else if (!min_heap.empty()) {
      ll el = min_heap.top();
      if (el < arr[i]) {
        min_heap.pop();
        min_heap.push(arr[i]);
        sum += arr[i] - el;
      }
    }
  }

  cout << min_heap.size() << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}

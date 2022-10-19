#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void build_tree(const vector<ll>& arr, vector<ll>& seg_tree, ll node_low,
                ll node_high, ll idx) {
  //
  if (node_low == node_high) {
    seg_tree[idx] = arr[node_low];
    return;
  }

  ll mid = (node_low + node_high) / 2;
  build_tree(arr, seg_tree, node_low, mid, 2 * idx);
  build_tree(arr, seg_tree, mid + 1, node_high, 2 * idx + 1);

  seg_tree[idx] = seg_tree[2 * idx] + seg_tree[2 * idx + 1];
}

ll calc_sum_helper(const vector<ll>& arr, const vector<ll>& seg_tree,
                   ll query_low, ll query_high, ll nd, ll node_low,
                   ll node_high) {
  //
  if (query_low <= node_low && query_high >= node_high) {
    return seg_tree[nd];
  }
  if (query_high < node_low || query_low > node_high) {
    return 0;
  }

  ll mid = (node_low + node_high) / 2;
  return calc_sum_helper(arr, seg_tree, query_low, query_high, 2 * nd, node_low,
                         mid) +
         calc_sum_helper(arr, seg_tree, query_low, query_high, 2 * nd + 1,
                         mid + 1, node_high);
}

ll calc_sum(const vector<ll>& arr, const vector<ll>& seg_tree, ll left,
            ll right) {
  return calc_sum_helper(arr, seg_tree, left, right, 1, 0, arr.size() - 1);
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  ll N;
  cin >> N;

  vector<ll> arr(N);
  for (ll& i : arr) cin >> i;

  vector<ll> segtree(4 * N, -1);
  build_tree(arr, segtree, 0, N - 1, 1);

  for (ll i = 1; i < 4 * N; ++i) {
    cout << segtree[i] << " ";
  }
  cout << endl;

  ll Q;
  cin >> Q;
  while (Q--) {
    ll low, high;
    cin >> low >> high;

    cout << calc_sum(arr, segtree, low, high) << endl;
  }
}

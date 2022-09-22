#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

vector<int> parent;
vector<int> sz;

int find_set(int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}

int union_sets(int a, int b) {
  int p1 = find_set(a);
  int p2 = find_set(b);

  if (p1 == p2) return p1;

  if (sz[p2] > sz[p1]) swap(p1, p2);
  parent[p2] = p1;
  sz[p1] += sz[p2];
  return p1;
}

int get_size(int v) { return sz[find_set(v)]; }

int main() {
  int N, M;
  cin >> N >> M;

  parent.resize(N + 1);
  for (int i = 1; i <= N; ++i) parent[i] = i;

  sz.assign(N + 1, 1);
  while (M--) {
    int k;
    cin >> k;
    if (k == 0) continue;

    int first;
    cin >> first;

    for (int i = 1; i < k; ++i) {
      int el;
      cin >> el;
      union_sets(first, el);
    }
  }

  for (int i = 1; i <= N; ++i) {
    cout << get_size(i) << " ";
  }
  cout << endl;
}
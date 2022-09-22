#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct DSU {
  DSU(int limit = 10000) : limit(limit) {
    parent.assign(limit, -1);
    size.assign(limit, 0);
  }

  int make_set(int v) {
    parent[v] = v;
    size[v] = 1;
    return v;
  }

  int find_set(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find_set(parent[v]);
  }

  int union_sets(int a, int b) {
    int p1 = find_set(a);
    int p2 = find_set(b);
    if (p1 == p2) return p1;

    if (size[p2] > size[p1]) swap(p1, p2);

    parent[p2] = p1;
    size[p1] += size[p2];
    return p1;
  }

 private:
  int limit = 10000;
  vector<int> parent;
  vector<int> size;
};

int main() {}
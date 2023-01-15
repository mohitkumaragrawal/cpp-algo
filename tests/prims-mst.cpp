#include <bits/stdc++.h>
using namespace std;

const int V = 5;

int minKey(int key[], bool mstSet[]) {
  int min_el = INT_MAX, min_index;

  for (int u = 0; u < V; ++u) {
    if (!mstSet[u] && key[u] < min_el) {
      min_el = key[u];
      min_index = u;
    }
  }
  return min_index;
}

void primsMST(int graph[V][V]) {
  int key[V], parent[V];
  bool mstSet[V];

  for (int i = 0; i < V; ++i) {
    key[i] = INT_MAX;
    mstSet[i] = false;
  }

  key[0] = 0;
  parent[0] = -1;

  for (int count = 0; count < V - 1; ++count) {
    int u = minKey(key, mstSet);
    mstSet[u] = true;

    for (int v = 0; v < V; ++v) {
      if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
        parent[v] = u, key[u] = graph[u][v];
      }
    }
  }
}

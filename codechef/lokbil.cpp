// TODO: Implement it with BREADTH FIRST SEARCH;

#include <limits.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int N;

vector<vector<int>> graph(101);

double findAverageDistance(int node) {
  vector<bool> visited(N + 1, false);
  queue<int> q;
  visited[node] = true;
  q.push(node);

  vector<int> dist(N + 1);
  dist[node] = 0;

  while (!q.empty()) {
    int x = q.front();
    q.pop();

    for (int child : graph[x]) {
      if (visited[child]) continue;

      q.push(child);
      visited[child] = true;
      dist[child] = dist[x] + 1;
    }
  }

  int sum = 0;
  for (int x = 1; x <= N; ++x) {
    sum += dist[x];
  }

  return (double)sum / N;
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
      graph[i].clear();
    }

    string tmp;

    for (int i = 1; i <= N; ++i) {
      string line;
      getline(cin, line);

      while (line.empty()) {
        getline(cin, line);
      }

      for (char ch : line) {
        if (isspace(ch)) {
          int val = stoi(tmp);
          graph[i].push_back(val);
          tmp.clear();
        } else {
          tmp.push_back(ch);
        }
      }
      if (!tmp.empty()) {
        int val = stoi(tmp);
        tmp.clear();
        graph[i].push_back(val);
      }
    }

    int node = 1;
    double avgdist = findAverageDistance(node);

    for (int i = 2; i <= N; ++i) {
      double d = findAverageDistance(i);

      if (d < avgdist) {
        avgdist = d;
        node = i;
      }
    }

    cout << node << " " << fixed << setprecision(6) << avgdist << endl;
  }
}
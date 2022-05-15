#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> movements = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int find_shorted_part(const vector<string>& grid, int r, int c) {
  queue<pair<int, int>> q;

  // total number of nodes in the graph;
  int n = grid.size() * grid[0].size();

  // which nodes are already visited;
  vector<bool> visisted(n + 1, false);

  // distance fron (r,c) to the corresponding node;
  vector<int> dist(n + 1);

  // previous node or the parent node of any paricular node;
  vector<pair<int, int>> prev(n + 1);

  // function used to map the two ordered pair into a single number representing
  // the node index;
  auto nd = [&](const pair<int, int>& pr) {
    return pr.first * grid[0].size() + pr.second;
  };

  // is a given node valid??
  auto valid = [&](const pair<int, int>& pr) -> bool {
    if (pr.first >= 0 && pr.first < grid.size() && pr.second >= 0 &&
        pr.second < grid[0].size())
      return grid[pr.first][pr.second] != '#';

    return false;
  };

  /**
   * SOLVE SECTION;
   **/

  // from where did our search begin?
  auto start_pair = make_pair(r, c);

  // add the start_pair to the queue in order to proecess it later;
  q.push(start_pair);

  // trivial distance;
  dist[nd(start_pair)] = 0;

  // now we visited the start_node;
  visisted[nd(start_pair)] = true;

  // we will find the end node;
  pair<int, int> end_pair = {-1, -1};

  while (!q.empty()) {
    // get the first pending item from the queue;
    auto parent = q.front();
    q.pop();

    for (auto mv : movements) {
      auto child =
          make_pair(parent.first + mv.first, parent.second + mv.second);

      auto child_node = nd(child);

      if (!valid(child) || visisted[child_node]) continue;

      // we got the child node;
      prev[child_node] = parent;
      visisted[child_node] = true;
      dist[child_node] = dist[nd(parent)] + 1;

      // add the child to the queue in order to process it later;
      q.push(child);

      if (grid[child.first][child.second] == 'E') {
        // found the end node;
        end_pair = child;

        // found the end node, now just empty the queue;
        while (!q.empty()) q.pop();
        break;
      }
    }
  }

  if (end_pair.first == -1) {
    // didn't found any path
    return -1;
  }

  /**
   * RECONSTRUCT THE PATH;
   **/

  vector<pair<int, int>> path;
  auto itr = end_pair;

  while (true) {
    path.push_back(itr);

    if (grid[itr.first][itr.second] == 'S') {
      break;
    }
    itr = prev[nd(itr)];
  }

  /**
   * PRINT THE PATH IF FOUND;
   **/

  for (int x = path.size() - 1; x >= 0; --x) {
    cout << "(" << path[x].first << ", " << path[x].second << ") ";
    if (x != 0) cout << "-> ";
  }
  cout << endl;

  /**
   * RETURNS THE SHORTEST DISTANCE
   **/
  return dist[nd(end_pair)];
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    int m, n;
    cin >> m >> n;

    vector<string> grid(m);
    for (auto& x : grid) cin >> x;

    cout << find_shorted_part(grid, 0, 0) << endl;
  }
}
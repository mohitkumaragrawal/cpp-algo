#include <iostream>
#include <vector>
using namespace std;

bool organizing_containers(int N, vector<vector<int>>& containers) {
  vector<int> containerCapacity(N, 0);
  vector<int> ballsCount(N, 0);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      containerCapacity[i] += containers[i][j];
      ballsCount[j] += containers[i][j];
    }
  }

  for (int i = 0; i < N; ++i) {
    bool found = false;

    for (int j = 0; j < N; ++j) {
      if (containerCapacity[j] == ballsCount[i]) {
        found = true;
        containerCapacity[j] = 0;
        break;
      }
    }

    if (!found) {
      return false;
    }
  }

  return true;
}

int main() {
  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int N;
    cin >> N;
    vector<vector<int>> containers(N, vector<int>(N));
    for (int x = 0; x < N; ++x) {
      for (int y = 0; y < N; ++y) {
        cin >> containers[x][y];
      }
    }
    auto result = organizing_containers(N, containers);
    if (result) {
      cout << "Possible" << endl;
    } else {
      cout << "Impossible" <<endl;
    }
  }
}
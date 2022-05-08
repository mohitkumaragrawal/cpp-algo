#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> groups(N);
  for (int& i : groups) cin >> i;

  vector<int> ships(M);
  for (int& i : ships) cin >> i;

  sort(groups.begin(), groups.end());
  sort(ships.begin(), ships.end());

  if (ships.back() < groups.back()) {
    cout << -1 << endl;
    return 0;
  }

  int groups_left = groups.size();
  int time_passed = 0;

  bool dispatched = false;

  while (groups_left > 0) {
    if (dispatched) {
      // means there are no planes at the source;
      time_passed++;
      dispatched = false;
    }
    int loaded = 0;

    for (int i = 0; i < min(M, groups_left); ++i) {
      if (ships[M - i - 1] < groups[groups_left - i - 1]) break;

      loaded++;
    }

    // now dispatch the groups;
    groups_left -= loaded;
    time_passed++;
    dispatched = true;
  }

  cout << time_passed << endl;
}
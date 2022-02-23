#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using List = std::vector<int>;

List leaderboard(const List& ranked, const List& player) {
  List rank(ranked.size());
  rank[0] = 1;
  for (int i = 1; i < ranked.size(); ++i) {
    if (ranked[i]==ranked[i-1]) {
      rank[i] = rank[i-1];
    } else {
      rank[i] = rank[i-1] + 1;
    }
  }

  int i = ranked.size() - 1;
  List result;

  for (auto score: player) {
    while (ranked[i] < score && i >= 0) {
      i--;
    }
    if (ranked[i] == score) {
      result.push_back(rank[i]);
    } else if (ranked[i] > score) {
      result.push_back(rank[i] + 1);
    } else {
      result.push_back(1);
    }
  }

  return result;
}

int main() {
  freopen("climb-leaderboard.txt", "r", stdin);

  int m;
  std::cin >> m;
  List ranked(m);
  for (int j = 0; j < m; ++j) {
    std::cin >> ranked[j];
  }

  int n;
  std::cin >> n;
  List player(n);
  for (int j = 0; j < n; ++j) {
    std::cin >> player[j];
  }

  auto result = leaderboard(ranked, player);
  for (auto el: result) {
    std::cout << el << '\n';
  }

}
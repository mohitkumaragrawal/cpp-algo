#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compareProblems(const pair<int, int>& p1, const pair<int, int>& p2) {
  if (p1.first == p2.first) return p1.second < p2.second;
  return p1.first < p2.first;
}

int calculateProblemScore(vector<pair<int, int>>& subtsks) {
  sort(subtsks.begin(), subtsks.end());

  int score = 0;
  for (int k = 0; k < subtsks.size() - 1; ++k) {
    if (subtsks[k].second > subtsks[k + 1].second) ++score;
  }
  return score;
}

int main() {
  int P, S;
  cin >> P >> S;

  vector<pair<int, int>> problems;

  for (int i = 1; i <= P; ++i) {
    vector<int> sc(S);
    vector<int> nc(S);

    for (int& i : sc) cin >> i;
    for (int& i : nc) cin >> i;

    vector<pair<int, int>> subtsk;
    for (int i = 0; i < S; ++i) {
      subtsk.push_back(make_pair(sc[i], nc[i]));
    }

    int n = calculateProblemScore(subtsk);
    problems.push_back(make_pair(n, i));
  }

  sort(problems.begin(), problems.end(), compareProblems);
  for (auto pr : problems) {
    cout << pr.second << endl;
  }
}
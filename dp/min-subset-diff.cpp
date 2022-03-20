#include <iostream>
#include <vector>
#include <set>

using namespace std;

int minSubsetDiff(vector<int>& A) {
  set<int> possibleSums;
  possibleSums.insert(0);

  int S = 0;
  for (int i : A) {
    S += i;
  }

  int Ans = S;

  for (int i: A) {
    vector<int> ns;
    for (int s: possibleSums) {
      int newSum = i + s;
      ns.push_back(newSum);

      Ans = min(Ans, abs((2*newSum)-S));
    }

    for (int j : ns) {
      possibleSums.insert(j);
    }
  }
  return Ans;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int &i:A) cin >> i;

  int result = minSubsetDiff(A);
  cout << result << endl;
}
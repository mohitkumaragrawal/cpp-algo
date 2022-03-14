#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int magSq(int x, int y) {
  return (x * x) + (y * y);
}

int calculateValue(vector<int>& X, vector<int>& Y, vector<int>& A, int r) {
  int value = 0;
  int N = X.size();
  for (int i = 0; i < N; ++i) {
    if (magSq(X[i], Y[i]) <= (r*r)) {
      value += A[i];
    }
  }
  return value;
}

int findMinimumRadius(vector<int>& X, vector<int>& Y, vector<int>& A, int N, int p) {
  int rMin = 1;
  int rMaxSq = magSq(X[0], Y[0]);
  for (int i = 1; i < N; ++i) {
    int newRSq = magSq(X[i], Y[i]);
    if (newRSq > rMaxSq) {
      rMaxSq = newRSq;
    }
  }
  int rMax = (int) ceil(sqrt(rMaxSq));

  int result = -1;
  while (rMax >= rMin) {
    int r = rMin + (rMax - rMin) / 2;
    int val = calculateValue(X, Y, A, r);

    if (val >= p) {
      result = r;
      rMax = r-1;
    } else {
      rMin = r+1;
    }
  }
  return result;
}

int main() {
  int TESTCASES;
  cin >> TESTCASES;

  while (TESTCASES--) {
    int N, p;
    cin >> N >> p;
    vector<int> X(N), Y(N), A(N);
    for (auto& el: X) cin >> el;
    for (auto& el: Y) cin >> el;
    for (auto& el: A) cin >> el;
    cout << findMinimumRadius(X, Y, A, N, p) << endl;
  }
}
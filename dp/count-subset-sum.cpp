#include <iostream>
#include <vector>
using namespace std;

int countWays(vector<int>& A, int N, int S) {
  if (S == 0) return 1;
  if (N == 0) return 0;

  int Key = A[N-1];
  
  if (Key <= S) {
    return countWays(A, N-1, S-Key) + countWays(A, N-1, S);
  }
  return countWays(A, N-1, S);
}

int main() {
  int N;
  vector<int> A(N);
  for (int& i: A) cin >> i;

  int S;
  cin >> S;
}
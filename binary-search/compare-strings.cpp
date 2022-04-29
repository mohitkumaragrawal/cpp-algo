#include <iostream>
#include <string>
#include <vector>

using namespace std;

// returns if A is lexographically smaller than B, assuming both have same size;
bool compare(const string& A, const string& B) {
  for (int i = 0; i < A.size(); ++i) {
    if (A[i] > B[i]) {
      return false;
    } else if (A[i] < B[i]) {
      return true;
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, Q;
  cin >> N >> Q;

  string A, B;
  cin >> A >> B;

  vector<int> qi;
  for (int i = 0; i < Q; ++i) {
    int idx;
    cin >> idx;
    qi.push_back(idx - 1);
  }

  int low = 0;
  int high = Q;
  int k = -1;

  while (true) {
    if (high < low) break;

    int mid = low + (high - low) / 2;
    string Bcopy(B.begin(), B.end());

    for (int i = 0; i <= mid; ++i) {
      Bcopy[qi[i]] = '1';
    }

    if (compare(Bcopy, A)) {
      low = mid + 1;
    } else {
      k = mid;
      high = mid - 1;
    }
  }

  if (k == -1) {
    while (Q--) {
      cout << "NO" << endl;
    }
    return 0;
  }

  for (int i = 0; i < k; ++i) {
    cout << "NO" << endl;
  }
  for (int i = k; i < Q; ++i) {
    cout << "YES" << endl;
  }
}
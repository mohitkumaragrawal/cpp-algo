#include <iostream>
using namespace std;

int main() {
  int m;
  cin >> m;

  int ranked[m];
  for (int j = 0; j < m; ++j) {
    cin >> ranked[j];
  }

  int n;
  cin >> n;
  int player[n];
  for (int j = 0; j < n; ++j) {
    cin >> player[j];
  }

  int rank[m];
  rank[0] = 1;
  for (int i = 1; i < m; ++i) {
    if (ranked[i] == ranked[i-1]) {
      rank[i] = rank[i-1];
    } else {
      rank[i] = rank[i-1] + 1;
    }
  }

  int pointer = m-1;
  for (int i = 0; i < n; ++i) {
    int playerscore = player[i];

    // find a pointer such that ranked[pointer] is either equal to or greater than playerscore
    // if not such pointer found, pointer is 0;
    while (ranked[pointer] < playerscore && pointer > 0 ) {
      pointer--;
    }

    int playerrank;
    if (ranked[pointer] == playerscore) {
      // same rank
      playerrank = rank[pointer];
    } else if (playerscore < ranked[pointer]) {
      playerrank = rank[pointer] + 1;
    } else {
      playerrank = 1;
    }

    cout << playerrank << endl;
  }
}
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
    // if not such pointer found, pointer is either 0 or -1;
    while (ranked[pointer] < playerscore && pointer > 0 ) {
      pointer--;
    }

    int playerrank;
    // now, here, playerscore is either equal to ranked[pointer] or less than ranked[pointer]
    if (ranked[pointer] == playerscore) {
      // same rank
      playerrank = rank[pointer];
    } else if (playerscore < ranked[pointer]) {
      // player scored less than ranked[pointer]
      playerrank = rank[pointer] + 1;
    } else {
      // if playerscored is more than the maximum of ranked[pointer] then playerrank is always 1.
      playerrank = 1;
    }

    cout << playerrank << endl;
  }
}
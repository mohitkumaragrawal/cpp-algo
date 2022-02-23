#include <iostream>
#include <vector>
#include <array>
using namespace std;

void print_absolute_permutation(int n, int k) {
  vector<int> P(n+1);
  vector<bool> used(n+1, false);

  auto in_range = [n](int choice) -> bool {
    if (choice >= 1 && choice <= n) {
      return true;
    }
    return false;
  };

  for (int i = 1; i <= n; ++i) {
    int choice1 = i - k;
    int choice2 = i + k;

    bool choice1available = in_range(choice1) && !used[choice1];
    bool choice2available = in_range(choice2) && !used[choice2];

    if (!choice1available && !choice2available) {
      cout << -1 << endl;
      return;
    }

    if (choice1available && !choice2available) {
      used[choice1] = true;
      P[i] = choice1;
    } else if (!choice1available & choice2available) {
      used[choice2] = true;
      P[i] = choice2;
    } else {
      P[i] = choice1;
      used[choice1] = true;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << P[i] << " ";
  }
  cout << endl;
}

int main() {
  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    print_absolute_permutation(n, k);
  }
}
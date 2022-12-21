#include <iostream>

using ll = long long;

void towerOfHanoi(ll n, char src, char dest, char helper) {
  if (n == 0) return;

  // First we will transfer all objects except the last one to the helper
  towerOfHanoi(n - 1, src, helper, dest);

  // Now the transfer the last to the destination
  std::cout << "Move " << src << " To " << dest << std::endl;

  // At last transfer all the remaining blocks from helper to dest.
  towerOfHanoi(n - 1, helper, dest, src);
}

int main() {
  freopen("towerofhanoi.txt", "r", stdin);

  ll n;
  std::cin >> n;

  towerOfHanoi(n, 'A', 'C', 'B');
}

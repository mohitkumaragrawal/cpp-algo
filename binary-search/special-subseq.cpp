#include <cmath>
#include <iostream>
using namespace std;

using ll = long long;

int get_count(int i) {
  double sqrti = sqrt((double)i);
  int k = i;
  if (k & 1) k++;
  k /= 2;
  return i * (int)floor(sqrti) + k;
}

// maximum distinct: 228653
int main() {
  int arr[101];
  for (int i = 1; i < 100; ++i) {
    arr[i] = get_count(i);
    cout << "i: " << arr[i] << endl;
  }

  ll sum = 0;
  ll i = 1;
  while (sum < 10000000000000) {
    sum += get_count(i);
    i++;
  }

  cout << i << " " << sum << endl;
}
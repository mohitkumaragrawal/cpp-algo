#include <iostream>
#include <vector>

using namespace std;

void swap_two_arrays(vector<int>& a, vector<int>& b, int n, int offset = 0) {
  int left = offset;
  int right = offset + n - 1;

  if (right >= a.size()) return;

  while ((right) >= offset) {
    swap(a[left], b[right]);
    left++;
    right--;
  }

  for (int i = offset; i < offset+n; ++i) {
    if ((n+i) >= a.size()) break;
    swap(a[n+i], b[n+i]);
  }

  swap_two_arrays(a, b, n, offset+2*n);
}

void print(vector<int> x) {
  for (int i = 0; i < x.size(); ++i) {
    cout << x[i] << " ";
  }
}

int main() {
  vector<int> a = {2, 3, 1, 0, 9, 7, 7, 4, 3, 1, 9, 5};
  vector<int> b = {5, 9, 4, 3, 7, 5, 1, 0, 6, 8, 5, 4};

  swap_two_arrays(a, b, 2);
  print(a); cout << endl;
  print(b); cout << endl;

  vector<int> a1 = {2, 3, 1, 0, 9, 7, 7, 4, 3, 1, 9, 5};
  vector<int> b1 = {5, 9, 4, 3, 7, 5, 1, 0, 6, 8, 5, 4};
  swap_two_arrays(a1, b1, 4);
  print(a1); cout << endl;
  print(b1); cout << endl;
}
#include <iostream>
#include <vector>
using namespace std;

void partition(vector<int>& arr) {
  int pivot = arr[0];

  vector<int> less;
  vector<int> more;

  for (auto el: arr) {
    if (el < pivot) {
      less.push_back(el);
    }
    if (el > pivot) {
      more.push_back(el);
    }
  }

  int j = 0;
  for (auto el: less) {
    arr[j] = el;
    ++j;
  }
  arr[j] = pivot;
  ++j;

  for (auto el: more) {
    arr[j] = el;
    ++j;
  }
}

int main() {
  int N; cin >> N;
  vector<int> arr(N);
  for (auto& i: arr) cin >> i;
  partition(arr);

  for (auto el: arr) {
    cout << el << ' ';
  } cout << endl;
}
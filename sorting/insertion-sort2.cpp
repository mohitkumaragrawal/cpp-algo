#include <iostream>
#include <vector>
using namespace std;

void show_complete_insertion_sort(vector<int>& arr, int N) {
  for (int i = 1; i < N; ++i) {
    int j = i;
    int pivot = arr[i];
    while (arr[j-1] > pivot && j > 0) {
      arr[j] = arr[j-1];
      j--;
    }
    arr[j] = pivot;

    for (auto el: arr) {
      cout << el << " ";
    }cout << endl;
  }
}

int main() {
  int N; cin >> N;
  vector<int> arr(N);
  for (auto& el: arr) cin >> el;

  show_complete_insertion_sort(arr, N);
}

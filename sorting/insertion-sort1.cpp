#include <iostream>
#include <vector>
using namespace std;

void show_insertion_sort(vector<int>& arr, int N) {
  // the arr is sorted till arr[0...N-2] goal is to insert arr[N-1]

  int pivot = arr[N-1];
  int j = N-1;

  while ((arr[j-1] > pivot)&&(j>0)) {
    arr[j] = arr[j-1];
    j--;

    for (auto el: arr) {
      cout << el << " ";
    }cout << endl;
  }
  arr[j] = pivot;
  for (auto el: arr) {
    cout << el << " ";
  }cout << endl;
}

int main() { 
  int N; cin >> N;
  vector<int> arr(N);

  for (auto& el: arr) cin >> el;

  show_insertion_sort(arr, N);
}
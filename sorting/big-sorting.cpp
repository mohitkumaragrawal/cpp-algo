#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool cmp(const string& a, const string & b) {
  if (a.size() > b.size()) return false;
  if (a.size() < b.size()) return true;
  
  auto sz = a.size();
  for (int i = 0; i < sz; ++i) {
    char c1 = a[i];
    char c2 = b[i];
    
    if (c1 > c2) {
      return false;
    }
    if (c1 < c2) {
      return true;
    }
  }
  return false;
}

// Simply implementing quick sort algo
void QuickSort(vector<string>& arr, int left, int right) {
  if (right > left) {

    int partition = left-1; // partition index;

    for (int i = left; i < right; ++i) {
      if (cmp(arr[i], arr[right])) {
        partition++;
        swap(arr[partition], arr[i]);
      }
    }
    swap(arr[partition+1], arr[right]);

    // now just run QuickSort on the remaining stuff
    int pivotIndex = partition + 1;
    QuickSort(arr, left, pivotIndex - 1);
    QuickSort(arr, pivotIndex+1, right);
  }
}

int main() {
  freopen("big-sorting-input.txt", "r", stdin);
  freopen("big-sorting-output.txt", "w", stdout);
  int N;
  cin >> N;

  vector<string> arr;
  for (int i = 0; i < N; ++i) {
    string tmp;
    cin >> tmp;
    arr.push_back(tmp);
  }
  QuickSort(arr, 0, arr.size()-1);

  for (auto el: arr) {
    cout << el << endl;
  }
}
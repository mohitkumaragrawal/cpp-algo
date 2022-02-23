#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void almost_sorted(int n, vector<int>& arr) {
  vector<int> copied(arr.begin(), arr.end());
  sort(copied.begin(), copied.end());
  
  vector<int> m;
  for (int i = 0; i < n; ++i) {
    if (copied[i] != arr[i]) {
      m.push_back(i);
    }
  }
  if (m.size() == 0) {
    cout << "yes" << endl;
  } else if(m.size() == 2) {
    cout << "yes" << endl;
    cout << "swap " << m[0] + 1 << " " << m[1]+1 << endl;
  } else {
    int m_min = m[0], m_max = m[m.size()-1];
    
    for (int i = m_min; i <= m_max-1; ++i) {
      if (arr[i] < arr[i+1]) {
        cout << "no" <<endl;
        return;
      }
    }
    cout << "yes" << endl;
    cout << "reverse " << m_min+1<<" " <<m_max+1<<endl;
  }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& el: arr) cin >> el;
    almost_sorted(n, arr);
}

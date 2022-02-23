#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(
    vector<int>& a, vector<int>& b) 
  {
    auto total = a.size() + b.size();
    auto half = total / 2;

    if (a.size() > b.size()) swap(a, b);

    int l = 0, r = a.size() - 1;
    while (true) {
      int i = (l + r) / 2;
      if (l+r < 0) i = -1;

      int j = (half - i - 2);

      int Aleft = (i >= 0) ? a[i] : INT_MIN;
      int Aright = ((i + 1) < a.size()) ? a[i + 1] : INT_MAX;
      int Bleft = (j >= 0) ? b[j] : INT_MIN;
      int Bright = (j + 1 < b.size()) ? b[j + 1] : INT_MAX; 

      if (Aleft <= Bright && Bleft <= Aright) {
        if (total % 2 == 1) {
          return min(Bright, Aright);
        }
        return (max(Aleft, Bleft) + min(Bright, Aright)) / 2.0;
      } else if (Aleft > Bright) {
        r = i - 1;
      } else if (Bleft > Aright){
        l = i + 1;
      } else {
        return 0.0;
      }
    }

    return 0.0;
  }
};

int main() {
  vector<int> a = {2};
  vector<int> b = {1,3};

  auto result = Solution().findMedianSortedArrays(a, b);
  cout << result << endl;
}

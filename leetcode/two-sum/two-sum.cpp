#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int targetSum) {
    unordered_map<int, int> exists; // map between element to index;
    for (int i = 0; i < nums.size(); ++i) {
      exists[nums[i]] = i;
    }

    for (int iFirstNum = 0; iFirstNum < nums.size(); ++iFirstNum) {
      int firstNum = nums[iFirstNum];
      int requiredNum = targetSum - firstNum;
      if (exists.find(requiredNum) != exists.end()) {
        int iSecondNum = exists[requiredNum];
        if (iFirstNum == iSecondNum) {
          continue;
        }

        return vector<int> {iFirstNum, iSecondNum};
      }
    }
    // can't find the sum;
    return vector<int>();
  }
};
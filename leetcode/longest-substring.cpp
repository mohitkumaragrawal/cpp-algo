#include <string>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string& str) {
    // stores the count of every character, in our window;
    int chars[128];

    // initially our windows doesn't contain anything
    for (int i = 0; i < 128; ++i) chars[i] = 0;

    // [left, right] (inclusive) of our sliding window;
    int right = 0, left = 0;

    // result;
    int res = 0;

    while (right < str.size()) {
      // pushing the right character in our sliding window;
      char right_char = str[right];
      chars[right_char]++;

      // if the right_char already exists in the sliding window;
      // we need to pop from front in order to remove duplicates;
      while (chars[right_char] > 1) {
        // pop from front in our sliding window;
        char left_char = str[left];
        chars[left_char]--;
        left++;
      }
      // update our result;
      res = max(res, (right - left + 1));

      // and lets move on to next character;
      ++right;
    }

    // return our answer;
    return res;
  }
};

int main() {
  Solution sol;
  string test_str = "abcabca";
  auto result = sol.lengthOfLongestSubstring(test_str);

  printf("%d", result);
}
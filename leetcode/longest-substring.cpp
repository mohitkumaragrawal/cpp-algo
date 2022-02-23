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

class Solution2 {
public:
  int lengthOfLongestSubstring(string& str) {
    // it stores the index of characters in the window;
    int mp[128]; // {'a': 0, 'b': 1}
    for (int i = 0; i < 128; ++i) mp[i] = -1;

    // str = abba

    int result = 0; // result = 2
    int left = 0, right = 0; // left = 2, right = 2
    while (right < str.size()) {
      int r_char = str[right]; // r_char = b

      // if it exists in the window;
      if (mp[r_char] != -1) {
        // if mp[r_char] is already out of my window, then don't update left;
        left = max(left, mp[r_char] + 1);
      }

      mp[r_char] = right;
      result = max(result, (right - left + 1));
      right++;
    }

    return result;
  }
};

int main() {
  Solution sol;
  string test_str = "abcabca";
  auto result = sol.lengthOfLongestSubstring(test_str);

  printf("%d", result);
}
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  vector<int> MultiplyOneDigit(string& firstNum, char secondNumberDigit, int numZeros) {
    vector<int> currentResult(numZeros, 0);
    int carry = 0;

    for (char firstNumDigit: firstNum) {
      int mul = (secondNumberDigit - '0') * (firstNumDigit - '0') + carry;

      carry = mul / 10;
      currentResult.push_back(mul % 10);
    }
    if (carry > 0) {
      currentResult.push_back(carry);
    }
    return currentResult;
  }

  string SumResults(vector<vector<int>>& results) {
    vector<int> answer = results.back();
    vector<int> newAnswer;
    results.pop_back();

    // this just do (answer = answer + result);
    // first does newAnswer = answer + result, and then
    // answer = newAnswer; kaboom!
    for (vector<int> result: results) {
      int carry = 0;
      newAnswer.clear();
      int maxSize = max(answer.size(), result.size());

      for (int i = 0; i < maxSize; ++i) {
        int digit1 = (i < result.size()) ? result[i] : 0;
        int digit2 = (i < answer.size()) ? answer[i] : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        newAnswer.push_back(sum % 10);
      }
      if (carry) {
        answer.push_back(carry);
      }
      answer = newAnswer;
    }

    string finalAnswer;
    for (int digit: answer) {
      finalAnswer.push_back(digit +'0');
    }
    return finalAnswer;
  }
public:
  string MultiplyString(string firstNum, string secondNum) {
    if (firstNum == "0" || secondNum == "0") {
      return "0";
    }

    // First we need to reverse the strings;
    reverse(firstNum.begin(), firstNum.end()); // O(M)
    reverse(secondNum.begin(), secondNum.end()); // O(N)

    vector<vector<int>> results;
    for (int i = 0; i < secondNum.size(); ++i) { // O(M N)
      results.push_back(MultiplyOneDigit(firstNum, secondNum[i], i));
    }

    string answer = SumResults(results);
    reverse(answer.begin(), answer.end());
    return answer;
  }
};

int main() {
  string a, b;
  cin >> a >> b;

  string result = (Solution()).MultiplyString(a, b);
  cout << result << endl;
}
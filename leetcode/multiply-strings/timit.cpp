#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

struct sol1 {
  string stringify(vector<int> tmp) {
    int carry = 0;
    for (int i = tmp.size() - 1; i >= 0; --i) {
      int el = tmp[i] + carry;
      carry = el / 10;
      el %= 10;
      tmp[i] = el;
    }
    string result;
    if (carry > 0) {
      result.append(to_string(carry));
      carry = 0;
    }
    for (auto el: tmp) {
      result.push_back((char)(el + '0'));
    }
    return result;
  }
  void mul_with_10_power(string& num, int power) {
    while(power--) num.push_back('0');
  }
  string mul_with_digit(const string& num1, int digit) {
    vector<int> tmp;
    for (auto ch: num1) {
      int product = (int)(ch - '0') * digit;
      tmp.push_back(product);
    }
    return stringify(tmp);
  }
  string sum_strings(string a, string b) {
    if (a.size() < b.size()) {
      swap(a, b);
    }
    vector<int> tmp;
    for (int i = 0; i < a.size(); ++i) {
      int a_i = a.size() - i - 1;
      int b_i = b.size() - i - 1;
      int sum = (int)(a[a_i] - '0');
      if (b_i >= 0) {
          sum += (int)(b[b_i] - '0');
      }
      tmp.push_back(sum);
    }
    vector<int> reversed;
    for (int i = tmp.size()-1; i >= 0; --i) {
      reversed.push_back(tmp[i]);
    }
    return stringify(reversed);
  }
  
  string multiply(string num1, string num2) {
    if (num1.size() < num2.size()) {
        swap(num1, num2);
    }
    vector<string> partial_products;
    for (int i = num2.size()-1; i >= 0; --i) {
        string prod = mul_with_digit(num1, (int)(num2[i]-'0'));
        int zeros = num2.size() - i - 1;
        while(zeros--) {
            prod.push_back('0');
        }
        partial_products.push_back(prod);
    }
    string result = "0";
    for (auto& s: partial_products) {
        result = sum_strings(result, s);
    }
    return result;
  }
};

struct sol2 {
  string multiply(string a, string b) {
    if (a == "0" || b == "0") return "0";
    int m = a.size(), n = b.size();
    int L = m+n;

    vector<int> sum(m+n-1, 0);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        sum[i+j] += (a[i]-'0') * (b[j]-'0');
      }
    }

    int carry = 0;
    for (int i = sum.size() - 1; i > 0; --i) {
      carry = sum[i] / 10;
      sum[i] %= 10;

      sum[i-1] += carry;
    }

    string ans;
    // there is a possibility that sum[0] is two-digit number;
    if (sum[0] > 9) {
      ans.push_back((sum[0]/10)+'0');
      ans.push_back((sum[0]%10) +'0');
    } else {
      ans.push_back(sum[0] + '0');
    }

    for (int i = 1; i < sum.size(); ++i) {
      ans.push_back(sum[i] + '0');
    }
    return ans;
  }
};

template<typename Multiplier>
struct Factorial {
  string calcFactorial(int N) {
    Multiplier m;
    string s = "1";
    for (int i = 2; i <= N; ++i) {
      string with = to_string(i);
      s = m.multiply(s, with);
    }
    return s;
  }
};

// finds the factorial of 1 through 100;
template<typename Sol, int N>
struct Timit {
  static long long calc_miliseconds() {
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
      Factorial<Sol> f;
      f.calcFactorial(i);
    }

    auto end = chrono::high_resolution_clock::now();

    auto dur = (end - start);

    // for lossy conversions we need to use duration_cast;
    return chrono::duration_cast<chrono::milliseconds>(dur).count();
  }
};

int main() {
  auto s2 = Timit<sol2, 100>::calc_miliseconds();
  auto s1 = Timit<sol1, 100>::calc_miliseconds();

  auto dur1 = s1;
  auto dur2 = s2;

  auto ratio = dur1 / dur2;

  cout << "time taken by sol1 is " << dur1 << "ms" << endl;
  cout << "time taken by sol2 is " << dur2 << "ms" << endl;

  cout << "solution 2 is " << ratio  << " folds faster than solution 1" << endl;

}
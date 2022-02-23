#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
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

int main() {
    Solution s;
    vector<int> num = {12, 12};
    cout << s.multiply("2", "3") << endl;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll a, b;

vector<ull> max_dig;
void init_max_dig() {
  ull p = 10;
  max_dig.resize(15);
  for (int i = 1; i <= 14; ++i) {
    max_dig[i] = p - 1;
    p *= 10;
  }
}

vector<ull> dig_count;
ll count_digit_numbers(int dig) {
  if (dig_count[dig] != -1) return dig_count[dig];

  if (a > max_dig[dig]) {
    return dig_count[dig] = 0;
  }

  // we neeed to solve a + nb <= max_dig[dig];
  // n <= 1/b (max_dig[dig] - a)
  ll res = ((max_dig[dig] - a) / b) + 1;

  for (int i = 1; i < dig; ++i) {
    res -= count_digit_numbers(i);
  }
  return res;
}

ll find_number_of_digits(ll num) { return to_string(num).size(); }

// finds the number of digits that came upto nth index;
ll calc_digits(ll n) {
  if (n == 0) return 0;
  ll digs = find_number_of_digits(a + (n - 1) * b);

  ll res = 0, cnt = 0;
  for (int i = 1; i <= digs - 1; ++i) {
    cnt += count_digit_numbers(i);
    res += i * count_digit_numbers(i);
  }

  res += digs * (n - cnt);
  return res;
}

int main() {
  init_max_dig();

  int T;
  cin >> T;
  while (T--) {
    ll k;
    cin >> a >> b >> k;
    dig_count.assign(15, -1);
    dig_count[0] = 0;

    ll low = 1, high = k;
    ll ans = high;

    while (high >= low) {
      ll mid = (low + high) / 2;

      ll digs = calc_digits(mid);

      if (digs >= k) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    ll idx = k - calc_digits(ans - 1) - 1;
    string num = to_string(a + (ans - 1) * b);
    cout << num[idx] << endl;
  }
}
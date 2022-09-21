#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll a, b, N;

ll hcf(ll a, ll b) {
  if (b == 0) return a;
  return hcf(b, a % b);
}

void solve() {
  ll low = 1, high = 1e+9;

  ll lcm = (a * b) / hcf(a, b);

  while (high >= low) {
    ll mid = (low + high) / 2;

    ll rank = (mid / a) + (mid / b) - (mid / lcm);
    bool valid = (mid % a == 0) || (mid % b == 0);

    if (rank == N && valid) {
      cout << mid << endl;
      return;
    }

    if (rank >= N) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
}

ll low_bound(ll key, ll a) {
  ll low = 1, high = 1e+10;
  ll ans = -1;
  while (high >= low) {
    ll mid = (high + low) / 2;

    ll val = mid * a;
    if (val >= key) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

void solve2() {
  ll lcm = (a * b) / hcf(a, b);
  ll low = 1, high = 1e+9;

  // searching in a first;
  while (high >= low) {
    ll i = (high + low) / 2;
    ll val = a * i;

    ll j = low_bound(val, b);
    ll k = low_bound(val, lcm);

    ll rank = (i + j - k);
    if (rank == N) {
      cout << val << endl;
      return;
    }

    if (rank > N) {
      high = i - 1;
    } else {
      low = i + 1;
    }
  }

  // searching in b second;
  low = 1, high = 1e+9;
  while (high >= low) {
    ll i = (high + low) / 2;
    ll val = b * i;

    ll j = low_bound(val, a);
    ll k = low_bound(val, lcm);

    ll rank = (i + j - k);
    if (rank == N) {
      cout << val << endl;
      return;
    }

    if (rank > N) {
      high = i - 1;
    } else {
      low = i + 1;
    }
  }
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> a >> b >> N;
    solve2();
  }
}
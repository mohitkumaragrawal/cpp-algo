#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll s[26], t[26], f[26];

void solve() {
  fill(s, s + 26, 0);
  fill(t, t + 26, 0);

  s[0] = t[0] = 1;
  ll Q;
  cin >> Q;
  while (Q--) {
    ll d, k;
    string str;
    cin >> d >> k >> str;

    fill(f, f + 26, 0);
    for (char ch : str) {
      f[ch - 'a']++;
    }

    if (d == 1)
      for (ll i = 0; i < 26; ++i) s[i] += k * f[i];
    else
      for (ll i = 0; i < 26; ++i) t[i] += k * f[i];

    ll s_max = 0, t_max = 0, s_sum = 0, t_sum = 0;

    for (ll i = 0; i < 26; ++i) {
      if (s[i] != 0) {
        s_max = i;
        s_sum += s[i];
      }

      if (t[i] != 0) {
        t_max = i;
        t_sum += t[i];
      }
    }

    if (t_max > 0) {
      cout << "YES\n";
      continue;
    }

    if (s_sum >= t_sum) {
      cout << "NO\n";
      continue;
    }

    if (s_max > 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    for (auto& i : A) cin >> i;
    for (auto& i : B) cin >> i;

    priority_queue<ll> qa(A.begin(), A.end());
    priority_queue<ll> qb(B.begin(), B.end());

    ll ans = 0;
    while (!qa.empty()) {
      if (qa.top() == qb.top()) {
        qa.pop();
        qb.pop();
        continue;
      }

      if (qa.top() > qb.top()) {
        ll el = to_string(qa.top()).size();
        qa.pop();
        qa.push(el);
      } else {
        ll el = to_string(qb.top()).size();
        qb.pop();
        qb.push(el);
      }
      ++ans;
    }
    cout << ans << endl;
  }
}
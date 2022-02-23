#include <iostream>
#include <deque>
#include <vector>
#include <set>

std::ostream& operator<<(std::ostream& out, const std::deque<int>& q) {
  out << "[ ";
  for (auto i: q) {
    out << i << ", ";
  }
  out << "]";
  return out;
}

int main() {
  freopen("sliding-window.txt", "r", stdin);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);

  for (auto& i: a) {
    std::cin >> i;
  }

  for (auto i : a) {
    std::cout << i << " " << std::endl;
  }

  // std::multiset<int, std::greater<int>> s;
  // std::vector<int> ans;

  // for (int i = 0; i < k; ++i) {
  //   s.insert(a[i]);
  // }

  // ans.push_back(*s.begin());

  // for (int i = k; i < n; ++i) {
  //   s.erase(s.lower_bound(a[i-k]));
  //   s.insert(a[i]);
  //   ans.push_back(*s.begin());
  // }

  // for (auto i: ans) {
  //   std::cout << i << " ";
  // }

  std::deque<int> q;
  std::vector<int> ans;

  for (int i = 0; i < k; ++i) {
    while (!q.empty() && a[q.back()] < a[i]) {
      q.pop_back();
    }
    q.push_back(i);
  }

  std::cout << q << std::endl;
  ans.push_back(q.front());

  for (int i = k; i < n; ++i) {
    while (!q.empty() && q.front() <= (i-k)){
      q.pop_front();
    }

    while (!q.empty() && a[q.back()] < a[i]) {
      q.pop_back();
    }

    q.push_back(i);
    std::cout << q << std::endl;

    ans.push_back(q.front());
  }

  for (auto i: ans) {
    std::cout << a[i] << " ";
  }
}
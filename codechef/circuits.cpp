#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

const double epsilon = 1e-9;

struct base_node {
  virtual double compute(double p) { return p; }
};

struct and_node : public base_node {
  and_node(base_node* node1, base_node* node2) {
    n1 = node1;
    n2 = node2;
  }

  double compute(double p) override {
    return (n1->compute(p) * n2->compute(p));
  }

 private:
  base_node *n1, *n2;
};

struct or_node : public base_node {
  or_node(base_node* node1, base_node* node2) {
    n1 = node1;
    n2 = node2;
  }

  double compute(double p) override {
    double p1 = n1->compute(p);
    double p2 = n2->compute(p);
    return p1 + p2 - p1 * p2;
  }

 private:
  base_node *n1, *n2;
};

void solve() {
  int N;
  cin >> N;

  vector<base_node*> nodes(N + 1, nullptr);

  for (int i = 1; i <= N; ++i) {
    int type;
    cin >> type;

    if (type == 0) {  // input node;
      nodes[i] = new base_node();
    } else if (type == 1) {  // or node;
      int l1, l2;
      cin >> l1 >> l2;

      auto nd = new or_node(nodes[l1], nodes[l2]);
      nodes[i] = nd;
    } else {  // and node;
      int l1, l2;
      cin >> l1 >> l2;

      auto nd = new and_node(nodes[l1], nodes[l2]);
      nodes[i] = nd;
    }
  }

  auto out_node = nodes[N];

  double low = 0;
  double high = 1;

  while (true) {
    if (low > high) break;

    double mid = (low + high) / 2;

    double val = out_node->compute(mid);
    double diff = val - 0.5;

    if (diff < 0) diff = -diff;
    if (diff < epsilon) {
      cout << fixed << setprecision(5) << mid << endl;
      return;
    }

    if (val > 0.5) {
      high = mid;
    } else {
      low = mid;
    }
  }
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    solve();
  }
}
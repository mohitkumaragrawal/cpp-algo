#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

#include "binary-tree.hpp"

void level_order_traversal(node_i* root) {
  if (!root) return;
  queue<node_i*> q;
  q.push(root);

  node_i* t;
  while (!q.empty()) {
    q.push(nullptr);

    t = q.front();
    q.pop();

    while (t != nullptr) { 
      if (t->left_child) {
        q.push(t->left_child);
      }

      if (t->right_child) {
        q.push(t->right_child);
      }

      cout << t->value << ' '; 
      t = q.front();
      q.pop();
    }
    cout << endl;
  }
}

int main() {
  freopen("level-order-traversal.txt", "r", stdin);
  int n; cin >> n;
  vector<int> preorder(n);
  vector<int> inorder(n);
  
  for (auto& i: preorder) cin >> i;
  for (auto& i: inorder) cin >> i;

  auto root = generate_bt_pre(preorder.data(), inorder.data(), n);
  level_order_traversal(root);
  delete_binary_tree(root);
}
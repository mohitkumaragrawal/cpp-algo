#include <iostream>
#include <queue>
#include <vector>

#include "binary-tree.hpp"

using namespace std;

void inorder_display(node_i* root) {
  if (!root) return;
  inorder_display(root->left_child);
  cout << root->value << ' ';
  inorder_display(root->right_child);
}

void preorder_display(node_i* root) {
  if(!root) return;
  cout << root->value << ' ';
  preorder_display(root->left_child);
  preorder_display(root->right_child);
}

int main() {
  freopen("level-sum.txt", "r", stdin);
  int n, k; cin >> n >> k;
  vector<int> preorder(n), inorder(n);
  for (auto& i: preorder) cin >> i;
  for (auto& i: inorder) cin >> i;

  auto root = generate_bt_pre(preorder.data(), inorder.data(), n);

  inorder_display(root);
  cout << endl;

  preorder_display(root);
  cout << endl;
  
  int sum = 0;
  int level = 0;

  if (root == nullptr) {
    cout << 0 << endl;
    return 0;
  }

  queue<node_i*> q;
  q.push(root);

  node_i* t;
  while (!q.empty()) {
    q.push(nullptr);
    t = q.front();
    q.pop();

    while (t != nullptr) {
      if (t->left_child) q.push(t->left_child);
      if (t->right_child) q.push(t->right_child);

      if (level == k) {
        sum += t->value;
      }

      t = q.front();
      q.pop();
    }

    ++level;
  }

  cout << sum << endl;

  cout << "End" << endl;
}
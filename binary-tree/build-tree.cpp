#include <iostream>
#include <vector>
#include "binary-tree.hpp"

using namespace std;

void inorder_display(node_i*root);


void inorder_display(node_i* root) {
  if (!root) return;
  inorder_display(root->left_child);
  cout << root->value << ' ';
  inorder_display(root->right_child);
}

int main() {
  int preorder[] = {1, 2, 4, 3, 5};
  int inorder[] = {4, 2, 1, 5 , 3};

  auto bt = generate_bt_pre(preorder, inorder, 5);
  inorder_display(bt); cout << endl;

  cout << bt->left_child->value << ", " << bt->right_child->value << endl;
  delete_binary_tree(bt);
}
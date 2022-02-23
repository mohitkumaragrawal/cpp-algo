#include <iostream>
#include <vector>
#include <algorithm>

#include "binary-tree.hpp"
using namespace std;

int calc_height(node_i* root) {
  if (!root) return 0;
  return max(calc_height(root->left_child), calc_height(root->right_child)) + 1;
}

int calc_diameter(node_i* root, int& height) { 
  if (!root) {
    height = 0;
    return 0;
  }

  int lh, rh;
  int lDiameter = calc_diameter(root->left_child, lh);
  int rDiameter = calc_diameter(root->right_child, rh);

  height = max(lh, rh) + 1;
  int tDiameter = lh + rh + 1;
  return max({lDiameter, rDiameter, tDiameter});
}

int main() {
  freopen("diameter-and-height.txt", "r", stdin);

  int n; cin >> n;
  vector<int> preorder(n), inorder(n);
  for (int&i: preorder) cin >> i;
  for (int& i: inorder) cin >> i;

  auto root = generate_bt_pre(preorder.data(), inorder.data(), n);
  int height = calc_height(root);

  int _;
  int diameter = calc_diameter(root, _);
  
  cout << "height: " << height << ", diameter: " << diameter << endl;
}
#include <iostream>
#include <vector>

struct node {
  int data;

  node* left;
  node* right;

  node (int val) : data(val) {
    left = nullptr;
    right = nullptr;
  }
};

void preorder_display(node* root) {
  if (!root) return;

  using std::cout;

  cout << root->data << " ";
  preorder_display(root->left);
  preorder_display(root->right);
}

void inorder_display(node* root) {
  if (!root) return;
  using std::cout;

  inorder_display(root->left);
  cout << root->data << " ";
  inorder_display(root->right);
}

void postorder_display(node* root) {
  if (!root) return;

  postorder_display(root->left);
  postorder_display(root->right);
  std::cout << root->data << " ";
}

int main() {
  node* root = new node(1);

  root->left = new node(2);
  root->right = new node(3);

  //     1
  //    / \
  //   2   3
  //  / \
  // 4  5

  root->left->left = new node(4);
  root->left->right = new node(5);

  std::cout << "Preorder: " << std::endl;
  preorder_display(root);
  std::cout << std::endl;

  std::cout << "Inorder: " << std::endl;
  inorder_display(root);
  std::cout << std::endl;

  std::cout << "Postorder: " << std::endl;
  postorder_display(root);
  std::cout <<  std::endl;

}
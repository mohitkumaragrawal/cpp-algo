#pragma once

template<typename T>
struct binary_node {
  using self_type = binary_node<T>;
  using value_type = T;

  self_type* left_child;
  self_type* right_child;
  
  T value;
  binary_node(const T& val) : value(val) {
    left_child = nullptr;
    right_child = nullptr;
  }

  binary_node() = default;
};

using node_i = binary_node<int>;

template<typename T>
void delete_binary_tree(binary_node<T>* head) {
  if (head == nullptr) return;

  delete_binary_tree(head->left_child);
  delete_binary_tree(head->right_child);
  head->left_child = nullptr;
  head->right_child = nullptr;
  delete head;
}

namespace impl {
  int search(int* preorder, int start, int end, int el) {
    for (int i = start; i <= end; ++i) {
      if (preorder[i] == el) return i;
    }
    return -1;
  }

  // works only when there are no duplicates in binary tree; i.e, all elements are distinct;
  node_i* generate_binary_tree_pre(int* preorder, int* inorder, int start, int end, int& idx) {
    using namespace std;
    if (start > end) return nullptr;

    int curr = preorder[idx];
    ++idx;
    node_i* node = new node_i(curr);

    if (start == end) return node;
    int pos = search(inorder, start, end, curr);

    node->left_child = generate_binary_tree_pre(preorder, inorder, start, pos-1, idx);
    node->right_child = generate_binary_tree_pre(preorder, inorder, pos+1, end, idx);

    return node;
  }

  node_i* generate_binary_tree_post(int* postorder, int* inorder, int start, int end, int& idx) {
    if (start > end) return nullptr;
    int curr = postorder[idx];
    idx--;

    auto node = new node_i(curr);
    int pos = search(inorder, start, end, curr);
    node->right_child = generate_binary_tree_post(postorder, inorder, pos+1, end, idx);
    node->left_child = generate_binary_tree_post(postorder, inorder, start, pos-1, idx);

    return node;
  }
}

node_i* generate_bt_pre(int* preorder, int* inorder, int size) {
  int idx = 0;
  return impl::generate_binary_tree_pre(preorder, inorder, 0, size-1, idx);
}

node_i* generate_bt_post(int* postorder, int* inorder, int size) {
  int idx = size-1;
  return impl::generate_binary_tree_post(postorder, inorder, 0, size-1, idx);
}
#include <iostream>
#include <string>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

Matrix make_matrix(const int row, const int col) {
  Matrix mat(row, std::vector<int>(col, 0));
  return std::move(mat);
}
// circular linked list
struct node {
  node(int v) : val(v) {
  }

  node* next;
  int val;
};

// The idea is very simple, i just create a circular linked list representing
// all the elements in the outtermost rectangle, and then move the head the required
// amount, and then replace the elements of mat with that of circular linked list
void rotate_matrix(Matrix& mat, int rot, int l, int r, int t, int b) {
  int rows = b-t+1;
  int cols = r-l+1;

  int perimeter = 2 * (rows + cols - 2);
  int rots = rot % perimeter;

  if (rows <= 1 || cols <= 1) return;

  node* head = new node(mat[t][l]);
  node* curr = head;

  for (int i = l+1; i <= r; ++i) {
    node* n = new node(mat[t][i]);
    curr->next = n;
    curr = n;
  }

  for (int i = t + 1; i <= b; ++i) {
    node* n = new node(mat[i][r]);
    curr->next = n;
    curr = n;
  }

  for (int i = r - 1; i >= l; --i) {
    node* n = new node(mat[b][i]);
    curr->next = n;
    curr = n;
  }

  for (int i = b-1; i >= t+1; --i) {
    node* n = new node(mat[i][l]);
    curr->next = n;
    curr = n;
  }

  curr->next = head; // just to complete the circular loop;
  node* tail = curr;
  curr = head;

  for (int i = 0; i < rots; ++i) {
    curr = curr->next;
  }

  for (int i = l; i <= r; ++i) {
    mat[t][i] = curr->val;
    curr = curr->next;
  }

  for (int i = t + 1; i <= b; ++i) {
    mat[i][r] = curr->val;
    curr = curr->next;
  }

  for (int i = r - 1; i >= l; --i) {
    mat[b][i] = curr->val;
    curr = curr->next;
  }

  for (int i = b-1; i >= t+1; --i) {
    mat[i][l] = curr->val;
    curr = curr->next;
  }

  // cleaup work
  curr = head;
  while (true) {
    if (curr == tail) {
      delete curr;
      break;
    }

    auto next = curr->next;
    delete curr;
    curr = next;
  }

  rotate_matrix(mat, rot, l + 1, r - 1, t + 1, b - 1);
}

int main() {
  freopen("mat-rot.txt", "r", stdin);
  int rows, cols, rot;

  std::cin >> rows >> cols >> rot;

  auto mat = make_matrix(rows, cols);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j< cols; ++j) {
      std::cin >> mat[i][j];
    }
  }

  rotate_matrix(mat, rot, 0, cols-1, 0, rows-1);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      std::cout << mat[i][j] << " ";
    }
    std::cout << "\n";
  }
}
#include <iostream>

struct node {
  int val;
  node* next;

  explicit node(int v): val(v), next(nullptr) {}
};

void display(node* head, int amount) {
  while (head && amount) {
    std::cout << head->val << " -> ";
    head = head->next;

    amount--;
  }
}

std::ostream& operator<<(std::ostream& out, node* node) {
  if (node == nullptr) {
    out << "null";
    return out;
  }

  return out << node->val << " -> " << node->next;
}

void push_back(node*& head, int val) {
  if (head == nullptr) {
    head = new node(val);
    return;
  }

  node* tmp = head;
  while (tmp->next) {
    tmp = tmp->next;
  }

  tmp->next = new node(val);
}

void push_front(node*& head, int val) {
  if (head == nullptr) {
    head = new node(val);
    return;
  }

  auto el = new node(val);
  el->next = head;
  head = el;
}

node* find(node* head, int val) {
  node* tmp = head;
  while(tmp) {
    if (tmp->val == val) {
      return tmp;
    }

    tmp = tmp->next;
  }
  return nullptr;
}

void delete_at_head(node*& head) {
  if (!head) return;

  node* tmp = head;
  head = tmp->next;
  delete tmp;
}

void delete_first(node*& head, int val) {
  if (!head) return;

  if (head->val == val) {
    delete_at_head(head);
    return;
  }

  node* tmp = head;
  while (tmp->next && tmp->next->val != val) {
    tmp = tmp->next;
  }

  if (tmp->next) {
    node* todelete = tmp->next;
    tmp->next = todelete->next;
    delete todelete;
  }
}

void reverse_list(node*& head) {
  if (!head) return;

  node* prev = nullptr;
  node* current = head;
  node* next = head->next;

  while (current) {
    current->next = prev;
    prev = current;
    current = next;
    if (next) {
      next = next->next;
    }
  }

  head = prev;
}

node* reverse_reccursively(node* head) {
  if (!head || !head->next) return head;

  node* rest = reverse_reccursively(head->next);
  head->next->next = head;
  head->next = nullptr;
  return rest;
}


node* reverse_k(node* head, int k) {
  if (!head || !head->next) return head;

  node* prev = nullptr;
  node* curr = head;
  node* next = head->next;

  for (auto i = 0; i < k; ++i) {
    curr->next = prev;

    prev = curr;
    curr = next;

    if (next) {
      next = next->next;
    }
  }

  head->next = reverse_k(curr, k);

  return prev;
}

bool has_cycle(node* head) {
  if (!head || !head->next || !head->next->next) return false;
  
  node* turt = head;
  node* hare = head;

  turt = turt->next;
  hare = hare->next->next;

  while(turt != hare) {
    if (!hare || !hare->next || !hare->next->next) return false;

    turt = turt->next;
    hare = hare->next->next;  
  }

  return true;
}

void remove_cycle(node *& head) {
  if (!head || !head->next || !head->next->next) return;
  
  node* turt = head;
  node* hare = head;

  turt = turt->next;
  hare = hare->next->next;

  while(turt != hare) {
    if (!hare || !hare->next || !hare->next->next) return;

    turt = turt->next;
    hare = hare->next->next;  
  }

  display(hare, 3);
  std::cout << std::endl;
  display(turt, 3);
  std::cout << std::endl;

  hare = head;

  while (hare->next != turt->next) {
    hare = hare->next;
    turt = turt->next;
  }

  if (turt == head) {
    head = head->next;
  }
  turt->next = nullptr;
}

void generate_cycle(node* head, int k) {
  node* b = head;
  while (--k) b = b->next;

  node* a = head;

  while (b->next) {
    b = b->next;
    a = a->next;
  }

  b->next = a;
}

int main() {
  node* head{};
  for (int i = 1; i <= 10; ++i) push_back(head, i);

  std::cout << head << std::endl;
  generate_cycle(head, 10);

  display(head, 20);

  std::cout << std::endl << has_cycle(head) << std::endl;

  remove_cycle(head);

  std::cout << head << std::endl;

}
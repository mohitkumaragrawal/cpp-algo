#include <algorithm>
#include <boost/iterator/iterator_adaptor.hpp>
#include <functional>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct node_base {
  node_base() : m_next(0) {}

  virtual ~node_base() { delete m_next; }

  virtual void print(std::ostream& out) const = 0;

  virtual void double_me() = 0;

  node_base* next() const { return m_next; }

  void append(node_base* node) {
    if (m_next) {
      m_next->append(node);
    } else {
      m_next = node;
    }
  }

 private:
  node_base* m_next;  // next node
};

inline std::ostream& operator<<(std::ostream& out, const node_base& node) {
  node.print(out);
  return out;
}

template <typename T>
struct node : public node_base {
  explicit node(const T& val) : m_value(val) {}

  void print(std::ostream& out) const override { out << m_value; }

  void double_me() override { m_value += m_value; }

 private:
  T m_value;
};

struct node_iterator
    : public boost::iterator_facade<node_iterator, node_base,
                                    boost::forward_traversal_tag> {
  node_iterator() : m_node(0) {}

  explicit node_iterator(node_base* node) : m_node(node) {}

 private:
  friend class boost::iterator_core_access;

  node_base* m_node;

  void increment() { m_node = m_node->next(); }

  bool equal(node_iterator const& node) const {
    return this->m_node == node.m_node;
  }

  node_base& dereference() const { return *m_node; }
};

struct node_doubler {
  void operator()(node_base& node) const { node.double_me(); }
};

int main() {
  float f = 3.2f;

  int k = f;
  std::cout << k << std::endl;
  auto node_head = std::make_unique<node<int>>(node<int>(13));

  node_head->append(new node<std::string>(" Hello "));
  node_head->append(new node<int>(3));

  std::copy(node_iterator(node_head.get()), node_iterator(),
            std::ostream_iterator<node_base>(std::cout));

  std::cout << std::endl;

  std::for_each(node_iterator(node_head.get()), node_iterator(),
                std::bind(&node_base::double_me, node_head.get()));

  std::copy(node_iterator(node_head.get()), node_iterator(),
            std::ostream_iterator<node_base>(std::cout));

  std::cout << std::endl;
}
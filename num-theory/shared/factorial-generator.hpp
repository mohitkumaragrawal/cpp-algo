#pragma once

#include "unary-operators.hpp"

template<typename T, size_t Amount, typename OperationT = modulo_operation<T>>
struct factorial_generator {
  factorial_generator() {
    _factorials[0] = 1;
    _factorials[1] = 1;

    for (size_t i = 2; i < Amount; ++i) {
      _factorials[i] = _operator(i * _factorials[i-1]);
    }
  }

  inline T operator()(size_t n) {
    return _factorials[n];
  }

private:
  T _factorials[Amount];
  OperationT _operator;
};
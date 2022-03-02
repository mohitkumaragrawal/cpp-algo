#pragma once

#include "unary-operators.hpp"

template <typename Number, typename UnaryOp=modulo_operation<Number>>
struct binary_exponentiation {
  Number operator()(Number base, Number power) {
    Number result = 1;
    while (power > 0) {
      if (power & 1) {
        result = _op(result * base);
        power--;
      } else {
        base = _op(base * base);
        power>>=1;
      }
    }
    return result;
  }
private:
  UnaryOp _op;
};
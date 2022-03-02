#pragma once
#define MOD_VAL 1000000007

template<typename T, size_t Mod=MOD_VAL>
struct modulo_operation {
  inline T operator()(T num) {
    return (num % Mod);
  }

  static constexpr T default_mod = MOD_VAL;
};

template<typename T>
struct void_operation {
  inline T operator()(T num) {
    return num;
  }
};

#undef MOD_VAL
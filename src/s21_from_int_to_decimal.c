#include "s21_decimal.h"

int s21_from_int_to_decimal(int int_num, s21_decimal *value) {
  int index = 31;
  init_struct(value);
  if (int_num < 0) {
    set_sign(value, 1);
    int_num *= -1;
  }
  for (unsigned int mask = 0x80000000; mask != 0; mask >>= 1) {
    if (!!(int_num & mask) == 1) {
      set_bits(value, index, 1);
    }
    index--;
  }
  return OK;
}

#include "s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = TRUE;
  int no_zero_num = 0;
  int is_not_equal = 0;
  for (int i = 0; i < 96 && result; i++) {
    if (get_bits(value_1, i) != get_bits(value_2, i)) {
      result = FALSE;
      is_not_equal = 1;
    }
    if (get_bits(value_1, i) || get_bits(value_2, i)) {
      no_zero_num = 1;
    }
  }
  if (get_sign(value_1) != get_sign(value_2) && no_zero_num) {
    result = FALSE;
  } else if (!no_zero_num) {
    result = TRUE;
  } else if (no_zero_num && get_scale(value_1) != get_scale(value_2)) {
    result = FALSE;
  } else if (!is_not_equal && get_scale(value_1) == get_scale(value_2)) {
    result = TRUE;
  }
  return result;
}

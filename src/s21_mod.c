#include "s21_decimal.h"

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  init_struct(result);
  int val_1_sign = get_sign(value_1);
  s21_decimal value_1_copy = value_1;
  int status = do_value_type_mod(value_1, value_2, result);
  if (!status && !get_scale(value_1) && !get_scale(value_2)) {
    set_sign(&value_1, 0);
    set_sign(&value_2, 0);
    other_div(value_1, value_2, result);
    s21_mul(value_2, *result, result);
    s21_sub(value_1, *result, result);
    if (val_1_sign) {
      set_sign(result, 1);
    } else if (!val_1_sign) {
      set_sign(result, 0);
    }
    if (value_2.value_type == S21_INF || value_2.value_type == S21_N_INF) {
      *result = value_1_copy;
    }
  } else if (!status && (get_scale(value_1) || get_scale(value_2))) {
    if (s21_is_greater(value_1, value_2)) {
      s21_decimal zero = {{0, 0, 0, 0}, S21_NORMAL};
      s21_decimal result_2 = {{0, 0, 0, 0}, S21_NORMAL};
      s21_truncate(value_1_copy, &value_1_copy);
      s21_sub(value_1, value_1_copy, &value_1_copy);
      s21_sub(value_1_copy, value_2, &result_2);
      if (s21_is_greater(result_2, zero)) {
        *result = result_2;
      }
    } else if (s21_is_equal(value_1, value_2)) {
      init_struct(result);
    } else if (s21_is_less(value_1, value_2)) {
      *result = value_1;
    }
  }
  return status;
}

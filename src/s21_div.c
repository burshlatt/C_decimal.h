#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  init_struct(result);
  int status = do_value_type_div(value_1, value_2, result);
  int scale = 0;
  int sign_1 = get_sign(value_1);
  int sign_2 = get_sign(value_2);
  s21_decimal value_1_copy = value_1;
  s21_decimal value_2_copy = value_2;
  s21_decimal copy = {0};
  s21_decimal res = {0};
  s21_decimal ten = {{10, 0, 0, 0}, S21_NORMAL};
  s21_decimal zero = {{0, 0, 0, 0}, S21_NORMAL};
  if (!zero_dec(value_1) && value_1.value_type == S21_NORMAL &&
      value_2.value_type == S21_NORMAL && !status) {
    normalization_scale(&value_1_copy, &value_2_copy);
    set_scale(&value_1_copy, 0);
    set_scale(&value_2_copy, 0);
    other_div(value_1_copy, value_2_copy, result);
    s21_mod(value_1_copy, value_2_copy, &res);
    for (int i = 0; scale < 28 && s21_is_not_equal(res, zero); i++) {
      while (s21_is_less(res, value_2_copy) != 0) {
        s21_mul(res, ten, &res);
        scale++;
      }
      copy = res;
      s21_mod(res, value_2_copy, &res);
      other_div(copy, value_2_copy, &copy);
      set_scale(&copy, scale);
      s21_add(*result, copy, result);
    }
    if ((sign_1 && !sign_2) || (!sign_1 && sign_2)) {
      set_sign(result, 1);
    } else if ((!sign_1 && !sign_2) || (sign_1 && sign_2)) {
      set_sign(result, 0);
    }
  }
  return status;
}

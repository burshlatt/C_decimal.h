#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  init_struct(result);
  *result = value;
  int sign = get_sign(value);
  set_sign(&value, 0);
  int scale = get_scale(value);
  s21_decimal divider = {{10, 0, 0, 0}, S21_NORMAL};
  for (int i = 0; i < scale; i++) {
    other_div(*result, divider, result);
  }
  set_scale(result, 0);
  set_sign(result, sign);
  return OK;
}

#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  if (get_sign(value) == 0) {
    s21_truncate(value, result);
  } else {
    s21_decimal value_copy = value;
    s21_decimal one = {{1, 0, 0, 0}, S21_NORMAL};
    set_sign(&value_copy, 0);
    s21_truncate(value_copy, result);
    s21_add(*result, one, result);
    set_sign(result, 1);
  }
  return OK;
}

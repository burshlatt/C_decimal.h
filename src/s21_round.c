#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int status = OK;
  s21_decimal one = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal int_part = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal float_part = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal comparison = {{5, 0, 0, 1 << 16}, S21_NORMAL};
  s21_floor(value, &int_part);
  s21_sub(value, int_part, &float_part);
  if (s21_is_greater_or_equal(float_part, comparison)) {
    clear_decimal(result);
    status = s21_add(int_part, one, result);
  } else {
    *result = int_part;
  }
  return status;
}

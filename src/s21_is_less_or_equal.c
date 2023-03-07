#include "s21_decimal.h"

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = FALSE;
  int less = s21_is_less(value_1, value_2);
  int equal = s21_is_equal(value_1, value_2);
  if (less || equal) {
    result = TRUE;
  }
  return result;
}

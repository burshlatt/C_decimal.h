#include "s21_decimal.h"

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = FALSE;
  int greater = s21_is_greater(value_1, value_2);
  int equal = s21_is_equal(value_1, value_2);
  if (greater || equal) {
    result = TRUE;
  }
  return result;
}

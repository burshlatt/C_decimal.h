#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal value, int *int_num) {
  s21_decimal value_copy = value;
  int status = OK;
  int int_num_copy = 0;
  int empty_decimal = 1;
  int scale = get_scale(value);
  for (int i = 0; i < 112; i++) {
    if (get_bits(value, i)) {
      int_num_copy += pow(2, i);
      empty_decimal = 0;
    }
  }
  for (int i = 0; i < scale; i++) {
    int_num_copy /= 10;
  }
  *int_num = int_num_copy;
  if (empty_decimal) {
    *int_num = 0;
  }
  if (get_sign(value)) {
    *int_num *= -1;
  }
  if (is_inf(&value_copy) || scale > 28) {
    status = CONVERSION_ERROR;
    *int_num = 0;
  }
  return status;
}

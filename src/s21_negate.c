#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  init_struct(result);
  *result = value;
  if (!get_sign(value)) {
    set_sign(result, 1);
  } else {
    set_sign(result, 0);
  }
  return OK;
}

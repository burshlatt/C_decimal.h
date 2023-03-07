#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal value, float *fl_num) {
  int status = OK;
  double temp = (double)*fl_num;
  for (int i = 0; i < 96; i++) {
    temp += get_bits(value, i) * pow(2, i);
  }
  temp = temp * pow(10, -get_scale(value));
  if (get_bits(value, 127)) temp = temp * (-1);
  *fl_num = temp;
  if (value.value_type == S21_N_INF) {
    status = CONVERSION_ERROR;
    *fl_num = -INFINITY;
  } else if (value.value_type == S21_INF) {
    status = CONVERSION_ERROR;
    *fl_num = INFINITY;
  } else if (value.value_type == S21_NAN) {
    status = CONVERSION_ERROR;
    *fl_num = NAN;
  } else if (get_scale(value) > 27) {
    status = CONVERSION_ERROR;
    *fl_num = 0;
  }
  return status;
}

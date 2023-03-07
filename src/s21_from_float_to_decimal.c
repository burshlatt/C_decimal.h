#include "s21_decimal.h"

int s21_from_float_to_decimal(float fl_num, s21_decimal *value) {
  init_struct(value);
  int return_value = OK;
  if (isinf(fl_num) || isnan(fl_num)) {
    return_value = CONVERSION_ERROR;
    if (isinf(fl_num)) {
      value->value_type = S21_INF;
    } else if (isnan(fl_num)) {
      value->value_type = S21_NAN;
    }
  } else {
    if (fl_num != 0) {
      int sign = *(int *)&fl_num >> 31;
      int exp = ((*(int *)&fl_num & ~0x80000000) >> 23) - 127;
      double temp = (double)fabs(fl_num);
      int off = 0;
      for (; off < 28 && (int)temp / (int)pow(2, 21) == 0; temp *= 10, off++) {
      }
      temp = round(temp);
      if (off <= 28 && (exp > -94 && exp < 96)) {
        floatbits mant = {0};
        temp = (float)temp;
        for (; fmod(temp, 10) == 0 && off > 0; off--, temp /= 10) {
        }
        mant.fl = temp;
        exp = ((*(int *)&mant.fl & ~0x80000000) >> 23) - 127;
        value->bits[exp / 32] |= 1 << exp % 32;
        for (int i = exp - 1, j = 22; j >= 0; i--, j--)
          if ((mant.ui & (1 << j)) != 0) value->bits[i / 32] |= 1 << i % 32;
        value->bits[3] = (sign << 31) | (off << 16);
      }
    }
  }
  return return_value;
}

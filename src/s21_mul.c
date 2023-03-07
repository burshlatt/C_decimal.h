#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  init_struct(result);
  int status = high_or_low_mul(value_1, value_2, result);
  if (value_1.value_type == S21_NORMAL && value_2.value_type == S21_NORMAL &&
      !status) {
    int val_max_bit;
    int sign_1 = get_sign(value_1);
    int sign_2 = get_sign(value_2);
    int final_scale = get_scale(value_1) + get_scale(value_2);
    set_scale(&value_1, 0);
    set_scale(&value_2, 0);
    if (sign_1 && sign_2) {
      set_sign(&value_1, 0);
      set_sign(&value_2, 0);
    }
    int val1_bin_len = get_first_true_bit(value_1);
    int val2_bin_len = get_first_true_bit(value_2);
    int max_bin_len, min_bin_len;
    s21_decimal dec_max, dec_min;
    if (val1_bin_len > val2_bin_len) {
      max_bin_len = val1_bin_len;
      min_bin_len = val2_bin_len;
      dec_max = value_1;
      dec_min = value_2;
    } else {
      max_bin_len = val2_bin_len;
      min_bin_len = val1_bin_len;
      dec_max = value_2;
      dec_min = value_1;
    }
    s21_decimal decimals_arr[112];
    for (int i = 0; i < 112; i++) {
      init_struct(&decimals_arr[i]);
    }
    for (int i = 0; i <= max_bin_len; i++) {
      val_max_bit = get_bits(dec_max, i);
      if (val_max_bit == 1) {
        for (int j = 0; j <= min_bin_len; j++) {
          if (get_bits(dec_min, j)) {
            set_bits(&decimals_arr[i], j + i, 1);
          }
        }
      }
    }
    for (int i = 0; i <= max_bin_len; i++) {
      if (status != HIGH_NUMBER && status != LOW_NUMBER) {
        status = s21_add(decimals_arr[i], *result, result);
      }
    }
    set_scale(result, final_scale);
    if ((sign_1 && !sign_2) || (!sign_1 && sign_2)) {
      set_sign(result, 1);
    }
    status = decimal_overflow(result);
    if (status) {
      clear_decimal(result);
    }
  } else {
    status = do_value_type_mul(value_1, value_2, result);
  }
  return status;
}

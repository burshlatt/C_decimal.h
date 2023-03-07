#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  init_struct(result);
  int one_in_mind = 0;
  int val_1_bit = 0;
  int val_2_bit = 0;
  int loc_res = 0;
  int status = high_or_low_add(value_1, value_2, result);
  s21_decimal value_1_copy = value_1;
  s21_decimal value_2_copy = value_2;
  if (value_1.value_type == S21_NORMAL && value_2.value_type == S21_NORMAL &&
      !status) {
    if (get_sign(value_1_copy) && !get_sign(value_2_copy)) {
      set_sign(&value_1_copy, 0);
      status = s21_sub(value_1_copy, value_2_copy, result);
      if (!get_sign(*result) && !status) {
        set_sign(result, 1);
      } else if (get_sign(*result) && !status) {
        set_sign(result, 0);
      }
    } else if (!get_sign(value_1_copy) && get_sign(value_2_copy)) {
      set_sign(&value_2_copy, 0);
      status = s21_sub(value_1_copy, value_2_copy, result);
    } else {
      if (get_sign(value_1_copy) && get_sign(value_2_copy)) {
        set_sign(result, 1);
      }
      int scale = normalization_scale(&value_1_copy, &value_2_copy);
      set_scale(result, scale);
      for (int i = 0; i < 112; i++) {
        val_1_bit = get_bits(value_1_copy, i);
        val_2_bit = get_bits(value_2_copy, i);
        loc_res = val_1_bit + val_2_bit + one_in_mind;
        if (one_in_mind == 1) {
          one_in_mind = 0;
        }
        if (loc_res == 1) {
          set_bits(result, i, 1);
        } else if (loc_res == 2) {
          one_in_mind = 1;
        } else if (loc_res == 3) {
          set_bits(result, i, 1);
          one_in_mind = 1;
        }
      }
    }
  } else {
    status = do_value_type_add(value_1, value_2, result);
  }
  if (zero_dec(*result)) {
    set_sign(result, 0);
    set_scale(result, 0);
  }
  return status;
}

#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  init_struct(result);
  int status = high_or_low_sub(value_1, value_2, result);
  int loc_res = 0;
  int val_1_bit = 0;
  int val_2_bit = 0;
  s21_decimal value_1_copy = value_1;
  s21_decimal value_2_copy = value_2;
  if (value_1.value_type == S21_NORMAL && value_2.value_type == S21_NORMAL &&
      !status) {
    if (get_sign(value_1_copy) && !get_sign(value_2_copy)) {
      set_sign(&value_1_copy, 0);
      status = s21_add(value_1_copy, value_2_copy, result);
      if (!status) {
        set_sign(result, 1);
      }
    } else if (!get_sign(value_1_copy) && get_sign(value_2_copy)) {
      set_sign(&value_2_copy, 0);
      status = s21_add(value_1_copy, value_2_copy, result);
    } else if (get_sign(value_1_copy) && get_sign(value_2_copy)) {
      set_sign(&value_2_copy, 0);
      status = s21_add(value_1_copy, value_2_copy, result);
    } else {
      if (s21_is_less(value_1_copy, value_2_copy)) {
        value_1_copy = value_2;
        value_2_copy = value_1;
        set_sign(result, 1);
      }
      int scale = normalization_scale(&value_1_copy, &value_2_copy);
      set_scale(result, scale);
      for (int i = 0; i < 112; i++) {
        val_1_bit = get_bits(value_1_copy, i);
        val_2_bit = get_bits(value_2_copy, i);
        loc_res = val_1_bit - val_2_bit;
        if (loc_res == 1) {
          set_bits(result, i, 1);
        } else if (loc_res == -1) {
          set_bits(result, i, 1);
          int i_copy = i + 1;
          for (int j = 1; get_bits(value_1_copy, i_copy) != 1 && i_copy != 95;
               j++) {
            set_bits(&value_1_copy, i + j, 1);
            i_copy++;
          }
          set_bits(&value_1_copy, i_copy, 0);
        }
      }
    }
  } else {
    status = do_value_type_sub(value_1, value_2, result);
  }
  return status;
}

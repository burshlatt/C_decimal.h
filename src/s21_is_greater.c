#include "s21_decimal.h"

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int status = 3;
  int equal_num = 0;
  int negative_num = 0;
  s21_decimal value_1_copy = value_1;
  s21_decimal value_2_copy = value_2;
  if (!get_sign(value_1) && get_sign(value_2)) {
    status = TRUE;
  } else if (get_sign(value_1) && !get_sign(value_2)) {
    status = FALSE;
  } else if (!s21_is_equal(value_1, value_2)) {
    normalization_scale(&value_1_copy, &value_2_copy);
    if (get_sign(value_1) && get_sign(value_2)) {
      set_sign(&value_1_copy, 0);
      set_sign(&value_2_copy, 0);
      negative_num = 1;
    }
    while (status == 3) {
      int first_true_bit = get_first_true_bit(value_1_copy);
      int second_true_bit = get_first_true_bit(value_2_copy);
      int first_false_bit = get_first_false_bit(value_1_copy);
      int second_false_bit = get_first_false_bit(value_2_copy);
      if (first_true_bit == second_true_bit &&
          first_false_bit == second_false_bit) {
        set_bits(&value_1_copy, first_true_bit, 0);
        set_bits(&value_2_copy, second_true_bit, 0);
      } else {
        if (first_true_bit == second_true_bit &&
            first_false_bit < second_false_bit) {
          status = TRUE;
        } else if (first_true_bit == second_true_bit &&
                   first_false_bit > second_false_bit) {
          status = FALSE;
        } else if (first_true_bit > second_true_bit) {
          status = TRUE;
        } else if (first_true_bit < second_true_bit) {
          status = FALSE;
        }
      }
    }
    if (negative_num && !equal_num) {
      if (status) {
        status = FALSE;
      } else {
        status = TRUE;
      }
    }
  } else {
    status = FALSE;
  }
  if (zero_dec(value_1) && zero_dec(value_2)) {
    status = FALSE;
  }
  return status;
}

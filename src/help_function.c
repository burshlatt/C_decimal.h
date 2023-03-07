#include "s21_decimal.h"

void print_decimal(s21_decimal value) {
  printf("\n");
  for (int i = 0; i < 32; i++) {
    printf("%d ", get_bits(value, i));
  }
  printf("\n");
  for (int i = 32; i < 64; i++) {
    printf("%d ", get_bits(value, i));
  }
  printf("\n");
  for (int i = 64; i < 96; i++) {
    printf("%d ", get_bits(value, i));
  }
  printf("\n");
  for (int i = 96; i < 128; i++) {
    printf("%d ", get_bits(value, i));
  }
  printf("\n\n");
}

void init_struct(s21_decimal *value) {
  clear_decimal(value);
  value->value_type = S21_NORMAL;
}

void clear_decimal(s21_decimal *value) {
  for (int i = 0; i < 128; i++) {
    set_bits(value, i, 0);
  }
}

void clear_bits(s21_decimal *value) {
  for (int i = 0; i < 112; i++) {
    set_bits(value, i, 0);
  }
}

int get_bits(s21_decimal value, int index) {
  unsigned int mask = 1u << (index % 32);
  return !!(value.bits[(int)(index / 32)] & mask);
}

void set_bits(s21_decimal *value, int index, unsigned int change_value) {
  unsigned int mask = 1u << (index % 32);
  if (!change_value) {
    value->bits[(int)(index / 32)] &= ~mask;
  } else if (change_value) {
    value->bits[(int)(index / 32)] |= mask;
  }
}

int get_sign(s21_decimal value) {
  int sign = 0;
  unsigned int mask = 1u << 31;
  sign = value.bits[SCALE] | ~mask;
  if (sign == -1) {
    sign *= -1;
  } else {
    sign = 0;
  }
  return sign;
}

void set_sign(s21_decimal *value, unsigned int change_value) {
  unsigned int mask = 1u << 31;
  if (change_value) {
    value->bits[SCALE] |= mask;
  } else if (!change_value) {
    value->bits[SCALE] &= ~mask;
  }
}

int get_scale(s21_decimal value) {
  int scale_index = 0;
  int scale = 0;
  unsigned int mask = 0;
  for (int i = 16; i < 24; i++) {
    mask = 1u << i;
    scale += !!(value.bits[SCALE] & mask) * pow(2, scale_index);
    scale_index++;
  }
  return scale;
}

void set_scale(s21_decimal *value, unsigned int change_value) {
  int scale = 0;
  int div = change_value;
  int scale_index = 16;
  unsigned int mask = 0;
  for (int i = 7; i >= 0; i--) {
    mask = 1u << scale_index;
    scale = div - (int)(div / 2) * 2;
    div = div / 2;
    if (!scale) {
      value->bits[SCALE] &= ~mask;
    } else if (scale) {
      value->bits[SCALE] |= mask;
    }
    scale_index++;
  }
}

int get_sign_float(float fl_num) {
  unsigned int fl_bits = *((unsigned int *)&fl_num);
  unsigned int mask = 1u << 31;
  return !!(fl_bits & mask);
}

void set_mantiss_from_float(s21_decimal *value, float fl_num, int fl_exp) {
  int index = fl_exp - 1;
  unsigned int fl_bits = *((unsigned int *)&fl_num);
  for (unsigned int mask = 0x400000; mask != 0; mask >>= 1) {
    if (!!(fl_bits & mask) == 1) {
      set_bits(value, index, 1);
    }
    index--;
  }
}

int get_first_true_bit(s21_decimal value) {
  int index = 0;
  int check = 0;
  for (int i = 111; i >= 0 && !check; i--) {
    if (get_bits(value, i)) {
      index = i;
      check = 1;
    }
  }
  if (!check) {
    index = -1;
  }
  return index;
}

int get_first_false_bit(s21_decimal value) {
  int index = 0;
  int flag_end = 0;
  for (int i = 111; i >= 0 && !flag_end; i--) {
    if (get_bits(value, i) && !get_bits(value, i - 1)) {
      index = i - 1;
      flag_end = 1;
    }
  }
  return index;
}

int normalization_scale(s21_decimal *value_1, s21_decimal *value_2) {
  int scale = 0;
  int scale_1 = get_scale(*value_1);
  int scale_2 = get_scale(*value_2);
  s21_decimal ten = {{10, 0, 0, 0}, S21_NORMAL};
  s21_decimal buffer = {{0, 0, 0, 0}, S21_NORMAL};
  if (scale_1 < scale_2) {
    if (get_first_true_bit(*value_1) < 93) {
      for (int i = 0; i < scale_2 - scale_1; i++) {
        s21_mul(*value_1, ten, value_1);
      }
      set_scale(value_1, scale_2);
      scale = scale_2;
    } else {
      for (int i = 0; i < scale_2 - scale_1; i++) {
        bit_div(*value_2, ten, value_2, &buffer);
      }
      set_scale(value_2, scale_1);
      scale = scale_1;
    }
  } else if (scale_1 > scale_2) {
    if (get_first_true_bit(*value_2) < 93) {
      for (int i = 0; i < scale_1 - scale_2; i++) {
        s21_mul(*value_2, ten, value_2);
      }
      set_scale(value_1, scale_2);
      scale = scale_1;
    } else {
      for (int i = 0; i < scale_1 - scale_2; i++) {
        bit_div(*value_1, ten, value_1, &buffer);
      }
      set_scale(value_1, scale_2);
      scale = scale_2;
    }
  } else if (scale_1 == scale_2) {
    scale = scale_1;
  }
  return scale;
}

int max_dec(s21_decimal value) {
  int status = 1;
  for (int i = 0; i < 96 && status == 1; i++) {
    if (!get_bits(value, i)) {
      status = 0;
    }
  }
  if (get_scale(value) != 0) {
    status = 0;
  }
  return status;
}

int zero_dec(s21_decimal value) {
  int status = 1;
  for (int i = 0; i < 112 && status == 1; i++) {
    if (get_bits(value, i)) {
      status = 0;
    }
  }
  return status;
}

void bit_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
             s21_decimal *buffer) {
  init_struct(buffer);
  init_struct(result);
  int index_first_bit = get_first_true_bit(value_1);
  for (int i = index_first_bit; i >= 0; i--) {
    if (get_bits(value_1, i)) {
      set_bits(buffer, 0, 1);
    }
    if (s21_is_greater_or_equal(*buffer, value_2)) {
      s21_sub(*buffer, value_2, buffer);
      if (i != 0) {
        shift_left(buffer, 1);
      }
      if (get_bits(value_1, i - 1)) {
        set_bits(buffer, 0, 1);
      }
      shift_left(result, 1);
      set_bits(result, 0, 1);
    } else {
      shift_left(result, 1);
      if (i != 0) {
        shift_left(buffer, 1);
      }
      if ((i - 1) >= 0 && get_bits(value_1, i - 1)) {
        set_bits(buffer, 0, 1);
      }
    }
  }
}

void shift_left(s21_decimal *value, int index) {
  int first_true_bit = get_first_true_bit(*value);
  if (first_true_bit + index > 111 && !get_sign(*value)) {
    value->value_type = S21_INF;
  } else if (first_true_bit + index > 111 && get_sign(*value)) {
    value->value_type = S21_N_INF;
  } else {
    for (int i = 0; i < index; i++) {
      int left_bit_1 = get_bits(*value, 31);
      int left_bit_2 = get_bits(*value, 63);
      int left_bit_3 = get_bits(*value, 95);
      int scale = get_scale(*value);
      int sign = get_sign(*value);
      value->bits[0] <<= 1;
      value->bits[1] <<= 1;
      value->bits[2] <<= 1;
      value->bits[3] <<= 1;
      set_bits(value, 32, left_bit_1);
      set_bits(value, 64, left_bit_2);
      set_bits(value, 96, left_bit_3);
      for (int i = 112; i < 128; i++) {
        set_bits(value, i, 0);
      }
      set_scale(value, scale);
      set_sign(value, sign);
    }
  }
}

int is_inf(s21_decimal *value) {
  int status = S21_NORMAL;
  s21_decimal max = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}, S21_NORMAL};
  s21_decimal min = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}, S21_NORMAL};
  set_scale(&max, 0);
  set_sign(&max, 0);
  set_scale(&min, 0);
  set_sign(&min, 1);
  if (value->value_type == S21_NORMAL) {
    if (s21_is_greater(*value, max)) {
      status = S21_NAN;
      value->value_type = S21_NAN;
    } else if (s21_is_less(*value, min)) {
      status = S21_NAN;
      value->value_type = S21_NAN;
    } else if (s21_is_greater_or_equal(max, *value) &&
               s21_is_less_or_equal(min, *value)) {
      status = S21_NORMAL;
      value->value_type = S21_NORMAL;
    }
  } else {
    status = value->value_type;
  }
  return status;
}

int other_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  init_struct(result);
  s21_decimal lasting_result;
  init_struct(&lasting_result);
  int i = get_first_true_bit(value_1);
  while (i >= 0) {
    shift_left(&lasting_result, 1);
    int value_to_set = get_bits(value_1, i);
    set_bits(&lasting_result, 0, value_to_set);
    if (s21_is_greater_or_equal(lasting_result, value_2)) {
      s21_sub(lasting_result, value_2, &lasting_result);
      shift_left(result, 1);
      set_bits(result, 0, 1);
    } else {
      shift_left(result, 1);
      set_bits(result, 0, 0);
    }
    i--;
  }
  return 0;
}

int decimal_overflow(s21_decimal *value) {
  int status = S21_NORMAL;
  s21_decimal max = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}, S21_NORMAL};
  s21_decimal min = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}, S21_NORMAL};
  set_scale(&max, 0);
  set_sign(&max, 0);
  set_scale(&min, 0);
  set_sign(&min, 1);
  if (value->value_type == S21_NORMAL) {
    if (s21_is_greater(*value, max)) {
      status = S21_INF;
      value->value_type = S21_INF;
    } else if (s21_is_less(*value, min)) {
      status = S21_N_INF;
      value->value_type = S21_N_INF;
    } else if (s21_is_greater_or_equal(max, *value) &&
               s21_is_less_or_equal(min, *value)) {
      status = S21_NORMAL;
      value->value_type = S21_NORMAL;
    }
  } else {
    status = value->value_type;
  }
  return status;
}

int high_or_low_add(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result) {
  int status = 0;
  if (get_sign(value_1) && get_sign(value_2)) {
    if (max_dec(value_1) && !zero_dec(value_2)) {
      status = LOW_NUMBER;
      clear_decimal(result);
      result->value_type = S21_N_INF;
    } else if (max_dec(value_2) && !zero_dec(value_1)) {
      status = LOW_NUMBER;
      clear_decimal(result);
      result->value_type = S21_N_INF;
    }
  } else if (!get_sign(value_1) && !get_sign(value_2)) {
    if (max_dec(value_1) && !zero_dec(value_2)) {
      status = HIGH_NUMBER;
      clear_decimal(result);
      result->value_type = S21_INF;
    } else if (max_dec(value_2) && !zero_dec(value_1)) {
      status = HIGH_NUMBER;
      clear_decimal(result);
      result->value_type = S21_INF;
    }
  }
  return status;
}

int high_or_low_sub(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result) {
  int status = 0;
  if (get_sign(value_1) && !get_sign(value_2)) {
    if (max_dec(value_1) && !zero_dec(value_2)) {
      status = LOW_NUMBER;
      clear_decimal(result);
      result->value_type = S21_N_INF;
    } else if (!zero_dec(value_1) && max_dec(value_2)) {
      status = LOW_NUMBER;
      clear_decimal(result);
      result->value_type = S21_N_INF;
    }
  } else if (!get_sign(value_1) && get_sign(value_2)) {
    if (max_dec(value_1) && !zero_dec(value_2)) {
      status = HIGH_NUMBER;
      clear_decimal(result);
      result->value_type = S21_INF;
    } else if (!zero_dec(value_1) && max_dec(value_2)) {
      status = HIGH_NUMBER;
      clear_decimal(result);
      result->value_type = S21_INF;
    }
  }
  return status;
}

int high_or_low_mul(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result) {
  int status = 0;
  s21_decimal one = {{1, 0, 0, 0}, S21_NORMAL};
  set_sign(&one, 0);
  set_scale(&one, 0);
  if ((max_dec(value_1) && s21_is_greater(value_2, one)) ||
      (max_dec(value_2) && s21_is_greater(value_1, one))) {
    clear_decimal(result);
    if (!get_sign(value_1) && !get_sign(value_2)) {
      result->value_type = S21_INF;
      status = HIGH_NUMBER;
    } else if (!get_sign(value_1) && get_sign(value_2)) {
      result->value_type = S21_N_INF;
      status = LOW_NUMBER;
    } else if (get_sign(value_1) && !get_sign(value_2)) {
      result->value_type = S21_N_INF;
      status = LOW_NUMBER;
    }
  }
  return status;
}

int do_value_type_add(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal *result) {
  int status = 0;
  int val_stat_1 = is_inf(&value_1);
  int val_stat_2 = is_inf(&value_2);
  if (!val_stat_1 && val_stat_2 == S21_INF) {
    status = HIGH_NUMBER;
    result->value_type = S21_INF;
  } else if (!val_stat_1 && val_stat_2 == S21_N_INF) {
    status = LOW_NUMBER;
    result->value_type = S21_N_INF;
  } else if (val_stat_1 == S21_INF && !val_stat_2) {
    status = HIGH_NUMBER;
    result->value_type = S21_INF;
  } else if (val_stat_1 == S21_INF && val_stat_2 == S21_INF) {
    status = HIGH_NUMBER;
    result->value_type = S21_INF;
  } else if (val_stat_1 == S21_INF && val_stat_2 == S21_N_INF) {
    status = DIVISION_BY_ZERO;
    result->value_type = S21_NAN;
  } else if (val_stat_1 == S21_N_INF && !val_stat_2) {
    status = LOW_NUMBER;
    result->value_type = S21_N_INF;
  } else if (val_stat_1 == S21_N_INF && val_stat_2 == S21_INF) {
    status = DIVISION_BY_ZERO;
    result->value_type = S21_NAN;
  } else if (val_stat_1 == S21_N_INF && val_stat_2 == S21_N_INF) {
    status = LOW_NUMBER;
    result->value_type = S21_N_INF;
  } else if (val_stat_1 == S21_NAN || val_stat_2 == S21_NAN) {
    status = DIVISION_BY_ZERO;
    result->value_type = S21_NAN;
  }
  if (!status) {
    status = is_inf(result);
  } else {
    clear_decimal(result);
  }
  return status;
}

int do_value_type_sub(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal *result) {
  int status = 0;
  int val_stat_1 = is_inf(&value_1);
  int val_stat_2 = is_inf(&value_2);
  if (!val_stat_1 && val_stat_2 == S21_INF) {
    status = LOW_NUMBER;
    result->value_type = S21_N_INF;
  } else if (!val_stat_1 && val_stat_2 == S21_N_INF) {
    status = HIGH_NUMBER;
    result->value_type = S21_INF;
  } else if (val_stat_1 == S21_INF && !val_stat_2) {
    status = HIGH_NUMBER;
    result->value_type = S21_INF;
  } else if (val_stat_1 == S21_INF && val_stat_2 == S21_INF) {
    status = DIVISION_BY_ZERO;
    result->value_type = S21_NAN;
  } else if (val_stat_1 == S21_INF && val_stat_2 == S21_N_INF) {
    status = HIGH_NUMBER;
    result->value_type = S21_INF;
  } else if (val_stat_1 == S21_N_INF && !val_stat_2) {
    status = LOW_NUMBER;
    result->value_type = S21_N_INF;
  } else if (val_stat_1 == S21_N_INF && val_stat_2 == S21_INF) {
    status = LOW_NUMBER;
    result->value_type = S21_N_INF;
  } else if (val_stat_1 == S21_N_INF && val_stat_2 == S21_N_INF) {
    status = DIVISION_BY_ZERO;
    result->value_type = S21_NAN;
  } else if (val_stat_1 == S21_NAN || val_stat_2 == S21_NAN) {
    status = DIVISION_BY_ZERO;
    result->value_type = S21_NAN;
  }
  if (!status) {
    status = is_inf(result);
  } else {
    clear_decimal(result);
  }
  return status;
}

int do_value_type_mul(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal *result) {
  int status = 0;
  int val_stat_1 = is_inf(&value_1);
  int val_stat_2 = is_inf(&value_2);
  int sign_1 = get_sign(value_1);
  int sign_2 = get_sign(value_2);
  if (zero_dec(value_1) && val_stat_2 == S21_INF) {
    status = DIVISION_BY_ZERO;
    result->value_type = S21_NAN;
  } else if (zero_dec(value_1) && val_stat_2 == S21_N_INF) {
    status = DIVISION_BY_ZERO;
    result->value_type = S21_NAN;
  } else if (!val_stat_1 && !sign_1 && val_stat_2 == S21_INF) {
    status = HIGH_NUMBER;
    result->value_type = S21_INF;
  } else if (!val_stat_1 && !sign_1 && val_stat_2 == S21_N_INF) {
    status = LOW_NUMBER;
    result->value_type = S21_N_INF;
  } else if (!val_stat_1 && sign_1 && val_stat_2 == S21_INF) {
    status = LOW_NUMBER;
    result->value_type = S21_N_INF;
  } else if (!val_stat_1 && sign_1 && val_stat_2 == S21_N_INF) {
    status = HIGH_NUMBER;
    result->value_type = S21_INF;
  } else if (val_stat_1 == S21_INF && zero_dec(value_2)) {
    status = DIVISION_BY_ZERO;
    result->value_type = S21_NAN;
  } else if (val_stat_1 == S21_INF && !val_stat_2 && !sign_2) {
    status = HIGH_NUMBER;
    result->value_type = S21_INF;
  } else if (val_stat_1 == S21_INF && !val_stat_2 && sign_2) {
    status = LOW_NUMBER;
    result->value_type = S21_N_INF;
  } else if (val_stat_1 == S21_INF && val_stat_2 == S21_INF) {
    status = HIGH_NUMBER;
    result->value_type = S21_INF;
  } else if (val_stat_1 == S21_INF && val_stat_2 == S21_N_INF) {
    status = LOW_NUMBER;
    result->value_type = S21_N_INF;
  } else if (val_stat_1 == S21_N_INF && zero_dec(value_2)) {
    status = DIVISION_BY_ZERO;
    result->value_type = S21_NAN;
  } else if (val_stat_1 == S21_N_INF && !val_stat_2 && !sign_2) {
    status = LOW_NUMBER;
    result->value_type = S21_N_INF;
  } else if (val_stat_1 == S21_N_INF && !val_stat_2 && sign_2) {
    status = HIGH_NUMBER;
    result->value_type = S21_INF;
  } else if (val_stat_1 == S21_N_INF && val_stat_2 == S21_INF) {
    status = LOW_NUMBER;
    result->value_type = S21_N_INF;
  } else if (val_stat_1 == S21_N_INF && val_stat_2 == S21_N_INF) {
    status = HIGH_NUMBER;
    result->value_type = S21_INF;
  } else if (val_stat_1 == S21_NAN || val_stat_2 == S21_NAN) {
    status = DIVISION_BY_ZERO;
    result->value_type = S21_NAN;
  }
  if (!status) {
    status = is_inf(result);
  } else {
    clear_decimal(result);
  }
  return status;
}

int do_value_type_div(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal *result) {
  int status = 0;
  int val_stat_1 = is_inf(&value_1);
  int val_stat_2 = is_inf(&value_2);
  int sign_1 = get_sign(value_1);
  int sign_2 = get_sign(value_2);
  if (zero_dec(value_1) && zero_dec(value_2)) {
    status = DIVISION_BY_ZERO;
    result->value_type = S21_NAN;
  } else if (!val_stat_1 && !zero_dec(value_1) && !sign_1 &&
             zero_dec(value_2) && value_2.value_type == S21_NORMAL) {
    status = HIGH_NUMBER;
    result->value_type = S21_INF;
  } else if (!val_stat_1 && !zero_dec(value_1) && sign_1 && zero_dec(value_2) &&
             value_2.value_type == S21_NORMAL) {
    status = LOW_NUMBER;
    result->value_type = S21_N_INF;
  } else if (value_1.value_type == S21_INF &&
             (zero_dec(value_2) || (!zero_dec(value_2) && !sign_2)) &&
             value_2.value_type == S21_NORMAL) {
    status = HIGH_NUMBER;
    result->value_type = S21_INF;
  } else if (value_1.value_type == S21_INF && !zero_dec(value_2) && sign_2) {
    status = LOW_NUMBER;
    result->value_type = S21_N_INF;
  } else if (value_1.value_type == S21_INF &&
             (value_2.value_type == S21_INF ||
              value_2.value_type == S21_N_INF)) {
    status = DIVISION_BY_ZERO;
    result->value_type = S21_NAN;
  } else if (value_1.value_type == S21_N_INF &&
             (zero_dec(value_2) || (!zero_dec(value_2) && !sign_2)) &&
             value_2.value_type == S21_NORMAL) {
    status = LOW_NUMBER;
    result->value_type = S21_N_INF;
  } else if (value_1.value_type == S21_N_INF && !zero_dec(value_2) && sign_2) {
    status = HIGH_NUMBER;
    result->value_type = S21_INF;
  } else if (value_1.value_type == S21_N_INF &&
             (value_2.value_type == S21_INF ||
              value_2.value_type == S21_N_INF)) {
    status = DIVISION_BY_ZERO;
    result->value_type = S21_NAN;
  } else if (val_stat_1 == S21_NAN || val_stat_2 == S21_NAN) {
    status = DIVISION_BY_ZERO;
    result->value_type = S21_NAN;
  }
  if (!status) {
    status = is_inf(result);
  } else {
    clear_decimal(result);
  }
  return status;
}

int do_value_type_mod(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal *result) {
  int status = 0;
  int val_stat_1 = is_inf(&value_1);
  int val_stat_2 = is_inf(&value_2);
  if (zero_dec(value_2)) {
    status = DIVISION_BY_ZERO;
    result->value_type = S21_NAN;
  } else if (val_stat_1 == S21_NAN || val_stat_1 == S21_INF ||
             val_stat_1 == S21_N_INF || val_stat_2 == S21_NAN) {
    status = DIVISION_BY_ZERO;
    result->value_type = S21_NAN;
  } else if (!val_stat_1 &&
             (val_stat_2 == S21_INF || val_stat_2 == S21_N_INF)) {
    status = OK;
    result->value_type = S21_NORMAL;
  }
  if (!status) {
    status = is_inf(result);
  } else {
    clear_decimal(result);
  }
  return status;
}

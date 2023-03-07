#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define HIGH_NUMBER 1
#define LOW_NUMBER 2
#define DIVISION_BY_ZERO 3

#define FALSE 0
#define TRUE 1

#define CONVERSION_ERROR 1

#define CALCULATION_ERROR 1

#define MAX_NUM 79228162514264337593543950335.0
#define MIN_NUM -79228162514264337593543950335.0

enum digit { LOW, MID, HIGH, SCALE };

typedef enum {
  S21_NORMAL = 0,
  S21_INF = 1,
  S21_N_INF = 2,
  S21_NAN = 3
} value_type_t;

typedef struct {
  unsigned int bits[4];
  value_type_t value_type;
} s21_decimal;

typedef union {
  int ui;
  float fl;
} floatbits;

int is_inf(s21_decimal *value);
int max_dec(s21_decimal value);
int zero_dec(s21_decimal value);
int decimal_overflow(s21_decimal *value);
int normalization_scale(s21_decimal *value_1, s21_decimal *value_2);
int other_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int high_or_low_add(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result);
int high_or_low_sub(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result);
int high_or_low_mul(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result);
int do_value_type_add(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal *result);
int do_value_type_sub(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal *result);
int do_value_type_mul(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal *result);
int do_value_type_div(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal *result);
int do_value_type_mod(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal *result);

void clear_bits(s21_decimal *value);
void init_struct(s21_decimal *value);
void print_decimal(s21_decimal value);
void clear_decimal(s21_decimal *value);
void shift_left(s21_decimal *value, int index);
void bit_div(s21_decimal dividend, s21_decimal divisor, s21_decimal *result,
             s21_decimal *buffer);

int get_exp_float(float fl_num);
int get_sign(s21_decimal value);
int get_sign_float(float fl_num);
int get_scale(s21_decimal value);
int get_first_true_bit(s21_decimal value);
int get_first_false_bit(s21_decimal value);
int get_bits(s21_decimal value, int index);

void set_sign(s21_decimal *value, unsigned int change_value);
void set_scale(s21_decimal *value, unsigned int change_value);
void set_bits(s21_decimal *value, int index, unsigned int change_value);
void set_mantiss_from_float(s21_decimal *value, float fl_num, int fl_exp);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);

int s21_from_int_to_decimal(int int_num, s21_decimal *value);
int s21_from_decimal_to_int(s21_decimal value, int *int_num);
int s21_from_float_to_decimal(float fl_num, s21_decimal *value);
int s21_from_decimal_to_float(s21_decimal value, float *fl_num);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);

#endif  // SRC_S21_DECIMAL_H_

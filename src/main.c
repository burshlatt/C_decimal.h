#include "s21_decimal.h"

int main() {
  s21_decimal number_1 = {{21, 0, 0, 0 << 16 | 0 << 31}, S21_NORMAL};
  s21_decimal number_2 = {{42, 0, 0, 0 << 16 | 0 << 31}, S21_NORMAL};
  s21_decimal result = {{0, 0, 0, 0 << 16 | 0 << 31}, S21_NORMAL};
  s21_add(number_1, number_2, &result);
  print_decimal(number_1);
  int result_int = 0;
  s21_from_decimal_to_int(result, &result_int);
  printf("int result: %d\n\n", result_int);
  return 0;
}

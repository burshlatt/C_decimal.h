#include <check.h>
#include <math.h>

#include "s21_decimal.h"

START_TEST(s21_add_test) {
  int value_type = 0;
  // Проверка на 0
  // 1
  s21_decimal num_11 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_12 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result1 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_11, num_12, &result1);
  ck_assert_int_eq(result1.bits[0], 0);
  ck_assert_int_eq(result1.bits[1], 0);
  ck_assert_int_eq(result1.bits[2], 0);
  ck_assert_int_eq(result1.bits[3], 0);
  ck_assert_int_eq(result1.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 2
  s21_decimal num_21 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_22 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result2 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_21, num_22, &result2);
  ck_assert_int_eq(result2.bits[0], 1);
  ck_assert_int_eq(result2.bits[1], 0);
  ck_assert_int_eq(result2.bits[2], 0);
  ck_assert_int_eq(result2.bits[3], 0);
  ck_assert_int_eq(result2.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 3
  s21_decimal num_31 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_32 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result3 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_31, num_32, &result3);
  ck_assert_int_eq(result3.bits[0], 1);
  ck_assert_int_eq(result3.bits[1], 0);
  ck_assert_int_eq(result3.bits[2], 0);
  ck_assert_int_eq(result3.bits[3], 2147483648);
  ck_assert_int_eq(result3.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 4
  s21_decimal num_41 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_42 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal result4 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_41, num_42, &result4);
  ck_assert_int_eq(result4.bits[3], 0);
  ck_assert_int_eq(result4.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 5
  s21_decimal num_51 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_52 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal result5 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_51, num_52, &result5);
  ck_assert_int_eq(result5.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 6
  s21_decimal num_61 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_62 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal result6 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_61, num_62, &result6);
  ck_assert_int_eq(result6.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // ПРОВЕРКА НА 1
  // 7
  s21_decimal num_71 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_72 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result7 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_71, num_72, &result7);
  ck_assert_int_eq(result7.bits[0], 1);
  ck_assert_int_eq(result7.bits[1], 0);
  ck_assert_int_eq(result7.bits[2], 0);
  ck_assert_int_eq(result7.bits[3], 0);
  ck_assert_int_eq(result7.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 8
  s21_decimal num_81 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_82 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result8 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_81, num_82, &result8);
  ck_assert_int_eq(result8.bits[0], 2);
  ck_assert_int_eq(result8.bits[1], 0);
  ck_assert_int_eq(result8.bits[2], 0);
  ck_assert_int_eq(result8.bits[3], 0);
  ck_assert_int_eq(result8.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 9
  s21_decimal num_91 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_92 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result9 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_91, num_92, &result9);
  ck_assert_int_eq(result9.bits[0], 0);
  ck_assert_int_eq(result9.bits[1], 0);
  ck_assert_int_eq(result9.bits[2], 0);
  ck_assert_int_eq(result9.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 10
  s21_decimal num_101 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_102 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal result10 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_101, num_102, &result10);
  ck_assert_int_eq(result10.bits[3], 0);
  ck_assert_int_eq(result10.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 11
  s21_decimal num_111 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_112 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal result11 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_111, num_112, &result11);
  ck_assert_int_eq(result11.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 12
  s21_decimal num_121 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_122 = {{3, 0, 0, 0}, S21_NAN};
  s21_decimal result12 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_121, num_122, &result12);
  ck_assert_int_eq(result12.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // ПРОВЕРКА НА -1
  // 13
  s21_decimal num_131 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_132 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result13 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_131, num_132, &result13);
  ck_assert_int_eq(result13.bits[0], 1);
  ck_assert_int_eq(result13.bits[1], 0);
  ck_assert_int_eq(result13.bits[2], 0);
  ck_assert_int_eq(result13.bits[3], 2147483648);
  ck_assert_int_eq(result13.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 14
  s21_decimal num_141 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_142 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result14 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_141, num_142, &result14);
  ck_assert_int_eq(result14.bits[0], 0);
  ck_assert_int_eq(result14.bits[1], 0);
  ck_assert_int_eq(result14.bits[2], 0);
  ck_assert_int_eq(result14.bits[3], 0);
  ck_assert_int_eq(result14.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 15
  s21_decimal num_151 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_152 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result15 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_151, num_152, &result15);
  ck_assert_int_eq(result15.bits[0], 2);
  ck_assert_int_eq(result15.bits[1], 0);
  ck_assert_int_eq(result15.bits[2], 0);
  ck_assert_int_eq(result15.bits[3], 2147483648);
  ck_assert_int_eq(result15.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 16
  s21_decimal num_161 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_162 = {{3, 0, 0, 0}, S21_INF};
  s21_decimal result16 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_161, num_162, &result16);
  ck_assert_int_eq(result16.bits[3], 0);
  ck_assert_int_eq(result16.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 17
  s21_decimal num_171 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_172 = {{3, 0, 0, 2147483648}, S21_N_INF};
  s21_decimal result17 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_171, num_172, &result17);
  ck_assert_int_eq(result17.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 18
  s21_decimal num_181 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_182 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal result18 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_181, num_182, &result18);
  ck_assert_int_eq(result18.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // ПРОВЕРКА НА INF
  // 19
  s21_decimal num_191 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_192 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result19 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_191, num_192, &result19);
  ck_assert_int_eq(result19.bits[3], 0);
  ck_assert_int_eq(result19.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 20
  s21_decimal num_201 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_202 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result20 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_201, num_202, &result20);
  ck_assert_int_eq(result20.bits[3], 0);
  ck_assert_int_eq(result20.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 21
  s21_decimal num_211 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_212 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result21 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_211, num_212, &result21);
  ck_assert_int_eq(result21.bits[3], 0);
  ck_assert_int_eq(result21.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 22
  s21_decimal num_221 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_222 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal result22 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_221, num_222, &result22);
  ck_assert_int_eq(result22.bits[3], 0);
  ck_assert_int_eq(result22.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 23
  s21_decimal num_231 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_232 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal result23 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_231, num_232, &result23);
  ck_assert_int_eq(result23.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 24
  s21_decimal num_241 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_242 = {{1, 0, 0, 0}, S21_NAN};
  s21_decimal result24 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_241, num_242, &result24);
  ck_assert_int_eq(result24.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // ПРОВЕРКА -INF
  // 25
  s21_decimal num_251 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_252 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result25 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_251, num_252, &result25);
  ck_assert_int_eq(result25.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 26
  s21_decimal num_261 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_262 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result26 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_261, num_262, &result26);
  ck_assert_int_eq(result26.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 27
  s21_decimal num_271 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_272 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result27 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_271, num_272, &result27);
  ck_assert_int_eq(result27.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 28
  s21_decimal num_281 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_282 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal result28 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_281, num_282, &result28);
  ck_assert_int_eq(result28.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 29
  s21_decimal num_291 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_292 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal result29 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_291, num_292, &result29);
  ck_assert_int_eq(result29.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 30
  s21_decimal num_301 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_302 = {{1, 0, 0, 0}, S21_NAN};
  s21_decimal result30 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_301, num_302, &result30);
  ck_assert_int_eq(result30.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // ПРОВРЕКА НА NAN
  // 31
  s21_decimal num_311 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_312 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result31 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_311, num_312, &result31);
  ck_assert_int_eq(result31.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 32
  s21_decimal num_321 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_322 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result32 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_321, num_322, &result32);
  ck_assert_int_eq(result32.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 33
  s21_decimal num_331 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_332 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result33 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_331, num_332, &result33);
  ck_assert_int_eq(result33.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 34
  s21_decimal num_341 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_342 = {{1, 0, 0, 2147483648}, S21_INF};
  s21_decimal result34 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_341, num_342, &result34);
  ck_assert_int_eq(result34.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 35
  s21_decimal num_351 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_352 = {{1, 0, 0, 2147483648}, S21_N_INF};
  s21_decimal result35 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_351, num_352, &result35);
  // ck_assert_int_eq(result35.bits[3], 2147483648);
  ck_assert_int_eq(result35.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 36
  s21_decimal num_361 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_362 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal result36 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_361, num_362, &result36);
  // ck_assert_int_eq(result36.bits[3], 2147483648);
  ck_assert_int_eq(result36.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // НОРМАЛЬНЫЕ ТЕСТЫ
  // 37
  s21_decimal num_371 = {{4294967295, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_372 = {{3, 2, 0, 0}, S21_NORMAL};
  s21_decimal result37 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_371, num_372, &result37);
  ck_assert_int_eq(result37.bits[0], 2);
  ck_assert_int_eq(result37.bits[1], 3);
  ck_assert_int_eq(result37.bits[2], 0);
  ck_assert_int_eq(result37.bits[3], 0);
  ck_assert_int_eq(result37.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 38
  s21_decimal num_381 = {{4294967, 0, 0, 2147876864}, S21_NORMAL};
  s21_decimal num_382 = {{13, 0, 0, 0}, S21_NORMAL};
  s21_decimal result38 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_381, num_382, &result38);
  ck_assert_int_eq(result38.bits[0], 8705033);
  ck_assert_int_eq(result38.bits[1], 0);
  ck_assert_int_eq(result38.bits[2], 0);
  ck_assert_int_eq(result38.bits[3], 393216);
  ck_assert_int_eq(result38.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 39
  s21_decimal num_391 = {{13, 12, 40, 2147483648}, S21_NORMAL};
  s21_decimal num_392 = {{32, 33, 5, 2147483648}, S21_NORMAL};
  s21_decimal result39 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_391, num_392, &result39);
  ck_assert_int_eq(result39.bits[0], 45);
  ck_assert_int_eq(result39.bits[1], 45);
  ck_assert_int_eq(result39.bits[2], 45);
  ck_assert_int_eq(result39.bits[3], 2147483648);
  ck_assert_int_eq(result39.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // ПЕРЕПОЛНЕНИЯ
  // 40
  s21_decimal num_401 = {{4294967295, 4294967295, 4294967295, 0}, S21_NORMAL};
  s21_decimal num_402 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result40 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_401, num_402, &result40);
  ck_assert_int_eq(result40.bits[3], 0);
  ck_assert_int_eq(result40.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 41
  s21_decimal num_411 = {{4294967295, 4294967295, 4294967295, 2147483648},
                         S21_NORMAL};
  s21_decimal num_412 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result41 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_411, num_412, &result41);
  // ck_assert_int_eq(result41.bits[3], 2147483648);
  ck_assert_int_eq(result41.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // Обычные
  // 42
  // + +
  s21_decimal num_421 = {{15325, 0, 0, 196608}, S21_NORMAL};
  s21_decimal num_422 = {{129, 0, 0, 131072}, S21_NORMAL};
  s21_decimal result42 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_421, num_422, &result42);
  ck_assert_int_eq(result42.bits[0], 16615);
  ck_assert_int_eq(result42.bits[1], 0);
  ck_assert_int_eq(result42.bits[2], 0);
  ck_assert_int_eq(result42.bits[3], 196608);
  ck_assert_int_eq(result42.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 43
  // - +
  s21_decimal num_431 = {{15325, 0, 0, 2147549184}, S21_NORMAL};
  s21_decimal num_432 = {{9294, 0, 0, 131072}, S21_NORMAL};
  s21_decimal result43 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_431, num_432, &result43);
  ck_assert_int_eq(result43.bits[0], 143956);
  ck_assert_int_eq(result43.bits[1], 0);
  ck_assert_int_eq(result43.bits[2], 0);
  ck_assert_int_eq(result43.bits[3], 2147614720);
  ck_assert_int_eq(result43.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 44
  // + -
  s21_decimal num_441 = {{15325, 0, 0, 65536}, S21_NORMAL};
  s21_decimal num_442 = {{9294, 0, 0, 2147680256}, S21_NORMAL};
  s21_decimal result44 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_441, num_442, &result44);
  ck_assert_int_eq(result44.bits[0], 1523206);
  ck_assert_int_eq(result44.bits[1], 0);
  ck_assert_int_eq(result44.bits[2], 0);
  ck_assert_int_eq(result44.bits[3], 196608);
  ck_assert_int_eq(result44.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 45
  // + -
  s21_decimal num_451 = {{1532513, 0, 0, 2147680256}, S21_NORMAL};
  s21_decimal num_452 = {{9294, 0, 0, 2147745792}, S21_NORMAL};
  s21_decimal result45 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_add(num_451, num_452, &result45);
  ck_assert_int_eq(result45.bits[0], 15334424);
  ck_assert_int_eq(result45.bits[1], 0);
  ck_assert_int_eq(result45.bits[2], 0);
  ck_assert_int_eq(result45.bits[3], 2147745792);
  ck_assert_int_eq(result45.value_type, 0);
  ck_assert_int_eq(value_type, 0);
}

START_TEST(s21_sub_test) {
  int value_type = 0;
  // Проверка на 0
  // 1
  s21_decimal num_11 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_12 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result1 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_11, num_12, &result1);
  ck_assert_int_eq(result1.bits[0], 0);
  ck_assert_int_eq(result1.bits[1], 0);
  ck_assert_int_eq(result1.bits[2], 0);
  ck_assert_int_eq(result1.bits[3], 0);
  ck_assert_int_eq(result1.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 2
  s21_decimal num_21 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_22 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result2 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_21, num_22, &result2);
  ck_assert_int_eq(result2.bits[0], 1);
  ck_assert_int_eq(result2.bits[1], 0);
  ck_assert_int_eq(result2.bits[2], 0);
  ck_assert_int_eq(result2.bits[3], 2147483648);
  ck_assert_int_eq(result2.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 3
  s21_decimal num_31 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_32 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result3 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_31, num_32, &result3);
  ck_assert_int_eq(result3.bits[0], 1);
  ck_assert_int_eq(result3.bits[1], 0);
  ck_assert_int_eq(result3.bits[2], 0);
  ck_assert_int_eq(result3.bits[3], 0);
  ck_assert_int_eq(result3.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 4
  s21_decimal num_41 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_42 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal result4 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_41, num_42, &result4);
  // ck_assert_int_eq(result4.bits[3], 2147483648);
  ck_assert_int_eq(result4.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 5
  s21_decimal num_51 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_52 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal result5 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_51, num_52, &result5);
  ck_assert_int_eq(result5.bits[3], 0);
  ck_assert_int_eq(result5.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 6
  s21_decimal num_61 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_62 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal result6 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_61, num_62, &result6);
  // ck_assert_int_eq(result6.bits[3], 2147483648);
  ck_assert_int_eq(result6.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // ПРОВЕРКА НА 1
  // 7
  s21_decimal num_71 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_72 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result7 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_71, num_72, &result7);
  ck_assert_int_eq(result7.bits[0], 1);
  ck_assert_int_eq(result7.bits[1], 0);
  ck_assert_int_eq(result7.bits[2], 0);
  ck_assert_int_eq(result7.bits[3], 0);
  ck_assert_int_eq(result7.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 8
  s21_decimal num_81 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_82 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result8 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_81, num_82, &result8);
  ck_assert_int_eq(result8.bits[0], 0);
  ck_assert_int_eq(result8.bits[1], 0);
  ck_assert_int_eq(result8.bits[2], 0);
  ck_assert_int_eq(result8.bits[3], 0);
  ck_assert_int_eq(result8.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 9
  s21_decimal num_91 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_92 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result9 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_91, num_92, &result9);
  ck_assert_int_eq(result9.bits[0], 2);
  ck_assert_int_eq(result9.bits[1], 0);
  ck_assert_int_eq(result9.bits[2], 0);
  ck_assert_int_eq(result9.bits[3], 0);
  ck_assert_int_eq(result9.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 10
  s21_decimal num_101 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_102 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal result10 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_101, num_102, &result10);
  // ck_assert_int_eq(result10.bits[3], 2147483648);
  ck_assert_int_eq(result10.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 11
  s21_decimal num_111 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_112 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal result11 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_111, num_112, &result11);
  ck_assert_int_eq(result11.bits[3], 0);
  ck_assert_int_eq(result11.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 12
  s21_decimal num_121 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_122 = {{3, 0, 0, 0}, S21_NAN};
  s21_decimal result12 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_121, num_122, &result12);
  // ck_assert_int_eq(result12.bits[3], 2147483648);
  ck_assert_int_eq(result12.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // ПРОВЕРКА НА -1
  // 13
  s21_decimal num_131 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_132 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result13 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_131, num_132, &result13);
  ck_assert_int_eq(result13.bits[0], 1);
  ck_assert_int_eq(result13.bits[1], 0);
  ck_assert_int_eq(result13.bits[2], 0);
  ck_assert_int_eq(result13.bits[3], 2147483648);
  ck_assert_int_eq(result13.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 14
  s21_decimal num_141 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_142 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result14 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_141, num_142, &result14);
  ck_assert_int_eq(result14.bits[0], 2);
  ck_assert_int_eq(result14.bits[1], 0);
  ck_assert_int_eq(result14.bits[2], 0);
  ck_assert_int_eq(result14.bits[3], 2147483648);
  ck_assert_int_eq(result14.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 15
  s21_decimal num_151 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_152 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result15 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_151, num_152, &result15);
  ck_assert_int_eq(result15.bits[0], 0);
  ck_assert_int_eq(result15.bits[1], 0);
  ck_assert_int_eq(result15.bits[2], 0);
  ck_assert_int_eq(result15.bits[3], 0);
  ck_assert_int_eq(result15.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 16
  s21_decimal num_161 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_162 = {{3, 0, 0, 0}, S21_INF};
  s21_decimal result16 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_161, num_162, &result16);
  // ck_assert_int_eq(result16.bits[3], 2147483648);
  ck_assert_int_eq(result16.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 17
  s21_decimal num_171 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_172 = {{3, 0, 0, 2147483648}, S21_N_INF};
  s21_decimal result17 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_171, num_172, &result17);
  ck_assert_int_eq(result17.bits[3], 0);
  ck_assert_int_eq(result17.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 18
  s21_decimal num_181 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_182 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal result18 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_181, num_182, &result18);
  // ck_assert_int_eq(result18.bits[3], 2147483648);
  ck_assert_int_eq(result18.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // ПРОВЕРКА НА INF
  // 19
  s21_decimal num_191 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_192 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result19 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_191, num_192, &result19);
  ck_assert_int_eq(result19.bits[3], 0);
  ck_assert_int_eq(result19.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 20
  s21_decimal num_201 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_202 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result20 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_201, num_202, &result20);
  ck_assert_int_eq(result20.bits[3], 0);
  ck_assert_int_eq(result20.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 21
  s21_decimal num_211 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_212 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result21 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_211, num_212, &result21);
  ck_assert_int_eq(result21.bits[3], 0);
  ck_assert_int_eq(result21.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 22
  s21_decimal num_221 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_222 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal result22 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_221, num_222, &result22);
  // ck_assert_int_eq(result22.bits[3], 2147483648);
  ck_assert_int_eq(result22.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 23
  s21_decimal num_231 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_232 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal result23 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_231, num_232, &result23);
  ck_assert_int_eq(result23.bits[3], 0);
  ck_assert_int_eq(result23.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 24
  s21_decimal num_241 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_242 = {{1, 0, 0, 0}, S21_NAN};
  s21_decimal result24 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_241, num_242, &result24);
  // ck_assert_int_eq(result24.bits[3], 2147483648);
  ck_assert_int_eq(result24.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // ПРОВЕРКА -INF
  // 25
  s21_decimal num_251 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_252 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result25 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_251, num_252, &result25);
  // ck_assert_int_eq(result25.bits[3], 2147483648);
  ck_assert_int_eq(result25.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 26
  s21_decimal num_261 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_262 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result26 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_261, num_262, &result26);
  // ck_assert_int_eq(result26.bits[3], 2147483648);
  ck_assert_int_eq(result26.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 27
  s21_decimal num_271 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_272 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result27 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_271, num_272, &result27);
  // ck_assert_int_eq(result27.bits[3], 2147483648);
  ck_assert_int_eq(result27.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 28
  s21_decimal num_281 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_282 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal result28 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_281, num_282, &result28);
  // ck_assert_int_eq(result28.bits[3], 2147483648);
  ck_assert_int_eq(result28.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 29
  s21_decimal num_291 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_292 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal result29 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_291, num_292, &result29);
  // ck_assert_int_eq(result29.bits[3], 2147483648);
  ck_assert_int_eq(result29.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 30
  s21_decimal num_301 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_302 = {{1, 0, 0, 0}, S21_NAN};
  s21_decimal result30 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_301, num_302, &result30);
  // ck_assert_int_eq(result30.bits[3], 2147483648);
  ck_assert_int_eq(result30.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // ПРОВРЕКА НА NAN
  // 31
  s21_decimal num_311 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_312 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result31 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_311, num_312, &result31);
  // ck_assert_int_eq(result31.bits[3], 2147483648);
  ck_assert_int_eq(result31.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 32
  s21_decimal num_321 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_322 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result32 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_321, num_322, &result32);
  // ck_assert_int_eq(result32.bits[3], 2147483648);
  ck_assert_int_eq(result32.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 33
  s21_decimal num_331 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_332 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result33 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_331, num_332, &result33);
  // ck_assert_int_eq(result33.bits[3], 2147483648);
  ck_assert_int_eq(result33.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 34
  s21_decimal num_341 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_342 = {{1, 0, 0, 2147483648}, S21_INF};
  s21_decimal result34 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_341, num_342, &result34);
  // ck_assert_int_eq(result34.bits[3], 2147483648);
  ck_assert_int_eq(result34.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 35
  s21_decimal num_351 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_352 = {{1, 0, 0, 2147483648}, S21_N_INF};
  s21_decimal result35 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_351, num_352, &result35);
  // ck_assert_int_eq(result35.bits[3], 2147483648);
  ck_assert_int_eq(result35.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 36
  s21_decimal num_361 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_362 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal result36 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_361, num_362, &result36);
  // ck_assert_int_eq(result36.bits[3], 2147483648);
  ck_assert_int_eq(result36.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // НОРМАЛЬНЫЕ ТЕСТЫ
  // 37
  s21_decimal num_371 = {{4294967295, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_372 = {{3, 2, 0, 0}, S21_NORMAL};
  s21_decimal result37 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_371, num_372, &result37);
  ck_assert_int_eq(result37.bits[0], 4);
  ck_assert_int_eq(result37.bits[1], 1);
  ck_assert_int_eq(result37.bits[2], 0);
  ck_assert_int_eq(result37.bits[3], 2147483648);
  ck_assert_int_eq(result37.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 38
  s21_decimal num_381 = {{2, 3, 4, 0}, S21_NORMAL};
  s21_decimal num_382 = {{1, 2, 3, 131072}, S21_NORMAL};
  s21_decimal result38 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_381, num_382, &result38);
  ck_assert_int_eq(result38.bits[0], 199);
  ck_assert_int_eq(result38.bits[1], 298);
  ck_assert_int_eq(result38.bits[2], 397);
  ck_assert_int_eq(result38.bits[3], 131072);
  ck_assert_int_eq(result38.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 39
  s21_decimal num_391 = {{33, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_392 = {{112, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result39 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_391, num_392, &result39);
  ck_assert_int_eq(result39.bits[0], 79);
  ck_assert_int_eq(result39.bits[1], 0);
  ck_assert_int_eq(result39.bits[2], 0);
  ck_assert_int_eq(result39.bits[3], 0);
  ck_assert_int_eq(result39.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // ПЕРЕПОЛНЕНИЯ
  // 40
  s21_decimal num_401 = {{4294967295, 4294967295, 4294967295, 0}, S21_NORMAL};
  s21_decimal num_402 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result40 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_401, num_402, &result40);
  ck_assert_int_eq(result40.bits[3], 0);
  ck_assert_int_eq(result40.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 41
  s21_decimal num_411 = {{4294967295, 4294967295, 4294967295, 2147483648},
                         S21_NORMAL};
  s21_decimal num_412 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result41 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_sub(num_411, num_412, &result41);
  // ck_assert_int_eq(result41.bits[3], 2147483648);
  ck_assert_int_eq(result41.value_type, 2);
  ck_assert_int_eq(value_type, 2);
}

START_TEST(s21_div_test) {
  int value_type = 0;

  s21_decimal num_11 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_12 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result1 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_11, num_12, &result1);
  ck_assert_int_eq(result1.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  s21_decimal num_21 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_22 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result2 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_21, num_22, &result2);
  ck_assert_int_eq(result2.bits[0], 0);
  ck_assert_int_eq(result2.bits[1], 0);
  ck_assert_int_eq(result2.bits[2], 0);
  ck_assert_int_eq(result2.bits[3], 0);
  ck_assert_int_eq(result2.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  s21_decimal num_31 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_32 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result3 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_31, num_32, &result3);
  ck_assert_int_eq(result3.bits[0], 0);
  ck_assert_int_eq(result3.bits[1], 0);
  ck_assert_int_eq(result3.bits[2], 0);
  ck_assert_int_eq(result3.bits[3], 0);
  ck_assert_int_eq(result3.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  s21_decimal num_41 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_42 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal result4 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_41, num_42, &result4);
  ck_assert_int_eq(result4.bits[0], 0);
  ck_assert_int_eq(result4.bits[1], 0);
  ck_assert_int_eq(result4.bits[2], 0);
  ck_assert_int_eq(result4.bits[3], 0);
  ck_assert_int_eq(result4.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  s21_decimal num_51 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_52 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal result5 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_51, num_52, &result5);
  ck_assert_int_eq(result5.bits[0], 0);
  ck_assert_int_eq(result5.bits[1], 0);
  ck_assert_int_eq(result5.bits[2], 0);
  ck_assert_int_eq(result5.bits[3], 0);
  ck_assert_int_eq(result5.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  s21_decimal num_61 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_62 = {{1, 0, 0, 0}, S21_NAN};
  s21_decimal result6 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_61, num_62, &result6);
  ck_assert_int_eq(result6.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  s21_decimal num_71 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_72 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result7 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_71, num_72, &result7);
  ck_assert_int_eq(result7.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  s21_decimal num_81 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_82 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result8 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_81, num_82, &result8);
  ck_assert_int_eq(result8.bits[0], 1);
  ck_assert_int_eq(result8.bits[1], 0);
  ck_assert_int_eq(result8.bits[2], 0);
  ck_assert_int_eq(result8.bits[3], 0);
  ck_assert_int_eq(result8.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  s21_decimal num_91 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_92 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result9 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_91, num_92, &result9);
  ck_assert_int_eq(result9.bits[0], 1);
  ck_assert_int_eq(result9.bits[1], 0);
  ck_assert_int_eq(result9.bits[2], 0);
  ck_assert_int_eq(result9.bits[3], 2147483648);
  ck_assert_int_eq(result9.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  s21_decimal num_101 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_102 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal result10 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_101, num_102, &result10);
  ck_assert_int_eq(result10.bits[0], 0);
  ck_assert_int_eq(result10.bits[1], 0);
  ck_assert_int_eq(result10.bits[2], 0);
  ck_assert_int_eq(result10.bits[3], 0);
  ck_assert_int_eq(result10.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  s21_decimal num_111 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_112 = {{1, 0, 0, 2147483648}, S21_N_INF};
  s21_decimal result11 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_111, num_112, &result11);
  ck_assert_int_eq(result11.bits[0], 0);
  ck_assert_int_eq(result11.bits[1], 0);
  ck_assert_int_eq(result11.bits[2], 0);
  ck_assert_int_eq(result11.bits[3], 0);
  ck_assert_int_eq(result11.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  s21_decimal num_121 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_122 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal result12 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_121, num_122, &result12);
  ck_assert_int_eq(result12.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  s21_decimal num_131 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_132 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result13 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_131, num_132, &result13);
  ck_assert_int_eq(result13.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  s21_decimal num_141 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_142 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result14 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_141, num_142, &result14);
  ck_assert_int_eq(result14.bits[0], 1);
  ck_assert_int_eq(result14.bits[1], 0);
  ck_assert_int_eq(result14.bits[2], 0);
  ck_assert_int_eq(result14.bits[3], 2147483648);
  ck_assert_int_eq(result14.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  s21_decimal num_151 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_152 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result15 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_151, num_152, &result15);
  ck_assert_int_eq(result15.bits[0], 1);
  ck_assert_int_eq(result15.bits[1], 0);
  ck_assert_int_eq(result15.bits[2], 0);
  ck_assert_int_eq(result15.bits[3], 0);
  ck_assert_int_eq(result15.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  s21_decimal num_161 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_162 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal result16 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_161, num_162, &result16);
  ck_assert_int_eq(result16.bits[0], 0);
  ck_assert_int_eq(result16.bits[1], 0);
  ck_assert_int_eq(result16.bits[2], 0);
  ck_assert_int_eq(result16.bits[3], 0);
  ck_assert_int_eq(result16.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  s21_decimal num_171 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_172 = {{13, 0, 0, 0}, S21_N_INF};
  s21_decimal result17 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_171, num_172, &result17);
  ck_assert_int_eq(result17.bits[0], 0);
  ck_assert_int_eq(result17.bits[1], 0);
  ck_assert_int_eq(result17.bits[2], 0);
  ck_assert_int_eq(result17.bits[3], 0);
  ck_assert_int_eq(result17.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  s21_decimal num_181 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_182 = {{13, 0, 0, 0}, S21_NAN};
  s21_decimal result18 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_181, num_182, &result18);
  ck_assert_int_eq(result18.bits[3], 0);
  ck_assert_int_eq(result18.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  s21_decimal num_191 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_192 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result19 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_191, num_192, &result19);
  ck_assert_int_eq(result19.bits[3], 0);
  ck_assert_int_eq(result19.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  s21_decimal num_201 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_202 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result20 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_201, num_202, &result20);
  ck_assert_int_eq(result20.bits[3], 0);
  ck_assert_int_eq(result20.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  s21_decimal num_211 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_212 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result21 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_211, num_212, &result21);
  ck_assert_int_eq(result21.bits[3], 0);
  ck_assert_int_eq(result21.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  s21_decimal num_221 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_222 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal result22 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_221, num_222, &result22);
  ck_assert_int_eq(result22.bits[3], 0);
  ck_assert_int_eq(result22.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  s21_decimal num_231 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_232 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal result23 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_231, num_232, &result23);
  ck_assert_int_eq(result23.bits[3], 0);
  ck_assert_int_eq(result23.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  s21_decimal num_241 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_242 = {{1, 0, 0, 0}, S21_NAN};
  s21_decimal result24 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_241, num_242, &result24);
  ck_assert_int_eq(result24.bits[3], 0);
  ck_assert_int_eq(result24.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  s21_decimal num_251 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_252 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result25 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_251, num_252, &result25);
  ck_assert_int_eq(result25.bits[3], 0);
  ck_assert_int_eq(result25.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  s21_decimal num_261 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_262 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result26 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_261, num_262, &result26);
  ck_assert_int_eq(result26.bits[3], 0);
  ck_assert_int_eq(result26.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  s21_decimal num_271 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_272 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result27 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_271, num_272, &result27);
  ck_assert_int_eq(result27.bits[3], 0);
  ck_assert_int_eq(result27.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  s21_decimal num_281 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_282 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal result28 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_281, num_282, &result28);
  ck_assert_int_eq(result28.bits[3], 0);
  ck_assert_int_eq(result28.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  s21_decimal num_291 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_292 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal result29 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_291, num_292, &result29);
  ck_assert_int_eq(result29.bits[3], 0);
  ck_assert_int_eq(result29.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  s21_decimal num_301 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_302 = {{1, 0, 0, 0}, S21_NAN};
  s21_decimal result30 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_301, num_302, &result30);
  ck_assert_int_eq(result30.bits[3], 0);
  ck_assert_int_eq(result30.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  s21_decimal num_311 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_312 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result31 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_311, num_312, &result31);
  ck_assert_int_eq(result31.bits[3], 0);
  ck_assert_int_eq(result31.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  s21_decimal num_321 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_322 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result32 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_321, num_322, &result32);
  ck_assert_int_eq(result32.bits[3], 0);
  ck_assert_int_eq(result32.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  s21_decimal num_331 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_332 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result33 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_331, num_332, &result33);
  ck_assert_int_eq(result33.bits[3], 0);
  ck_assert_int_eq(result33.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  s21_decimal num_341 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_342 = {{1, 0, 0, 2147483648}, S21_INF};
  s21_decimal result34 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_341, num_342, &result34);
  ck_assert_int_eq(result34.bits[3], 0);
  ck_assert_int_eq(result34.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  s21_decimal num_351 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_352 = {{1, 0, 0, 2147483648}, S21_N_INF};
  s21_decimal result35 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_351, num_352, &result35);
  ck_assert_int_eq(result35.bits[3], 0);
  ck_assert_int_eq(result35.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  s21_decimal num_361 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_362 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal result36 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_361, num_362, &result36);
  ck_assert_int_eq(result36.bits[3], 0);
  ck_assert_int_eq(result36.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  s21_decimal num_371 = {{12, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_372 = {{3, 0, 0, 0}, S21_NORMAL};
  s21_decimal result37 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_371, num_372, &result37);
  ck_assert_int_eq(result37.bits[0], 4);
  ck_assert_int_eq(result37.bits[1], 0);
  ck_assert_int_eq(result37.bits[2], 0);
  ck_assert_int_eq(result37.bits[3], 0);
  ck_assert_int_eq(result37.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  s21_decimal num_381 = {{3, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_382 = {{12, 0, 0, 0}, S21_NORMAL};
  s21_decimal result38 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_div(num_381, num_382, &result38);
  ck_assert_int_eq(result38.bits[0], 25);
  ck_assert_int_eq(result38.bits[1], 0);
  ck_assert_int_eq(result38.bits[2], 0);
  ck_assert_int_eq(result38.bits[3], 131072);
  ck_assert_int_eq(result38.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // s21_decimal num_391 = {{13, 0, 0, 2147483648}, S21_NORMAL};
  // s21_decimal num_392 = {{5, 0, 0, 0}, S21_NORMAL};
  // s21_decimal result39 = {{0, 0, 0, 0}, S21_NORMAL};
  // value_type = s21_div(num_391, num_392, &result39);
  // ck_assert_int_eq(result39.bits[0], 26);
  // ck_assert_int_eq(result39.bits[1], 0);
  // ck_assert_int_eq(result39.bits[2], 0);
  // ck_assert_int_eq(result39.bits[3], 2147549184);
  // ck_assert_int_eq(result39.value_type, 0);
  // ck_assert_int_eq(value_type, 0);

  // s21_decimal num_401 = {{10852, 0, 0, 2147745792}, S21_NORMAL};
  // s21_decimal num_402 = {{32, 0, 0, 2147680256}, S21_NORMAL};
  // s21_decimal result40 = {{0, 0, 0, 0}, S21_NORMAL};
  // value_type = s21_div(num_401, num_402, &result40);
  // ck_assert_int_eq(result40.bits[0], 339125);
  // ck_assert_int_eq(result40.bits[1], 0);
  // ck_assert_int_eq(result40.bits[2], 0);
  // ck_assert_int_eq(result40.bits[3], 262144);
  // ck_assert_int_eq(result40.value_type, 0);
  // ck_assert_int_eq(value_type, 0);
}

START_TEST(s21_mul_test) {
  int value_type = 0;
  // Проверка на 0
  // 1
  s21_decimal num_11 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_12 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result1 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_11, num_12, &result1);
  ck_assert_int_eq(result1.bits[0], 0);
  ck_assert_int_eq(result1.bits[1], 0);
  ck_assert_int_eq(result1.bits[2], 0);
  ck_assert_int_eq(result1.bits[3], 0);
  ck_assert_int_eq(result1.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 2
  s21_decimal num_21 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_22 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result2 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_21, num_22, &result2);
  ck_assert_int_eq(result2.bits[0], 0);
  ck_assert_int_eq(result2.bits[1], 0);
  ck_assert_int_eq(result2.bits[2], 0);
  ck_assert_int_eq(result2.bits[3], 0);
  ck_assert_int_eq(result2.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 3
  s21_decimal num_31 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_32 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result3 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_31, num_32, &result3);
  ck_assert_int_eq(result3.bits[0], 0);
  ck_assert_int_eq(result3.bits[1], 0);
  ck_assert_int_eq(result3.bits[2], 0);
  // ck_assert_int_eq(result3.bits[3], 2147483648);
  ck_assert_int_eq(result3.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // // 4
  s21_decimal num_41 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_42 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal result4 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_41, num_42, &result4);
  // ck_assert_int_eq(result4.bits[3], 2147483648);
  ck_assert_int_eq(result4.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // // 5
  s21_decimal num_51 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_52 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal result5 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_51, num_52, &result5);
  // ck_assert_int_eq(result5.bits[3], 2147483648);
  ck_assert_int_eq(result5.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 6
  s21_decimal num_61 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_62 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal result6 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_61, num_62, &result6);
  // ck_assert_int_eq(result6.bits[3], 2147483648);
  ck_assert_int_eq(result6.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // // ПРОВЕРКА НА 1
  // 7
  s21_decimal num_71 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_72 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result7 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_71, num_72, &result7);
  ck_assert_int_eq(result7.bits[0], 0);
  ck_assert_int_eq(result7.bits[1], 0);
  ck_assert_int_eq(result7.bits[2], 0);
  ck_assert_int_eq(result7.bits[3], 0);
  ck_assert_int_eq(result7.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 8
  s21_decimal num_81 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_82 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result8 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_81, num_82, &result8);
  ck_assert_int_eq(result8.bits[0], 1);
  ck_assert_int_eq(result8.bits[1], 0);
  ck_assert_int_eq(result8.bits[2], 0);
  ck_assert_int_eq(result8.bits[3], 0);
  ck_assert_int_eq(result8.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 9
  s21_decimal num_91 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_92 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result9 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_91, num_92, &result9);
  ck_assert_int_eq(result9.bits[0], 1);
  ck_assert_int_eq(result9.bits[1], 0);
  ck_assert_int_eq(result9.bits[2], 0);
  ck_assert_int_eq(result9.bits[3], 2147483648);
  ck_assert_int_eq(result9.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 10
  s21_decimal num_101 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_102 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal result10 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_101, num_102, &result10);
  ck_assert_int_eq(result10.bits[3], 0);
  ck_assert_int_eq(result10.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 11
  s21_decimal num_111 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_112 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal result11 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_111, num_112, &result11);
  // ck_assert_int_eq(result11.bits[3], 2147483648);
  ck_assert_int_eq(result11.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 12
  s21_decimal num_121 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_122 = {{3, 0, 0, 0}, S21_NAN};
  s21_decimal result12 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_121, num_122, &result12);
  // ck_assert_int_eq(result12.bits[3], 2147483648);
  ck_assert_int_eq(result12.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // ПРОВЕРКА НА -1
  // 13
  s21_decimal num_131 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_132 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result13 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_131, num_132, &result13);
  ck_assert_int_eq(result13.bits[0], 0);
  ck_assert_int_eq(result13.bits[1], 0);
  ck_assert_int_eq(result13.bits[2], 0);
  // ck_assert_int_eq(result13.bits[3], 2147483648);
  ck_assert_int_eq(result13.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 14
  s21_decimal num_141 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_142 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result14 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_141, num_142, &result14);
  ck_assert_int_eq(result14.bits[0], 1);
  ck_assert_int_eq(result14.bits[1], 0);
  ck_assert_int_eq(result14.bits[2], 0);
  ck_assert_int_eq(result14.bits[3], 2147483648);
  ck_assert_int_eq(result14.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 15
  s21_decimal num_151 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_152 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result15 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_151, num_152, &result15);
  ck_assert_int_eq(result15.bits[0], 1);
  ck_assert_int_eq(result15.bits[1], 0);
  ck_assert_int_eq(result15.bits[2], 0);
  ck_assert_int_eq(result15.bits[3], 0);
  ck_assert_int_eq(result15.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 16
  s21_decimal num_161 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_162 = {{3, 0, 0, 0}, S21_INF};
  s21_decimal result16 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_161, num_162, &result16);
  // ck_assert_int_eq(result16.bits[3], 2147483648);
  ck_assert_int_eq(result16.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 17
  s21_decimal num_171 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_172 = {{3, 0, 0, 2147483648}, S21_N_INF};
  s21_decimal result17 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_171, num_172, &result17);
  ck_assert_int_eq(result17.bits[3], 0);
  ck_assert_int_eq(result17.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 18
  s21_decimal num_181 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_182 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal result18 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_181, num_182, &result18);
  // ck_assert_int_eq(result18.bits[3], 2147483648);
  ck_assert_int_eq(result18.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // ПРОВЕРКА НА INF
  // 19
  s21_decimal num_191 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_192 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result19 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_191, num_192, &result19);
  // ck_assert_int_eq(result19.bits[3], 2147483648);
  ck_assert_int_eq(result19.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 20
  s21_decimal num_201 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_202 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result20 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_201, num_202, &result20);
  ck_assert_int_eq(result20.bits[3], 0);
  ck_assert_int_eq(result20.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 21
  s21_decimal num_211 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_212 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result21 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_211, num_212, &result21);
  // ck_assert_int_eq(result21.bits[3], 2147483648);
  ck_assert_int_eq(result21.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 22
  s21_decimal num_221 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_222 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal result22 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_221, num_222, &result22);
  ck_assert_int_eq(result22.bits[3], 0);
  ck_assert_int_eq(result22.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 23
  s21_decimal num_231 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_232 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal result23 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_231, num_232, &result23);
  // ck_assert_int_eq(result23.bits[3], 2147483648);
  ck_assert_int_eq(result23.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 24
  s21_decimal num_241 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_242 = {{1, 0, 0, 0}, S21_NAN};
  s21_decimal result24 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_241, num_242, &result24);
  // ck_assert_int_eq(result24.bits[3], 2147483648);
  ck_assert_int_eq(result24.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // ПРОВЕРКА -INF
  // 25
  s21_decimal num_251 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_252 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result25 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_251, num_252, &result25);
  // ck_assert_int_eq(result25.bits[3], 2147483648);
  ck_assert_int_eq(result25.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 26
  s21_decimal num_261 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_262 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result26 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_261, num_262, &result26);
  // ck_assert_int_eq(result26.bits[3], 2147483648);
  ck_assert_int_eq(result26.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 27
  s21_decimal num_271 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_272 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result27 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_271, num_272, &result27);
  // ck_assert_int_eq(result27.bits[3], 0);
  ck_assert_int_eq(result27.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 28
  s21_decimal num_281 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_282 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal result28 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_281, num_282, &result28);
  // ck_assert_int_eq(result28.bits[3], 2147483648);
  ck_assert_int_eq(result28.value_type, 2);
  ck_assert_int_eq(value_type, 2);

  // 29
  s21_decimal num_291 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_292 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal result29 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_291, num_292, &result29);
  // ck_assert_int_eq(result29.bits[3], 0);
  ck_assert_int_eq(result29.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 30
  s21_decimal num_301 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_302 = {{1, 0, 0, 0}, S21_NAN};
  s21_decimal result30 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_301, num_302, &result30);
  // ck_assert_int_eq(result30.bits[3], 2147483648);
  ck_assert_int_eq(result30.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // ПРОВРЕКА НА NAN
  // 31
  s21_decimal num_311 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_312 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result31 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_311, num_312, &result31);
  // ck_assert_int_eq(result31.bits[3], 2147483648);
  ck_assert_int_eq(result31.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 32
  s21_decimal num_321 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_322 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result32 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_321, num_322, &result32);
  // ck_assert_int_eq(result32.bits[3], 2147483648);
  ck_assert_int_eq(result32.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 33
  s21_decimal num_331 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_332 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result33 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_331, num_332, &result33);
  // ck_assert_int_eq(result33.bits[3], 2147483648);
  ck_assert_int_eq(result33.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 34
  s21_decimal num_341 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_342 = {{1, 0, 0, 2147483648}, S21_INF};
  s21_decimal result34 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_341, num_342, &result34);
  // ck_assert_int_eq(result34.bits[3], 2147483648);
  ck_assert_int_eq(result34.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 35
  s21_decimal num_351 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_352 = {{1, 0, 0, 2147483648}, S21_N_INF};
  s21_decimal result35 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_351, num_352, &result35);
  // ck_assert_int_eq(result35.bits[3], 2147483648);
  ck_assert_int_eq(result35.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 36
  s21_decimal num_361 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_362 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal result36 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_361, num_362, &result36);
  // ck_assert_int_eq(result36.bits[3], 2147483648);
  ck_assert_int_eq(result36.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // НОРМАЛЬНЫЕ ТЕСТЫ
  // 37
  s21_decimal num_371 = {{125, 0, 0, 2147680256}, S21_NORMAL};
  s21_decimal num_372 = {{4, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result37 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_371, num_372, &result37);
  ck_assert_int_eq(result37.bits[0], 500);
  ck_assert_int_eq(result37.bits[1], 0);
  ck_assert_int_eq(result37.bits[2], 0);
  ck_assert_int_eq(result37.bits[3], 196608);
  ck_assert_int_eq(result37.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 38
  s21_decimal num_381 = {{4294967295, 4294967295, 4294967295, 2147876864},
                         S21_NORMAL};
  s21_decimal num_382 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result38 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_381, num_382, &result38);
  ck_assert_int_eq(result38.bits[0], 0);
  ck_assert_int_eq(result38.bits[1], 0);
  ck_assert_int_eq(result38.bits[2], 0);
  ck_assert_int_eq(result38.bits[3], 2147876864);
  ck_assert_int_eq(result38.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 39
  s21_decimal num_391 = {{4294967295, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_392 = {{2, 0, 0, 0}, S21_NORMAL};
  s21_decimal result39 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_391, num_392, &result39);
  ck_assert_int_eq(result39.bits[0], 4294967294);
  ck_assert_int_eq(result39.bits[1], 1);
  ck_assert_int_eq(result39.bits[2], 0);
  ck_assert_int_eq(result39.bits[3], 0);
  ck_assert_int_eq(result39.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // ПЕРЕПОЛНЕНИЯ
  // 40
  s21_decimal num_401 = {{4294967295, 4294967295, 4294967295, 0}, S21_NORMAL};
  s21_decimal num_402 = {{2, 0, 0, 0}, S21_NORMAL};
  s21_decimal result40 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_401, num_402, &result40);
  ck_assert_int_eq(result40.bits[3], 0);
  ck_assert_int_eq(result40.value_type, 1);
  ck_assert_int_eq(value_type, 1);

  // 41
  s21_decimal num_411 = {{4294967295, 4294967295, 4294967295, 2147483648},
                         S21_NORMAL};
  s21_decimal num_412 = {{2, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result41 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mul(num_411, num_412, &result41);
  // ck_assert_int_eq(result41.bits[3], 2147483648);
  ck_assert_int_eq(result41.value_type, 1);
  ck_assert_int_eq(value_type, 1);
}

START_TEST(s21_mod_test) {
  // ПРОВЕРКА НА 0
  // 1
  s21_decimal num_11 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_12 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result1 = {{0, 0, 0, 0}, S21_NORMAL};
  int value_type = s21_mod(num_11, num_12, &result1);
  ck_assert_int_eq(result1.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 2
  s21_decimal num_21 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_22 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result2 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_21, num_22, &result2);
  ck_assert_int_eq(result2.bits[0], 0);
  ck_assert_int_eq(result2.bits[1], 0);
  ck_assert_int_eq(result2.bits[2], 0);
  ck_assert_int_eq(result2.bits[3], 0);
  ck_assert_int_eq(result2.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 3
  s21_decimal num_31 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_32 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result3 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_31, num_32, &result3);
  ck_assert_int_eq(result3.bits[0], 0);
  ck_assert_int_eq(result3.bits[1], 0);
  ck_assert_int_eq(result3.bits[2], 0);
  ck_assert_int_eq(result3.bits[3], 0);
  ck_assert_int_eq(result3.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 4
  s21_decimal num_41 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_42 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal result4 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_41, num_42, &result4);
  ck_assert_int_eq(result4.bits[0], 0);
  ck_assert_int_eq(result4.bits[1], 0);
  ck_assert_int_eq(result4.bits[2], 0);
  ck_assert_int_eq(result4.bits[3], 0);
  ck_assert_int_eq(result4.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 5
  s21_decimal num_51 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_52 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal result5 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_51, num_52, &result5);
  ck_assert_int_eq(result5.bits[0], 0);
  ck_assert_int_eq(result5.bits[1], 0);
  ck_assert_int_eq(result5.bits[2], 0);
  ck_assert_int_eq(result5.bits[3], 0);
  ck_assert_int_eq(result5.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 6
  s21_decimal num_61 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_62 = {{1, 0, 0, 0}, S21_NAN};
  s21_decimal result6 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_61, num_62, &result6);
  ck_assert_int_eq(result6.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // Проверка на 1
  // 7
  s21_decimal num_71 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_72 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result7 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_71, num_72, &result7);
  ck_assert_int_eq(result7.bits[3], 0);
  ck_assert_int_eq(result7.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 8
  s21_decimal num_81 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_82 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result8 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_81, num_82, &result8);
  ck_assert_int_eq(result8.bits[0], 0);
  ck_assert_int_eq(result8.bits[1], 0);
  ck_assert_int_eq(result8.bits[2], 0);
  ck_assert_int_eq(result8.bits[3], 0);
  ck_assert_int_eq(result8.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 9
  s21_decimal num_91 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_92 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result9 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_91, num_92, &result9);
  ck_assert_int_eq(result9.bits[0], 0);
  ck_assert_int_eq(result9.bits[1], 0);
  ck_assert_int_eq(result9.bits[2], 0);
  ck_assert_int_eq(result9.bits[3], 0);
  ck_assert_int_eq(result9.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 10
  s21_decimal num_101 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_102 = {{12, 0, 0, 0}, S21_INF};
  s21_decimal result10 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_101, num_102, &result10);
  ck_assert_int_eq(result10.bits[0], 1);
  ck_assert_int_eq(result10.bits[1], 0);
  ck_assert_int_eq(result10.bits[2], 0);
  ck_assert_int_eq(result10.bits[3], 0);
  ck_assert_int_eq(result10.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 11
  s21_decimal num_111 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_112 = {{12, 0, 0, 2147483648}, S21_N_INF};
  s21_decimal result11 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_111, num_112, &result11);
  ck_assert_int_eq(result11.bits[0], 1);
  ck_assert_int_eq(result11.bits[1], 0);
  ck_assert_int_eq(result11.bits[2], 0);
  ck_assert_int_eq(result11.bits[3], 0);
  ck_assert_int_eq(result11.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 12
  s21_decimal num_121 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_122 = {{12, 0, 0, 2147483648}, S21_NAN};
  s21_decimal result12 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_121, num_122, &result12);
  ck_assert_int_eq(result12.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // ПРОВЕРКА НА -1
  // 13
  s21_decimal num_131 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_132 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result13 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_131, num_132, &result13);
  ck_assert_int_eq(result13.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 14
  s21_decimal num_141 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_142 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result14 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_141, num_142, &result14);
  ck_assert_int_eq(result14.bits[0], 0);
  ck_assert_int_eq(result14.bits[1], 0);
  ck_assert_int_eq(result14.bits[2], 0);
  ck_assert_int_eq(result14.bits[3], 2147483648);
  ck_assert_int_eq(result14.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 15
  s21_decimal num_151 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_152 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result15 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_151, num_152, &result15);
  ck_assert_int_eq(result15.bits[0], 0);
  ck_assert_int_eq(result15.bits[1], 0);
  ck_assert_int_eq(result15.bits[2], 0);
  ck_assert_int_eq(result15.bits[3], 2147483648);
  ck_assert_int_eq(result15.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 16
  s21_decimal num_161 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_162 = {{111, 0, 0, 0}, S21_INF};
  s21_decimal result16 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_161, num_162, &result16);
  ck_assert_int_eq(result16.bits[0], 1);
  ck_assert_int_eq(result16.bits[1], 0);
  ck_assert_int_eq(result16.bits[2], 0);
  ck_assert_int_eq(result16.bits[3], 2147483648);
  ck_assert_int_eq(result16.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 17
  s21_decimal num_171 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_172 = {{13, 0, 0, 0}, S21_N_INF};
  s21_decimal result17 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_171, num_172, &result17);
  ck_assert_int_eq(result17.bits[0], 1);
  ck_assert_int_eq(result17.bits[1], 0);
  ck_assert_int_eq(result17.bits[2], 0);
  ck_assert_int_eq(result17.bits[3], 2147483648);
  ck_assert_int_eq(result17.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 18
  s21_decimal num_181 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal num_182 = {{13, 0, 0, 0}, S21_NAN};
  s21_decimal result18 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_181, num_182, &result18);
  ck_assert_int_eq(result18.bits[3], 0);
  ck_assert_int_eq(result18.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // ПРОВЕРКА НА INF
  // 19
  s21_decimal num_191 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_192 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result19 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_191, num_192, &result19);
  // ck_assert_int_eq(result19.bits[3], 2147483648);
  ck_assert_int_eq(result19.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 20
  s21_decimal num_201 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_202 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result20 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_201, num_202, &result20);
  // ck_assert_int_eq(result20.bits[3], 2147483648);
  ck_assert_int_eq(result20.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 21
  s21_decimal num_211 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_212 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result21 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_211, num_212, &result21);
  // ck_assert_int_eq(result21.bits[3], 2147483648);
  ck_assert_int_eq(result21.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 22
  s21_decimal num_221 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_222 = {{13, 0, 0, 0}, S21_INF};
  s21_decimal result22 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_221, num_222, &result22);
  // ck_assert_int_eq(result22.bits[3], 2147483648);
  ck_assert_int_eq(result22.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 23
  s21_decimal num_231 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_232 = {{13, 0, 0, 0}, S21_N_INF};
  s21_decimal result23 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_231, num_232, &result23);
  // ck_assert_int_eq(result23.bits[3], 2147483648);
  ck_assert_int_eq(result23.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 24
  s21_decimal num_241 = {{1, 0, 0, 0}, S21_INF};
  s21_decimal num_242 = {{13, 0, 0, 0}, S21_NAN};
  s21_decimal result24 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_241, num_242, &result24);
  // ck_assert_int_eq(result24.bits[3], 2147483648);
  ck_assert_int_eq(result24.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // ПРОВЕРКА -INF
  // 25
  s21_decimal num_251 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_252 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result25 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_251, num_252, &result25);
  // ck_assert_int_eq(result25.bits[3], 2147483648);
  ck_assert_int_eq(result25.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 26
  s21_decimal num_261 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_262 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result26 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_261, num_262, &result26);
  // ck_assert_int_eq(result26.bits[3], 2147483648);
  ck_assert_int_eq(result26.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 27
  s21_decimal num_271 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_272 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result27 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_271, num_272, &result27);
  // ck_assert_int_eq(result27.bits[3], 0);
  ck_assert_int_eq(result27.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 28
  s21_decimal num_281 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_282 = {{13, 0, 0, 0}, S21_INF};
  s21_decimal result28 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_281, num_282, &result28);
  // ck_assert_int_eq(result28.bits[3], 2147483648);
  ck_assert_int_eq(result28.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 29
  s21_decimal num_291 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_292 = {{13, 0, 0, 0}, S21_N_INF};
  s21_decimal result29 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_291, num_292, &result29);
  // ck_assert_int_eq(result29.bits[3], 2147483648);
  ck_assert_int_eq(result29.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 30
  s21_decimal num_301 = {{1, 0, 0, 0}, S21_N_INF};
  s21_decimal num_302 = {{13, 0, 0, 0}, S21_NAN};
  s21_decimal result30 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_301, num_302, &result30);
  // ck_assert_int_eq(result30.bits[3], 2147483648);
  ck_assert_int_eq(result30.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // ПРОВРЕКА НА NAN
  // 31
  s21_decimal num_311 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_312 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result31 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_311, num_312, &result31);
  // ck_assert_int_eq(result31.bits[3], 2147483648);
  ck_assert_int_eq(result31.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 32
  s21_decimal num_321 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_322 = {{1, 0, 0, 0}, S21_NORMAL};
  s21_decimal result32 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_321, num_322, &result32);
  // ck_assert_int_eq(result32.bits[3], 2147483648);
  ck_assert_int_eq(result32.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 33
  s21_decimal num_331 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_332 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result33 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_331, num_332, &result33);
  // ck_assert_int_eq(result33.bits[3], 2147483648);
  ck_assert_int_eq(result33.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 34
  s21_decimal num_341 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_342 = {{13, 0, 0, 2147483648}, S21_INF};
  s21_decimal result34 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_341, num_342, &result34);
  // ck_assert_int_eq(result34.bits[3], 2147483648);
  ck_assert_int_eq(result34.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 35
  s21_decimal num_351 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_352 = {{13, 0, 0, 2147483648}, S21_N_INF};
  s21_decimal result35 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_351, num_352, &result35);
  // ck_assert_int_eq(result35.bits[3], 2147483648);
  ck_assert_int_eq(result35.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // 36
  s21_decimal num_361 = {{1, 0, 0, 2147483648}, S21_NAN};
  s21_decimal num_362 = {{13, 0, 0, 2147483648}, S21_NAN};
  s21_decimal result36 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_361, num_362, &result36);
  // ck_assert_int_eq(result36.bits[3], 2147483648);
  ck_assert_int_eq(result36.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  // НОРМАЛЬНЫЕ ЗНАЧЕНИЯ
  // 37
  s21_decimal num_371 = {{33, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_372 = {{3, 0, 0, 0}, S21_NORMAL};
  s21_decimal result37 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_371, num_372, &result37);
  ck_assert_int_eq(result37.bits[0], 0);
  ck_assert_int_eq(result37.bits[1], 0);
  ck_assert_int_eq(result37.bits[2], 0);
  ck_assert_int_eq(result37.bits[3], 0);
  ck_assert_int_eq(result37.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 38
  s21_decimal num_381 = {{3, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_382 = {{2147483648, 0, 0, 0}, S21_NORMAL};
  s21_decimal result38 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_381, num_382, &result38);
  ck_assert_int_eq(result38.bits[0], 3);
  ck_assert_int_eq(result38.bits[1], 0);
  ck_assert_int_eq(result38.bits[2], 0);
  ck_assert_int_eq(result38.bits[3], 0);
  ck_assert_int_eq(result38.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 39
  s21_decimal num_391 = {{253, 0, 0, 131072}, S21_NORMAL};
  s21_decimal num_392 = {{5, 0, 0, 65536}, S21_NORMAL};
  s21_decimal result39 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_391, num_392, &result39);
  ck_assert_int_eq(result39.bits[0], 3);
  ck_assert_int_eq(result39.bits[1], 0);
  ck_assert_int_eq(result39.bits[2], 0);
  ck_assert_int_eq(result39.bits[3], 131072);
  ck_assert_int_eq(result39.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  // 40
  s21_decimal num_401 = {{50, 0, 0, 131072}, S21_NORMAL};
  s21_decimal num_402 = {{250, 0, 0, 131072}, S21_NORMAL};
  s21_decimal result40 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_401, num_402, &result40);
  ck_assert_int_eq(result40.bits[0], 50);
  ck_assert_int_eq(result40.bits[1], 0);
  ck_assert_int_eq(result40.bits[2], 0);
  ck_assert_int_eq(result40.bits[3], 131072);
  ck_assert_int_eq(result40.value_type, 0);
  ck_assert_int_eq(value_type, 0);

  s21_decimal num_403 = {{50, 0, 0, 0}, S21_NORMAL};
  s21_decimal num_404 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal result41 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_403, num_404, &result41);
  ck_assert_int_eq(result41.bits[0], 0);
  ck_assert_int_eq(result41.bits[1], 0);
  ck_assert_int_eq(result41.bits[2], 0);
  ck_assert_int_eq(result41.bits[3], 0);
  ck_assert_int_eq(result41.value_type, 3);
  ck_assert_int_eq(value_type, 3);

  s21_decimal num_405 = {{55, 0, 0, 1 << 16}, S21_NORMAL};
  s21_decimal num_406 = {{55, 0, 0, 1 << 16}, S21_NORMAL};
  s21_decimal result42 = {{0, 0, 0, 0}, S21_NORMAL};
  value_type = s21_mod(num_405, num_406, &result42);
  ck_assert_int_eq(result42.bits[0], 0);
  ck_assert_int_eq(result42.bits[1], 0);
  ck_assert_int_eq(result42.bits[2], 0);
  ck_assert_int_eq(result42.bits[3], 0);
  ck_assert_int_eq(result42.value_type, 0);
  ck_assert_int_eq(value_type, 0);
}

START_TEST(s21_is_less_test) {
  s21_decimal value_1 = {{123, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_1_2 = {{124, 0, 0, 0}, S21_NORMAL};
  int result = s21_is_less(value_1, value_1_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_2 = {{125, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_2_2 = {{124, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less(value_2, value_2_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_3 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_3_2 = {{124, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less(value_3, value_3_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_4 = {{124, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_4_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less(value_4, value_4_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_5 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_5_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less(value_5, value_5_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_6 = {{234, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_6_2 = {{234, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less(value_6, value_6_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_7 = {{12, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_7_2 = {{12, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_less(value_7, value_7_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_8 = {{20, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_8_2 = {{12, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_less(value_8, value_8_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_9 = {{2, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_9_2 = {{12, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_less(value_9, value_9_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_10 = {{145, 0, 0, 65536}, S21_NORMAL};
  s21_decimal value_10_2 = {{29, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less(value_10, value_10_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_11 = {{145, 0, 0, 65536}, S21_NORMAL};
  s21_decimal value_11_2 = {{290, 0, 0, 65536}, S21_NORMAL};
  result = s21_is_less(value_11, value_11_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_12 = {{145, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_12_2 = {{290, 0, 0, 65536}, S21_NORMAL};
  result = s21_is_less(value_12, value_12_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_13 = {{145, 0, 0, 2147614720}, S21_NORMAL};
  s21_decimal value_13_2 = {{2, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less(value_13, value_13_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_14 = {{145, 0, 0, 2147614720}, S21_NORMAL};
  s21_decimal value_14_2 = {{122, 0, 0, 2147614720}, S21_NORMAL};
  result = s21_is_less(value_14, value_14_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_15 = {{111, 0, 0, 2147614720}, S21_NORMAL};
  s21_decimal value_15_2 = {{1223, 0, 0, 2147614720}, S21_NORMAL};
  result = s21_is_less(value_15, value_15_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_16 = {{111, 1234, 0, 0}, S21_NORMAL};
  s21_decimal value_16_2 = {{1223, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less(value_16, value_16_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_17 = {{111, 1234, 0, 0}, S21_NORMAL};
  s21_decimal value_17_2 = {{1223, 0, 23467, 0}, S21_NORMAL};
  result = s21_is_less(value_17, value_17_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_18 = {{111, 1234, 0, 327680}, S21_NORMAL};
  s21_decimal value_18_2 = {{1223, 0, 23467, 327680}, S21_NORMAL};
  result = s21_is_less(value_18, value_18_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_19 = {{111, 0, 0, 327680}, S21_NORMAL};
  s21_decimal value_19_2 = {{111, 0, 0, 327680}, S21_NORMAL};
  result = s21_is_less(value_19, value_19_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_20 = {{111, 0, 0, 327680}, S21_NORMAL};
  s21_decimal inf = {{4284967295, 4284967295, 4284967296, 0}, S21_INF};
  result = s21_is_less(value_20, inf);
  ck_assert_int_eq(result, 1);

  result = s21_is_less(inf, value_20);
  ck_assert_int_eq(result, 0);

  s21_decimal value_21 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_21_2 = {{1, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less(value_21, value_21_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_22 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_22_2 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_less(value_22, value_22_2);
  ck_assert_int_eq(result, 0);

  // INF
  s21_decimal value_23 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal value_23_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less(value_23, value_23_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_25 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal value_25_2 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_less(value_25, value_25_2);
  ck_assert_int_eq(result, 0);

  // -INF
  s21_decimal value_30 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_30_2 = {{1, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less(value_30, value_30_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_32 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_32_2 = {{1, 0, 0, 0}, S21_INF};
  result = s21_is_less(value_32, value_32_2);
  ck_assert_int_eq(result, 1);

  // -NAN
  s21_decimal value_35 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_35_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less(value_35, value_35_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_37 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_37_2 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_less(value_37, value_37_2);
  ck_assert_int_eq(result, 0);
}

START_TEST(s21_is_greater_test) {
  s21_decimal value_1 = {{123, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_1_2 = {{124, 0, 0, 0}, S21_NORMAL};
  int result = s21_is_greater(value_1, value_1_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_2 = {{125, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_2_2 = {{124, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater(value_2, value_2_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_3 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_3_2 = {{124, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater(value_3, value_3_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_4 = {{124, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_4_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater(value_4, value_4_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_5 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_5_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater(value_5, value_5_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_6 = {{234, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_6_2 = {{234, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater(value_6, value_6_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_7 = {{12, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_7_2 = {{12, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_greater(value_7, value_7_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_8 = {{20, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_8_2 = {{12, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_greater(value_8, value_8_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_9 = {{2, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_9_2 = {{12, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_greater(value_9, value_9_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_10 = {{145, 0, 0, 65536}, S21_NORMAL};
  s21_decimal value_10_2 = {{29, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater(value_10, value_10_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_11 = {{145, 0, 0, 65536}, S21_NORMAL};
  s21_decimal value_11_2 = {{290, 0, 0, 65536}, S21_NORMAL};
  result = s21_is_greater(value_11, value_11_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_12 = {{145, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_12_2 = {{290, 0, 0, 65536}, S21_NORMAL};
  result = s21_is_greater(value_12, value_12_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_13 = {{145, 0, 0, 2147614720}, S21_NORMAL};
  s21_decimal value_13_2 = {{2, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater(value_13, value_13_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_14 = {{145, 0, 0, 2147614720}, S21_NORMAL};
  s21_decimal value_14_2 = {{122, 0, 0, 2147614720}, S21_NORMAL};
  result = s21_is_greater(value_14, value_14_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_15 = {{111, 0, 0, 2147614720}, S21_NORMAL};
  s21_decimal value_15_2 = {{1223, 0, 0, 2147614720}, S21_NORMAL};
  result = s21_is_greater(value_15, value_15_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_16 = {{111, 1234, 0, 0}, S21_NORMAL};
  s21_decimal value_16_2 = {{1223, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater(value_16, value_16_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_17 = {{111, 1234, 0, 0}, S21_NORMAL};
  s21_decimal value_17_2 = {{1223, 0, 23467, 0}, S21_NORMAL};
  result = s21_is_greater(value_17, value_17_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_18 = {{111, 1234, 0, 327680}, S21_NORMAL};
  s21_decimal value_18_2 = {{1223, 0, 23467, 327680}, S21_NORMAL};
  result = s21_is_greater(value_18, value_18_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_19 = {{111, 0, 0, 327680}, S21_NORMAL};
  s21_decimal value_19_2 = {{111, 0, 0, 327680}, S21_NORMAL};
  result = s21_is_greater(value_19, value_19_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_20 = {{111, 0, 0, 327680}, S21_NORMAL};
  s21_decimal inf = {{4284967295, 4284967295, 4284967296, 0}, S21_NORMAL};
  result = s21_is_greater(value_20, inf);
  ck_assert_int_eq(result, 0);

  result = s21_is_greater(inf, value_20);
  ck_assert_int_eq(result, 1);

  // INF
  s21_decimal value_25 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal value_25_2 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_greater(value_25, value_25_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_26 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal value_26_2 = {{1, 0, 0, 0}, S21_INF};
  result = s21_is_greater(value_26, value_26_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_28 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal value_28_2 = {{13, 0, 0, 0}, S21_NAN};
  result = s21_is_greater(value_28, value_28_2);
  ck_assert_int_eq(result, 0);

  // -INF
  s21_decimal value_29 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_29_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater(value_29, value_29_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_30 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_30_2 = {{1, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater(value_30, value_30_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_32 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_32_2 = {{1, 0, 0, 0}, S21_INF};
  result = s21_is_greater(value_32, value_32_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_33 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_33_2 = {{13, 0, 0, 0}, S21_N_INF};
  result = s21_is_greater(value_33, value_33_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_34 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_34_2 = {{13, 0, 0, 0}, S21_NAN};
  result = s21_is_greater(value_34, value_34_2);
  ck_assert_int_eq(result, 0);

  // -NAN
  s21_decimal value_35 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_35_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater(value_35, value_35_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_36 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_36_2 = {{1, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater(value_36, value_36_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_38 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_38_2 = {{1, 0, 0, 0}, S21_INF};
  result = s21_is_greater(value_38, value_38_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_39 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_39_2 = {{13, 0, 0, 0}, S21_N_INF};
  result = s21_is_greater(value_39, value_39_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_40 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_40_2 = {{13, 0, 0, 0}, S21_NAN};
  result = s21_is_greater(value_40, value_40_2);
  ck_assert_int_eq(result, 0);
}

START_TEST(s21_is_less_or_equal_test) {
  s21_decimal value_1 = {{123, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_1_2 = {{124, 0, 0, 0}, S21_NORMAL};
  int result = s21_is_less_or_equal(value_1, value_1_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_2 = {{125, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_2_2 = {{124, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less_or_equal(value_2, value_2_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_3 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_3_2 = {{124, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less_or_equal(value_3, value_3_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_4 = {{124, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_4_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less_or_equal(value_4, value_4_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_5 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_5_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less_or_equal(value_5, value_5_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_6 = {{234, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_6_2 = {{234, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less_or_equal(value_6, value_6_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_7 = {{12, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_7_2 = {{12, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_less_or_equal(value_7, value_7_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_8 = {{20, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_8_2 = {{12, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_less_or_equal(value_8, value_8_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_9 = {{2, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_9_2 = {{12, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_less_or_equal(value_9, value_9_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_10 = {{145, 0, 0, 65536}, S21_NORMAL};
  s21_decimal value_10_2 = {{29, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less_or_equal(value_10, value_10_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_11 = {{145, 0, 0, 65536}, S21_NORMAL};
  s21_decimal value_11_2 = {{290, 0, 0, 65536}, S21_NORMAL};
  result = s21_is_less_or_equal(value_11, value_11_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_12 = {{145, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_12_2 = {{290, 0, 0, 65536}, S21_NORMAL};
  result = s21_is_less_or_equal(value_12, value_12_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_13 = {{145, 0, 0, 2147614720}, S21_NORMAL};
  s21_decimal value_13_2 = {{2, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less_or_equal(value_13, value_13_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_14 = {{145, 0, 0, 2147614720}, S21_NORMAL};
  s21_decimal value_14_2 = {{122, 0, 0, 2147614720}, S21_NORMAL};
  result = s21_is_less_or_equal(value_14, value_14_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_15 = {{111, 0, 0, 2147614720}, S21_NORMAL};
  s21_decimal value_15_2 = {{1223, 0, 0, 2147614720}, S21_NORMAL};
  result = s21_is_less_or_equal(value_15, value_15_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_16 = {{111, 1234, 0, 0}, S21_NORMAL};
  s21_decimal value_16_2 = {{1223, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less_or_equal(value_16, value_16_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_17 = {{111, 1234, 0, 0}, S21_NORMAL};
  s21_decimal value_17_2 = {{1223, 0, 23467, 0}, S21_NORMAL};
  result = s21_is_less_or_equal(value_17, value_17_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_18 = {{111, 1234, 0, 327680}, S21_NORMAL};
  s21_decimal value_18_2 = {{1223, 0, 23467, 327680}, S21_NORMAL};
  result = s21_is_less_or_equal(value_18, value_18_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_19 = {{111, 0, 0, 327680}, S21_NORMAL};
  s21_decimal value_19_2 = {{111, 0, 0, 327680}, S21_NORMAL};
  result = s21_is_less_or_equal(value_19, value_19_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_20 = {{111, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_20_2 = {{111, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less_or_equal(value_20, value_20_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_21 = {{111, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_21_2 = {{111, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_less_or_equal(value_21, value_21_2);
  ck_assert_int_eq(result, 1);

  // INF
  s21_decimal value_25 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal value_25_2 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_less_or_equal(value_25, value_25_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_26 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal value_26_2 = {{1, 0, 0, 0}, S21_INF};
  result = s21_is_less_or_equal(value_26, value_26_2);
  ck_assert_int_eq(result, 1);

  // -INF
  s21_decimal value_29 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_29_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less_or_equal(value_29, value_29_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_30 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_30_2 = {{1, 0, 0, 0}, S21_NORMAL};
  result = s21_is_less_or_equal(value_30, value_30_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_32 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_32_2 = {{1, 0, 0, 0}, S21_INF};
  result = s21_is_less_or_equal(value_32, value_32_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_33 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_33_2 = {{13, 0, 0, 0}, S21_N_INF};
  result = s21_is_less_or_equal(value_33, value_33_2);
  ck_assert_int_eq(result, 1);

  // -NAN
  s21_decimal value_37 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_37_2 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_less_or_equal(value_37, value_37_2);
  ck_assert_int_eq(result, 0);
}

START_TEST(s21_is_greater_or_equal_test) {
  s21_decimal value_1 = {{123, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_1_2 = {{124, 0, 0, 0}, S21_NORMAL};
  int result = s21_is_greater_or_equal(value_1, value_1_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_2 = {{125, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_2_2 = {{124, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_2, value_2_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_3 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_3_2 = {{124, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_3, value_3_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_4 = {{124, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_4_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_4, value_4_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_5 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_5_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_5, value_5_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_6 = {{234, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_6_2 = {{234, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_6, value_6_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_7 = {{12, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_7_2 = {{12, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_7, value_7_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_8 = {{20, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_8_2 = {{12, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_8, value_8_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_9 = {{2, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_9_2 = {{12, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_9, value_9_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_10 = {{145, 0, 0, 65536}, S21_NORMAL};
  s21_decimal value_10_2 = {{29, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_10, value_10_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_11 = {{145, 0, 0, 65536}, S21_NORMAL};
  s21_decimal value_11_2 = {{290, 0, 0, 65536}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_11, value_11_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_12 = {{145, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_12_2 = {{290, 0, 0, 65536}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_12, value_12_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_13 = {{145, 0, 0, 2147614720}, S21_NORMAL};
  s21_decimal value_13_2 = {{2, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_13, value_13_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_14 = {{145, 0, 0, 2147614720}, S21_NORMAL};
  s21_decimal value_14_2 = {{122, 0, 0, 2147614720}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_14, value_14_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_15 = {{111, 0, 0, 2147614720}, S21_NORMAL};
  s21_decimal value_15_2 = {{1223, 0, 0, 2147614720}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_15, value_15_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_16 = {{111, 1234, 0, 0}, S21_NORMAL};
  s21_decimal value_16_2 = {{1223, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_16, value_16_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_17 = {{111, 1234, 0, 0}, S21_NORMAL};
  s21_decimal value_17_2 = {{1223, 0, 23467, 0}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_17, value_17_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_18 = {{111, 1234, 0, 327680}, S21_NORMAL};
  s21_decimal value_18_2 = {{1223, 0, 23467, 327680}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_18, value_18_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_19 = {{111, 0, 0, 327680}, S21_NORMAL};
  s21_decimal value_19_2 = {{111, 0, 0, 327680}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_19, value_19_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_20 = {{111, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_20_2 = {{111, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_20, value_20_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_21 = {{111, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_21_2 = {{111, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_21, value_21_2);
  ck_assert_int_eq(result, 1);

  // INF
  s21_decimal value_23 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal value_23_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_23, value_23_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_25 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal value_25_2 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_25, value_25_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_28 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal value_28_2 = {{13, 0, 0, 0}, S21_NAN};
  result = s21_is_greater_or_equal(value_28, value_28_2);
  ck_assert_int_eq(result, 0);

  // -INF
  s21_decimal value_30 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_30_2 = {{1, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_30, value_30_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_32 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_32_2 = {{1, 0, 0, 0}, S21_INF};
  result = s21_is_greater_or_equal(value_32, value_32_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_34 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_34_2 = {{13, 0, 0, 0}, S21_NAN};
  result = s21_is_greater_or_equal(value_34, value_34_2);
  ck_assert_int_eq(result, 0);

  // -NAN
  s21_decimal value_36 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_36_2 = {{1, 0, 0, 0}, S21_NORMAL};
  result = s21_is_greater_or_equal(value_36, value_36_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_38 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_38_2 = {{1, 0, 0, 0}, S21_INF};
  result = s21_is_greater_or_equal(value_38, value_38_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_39 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_39_2 = {{13, 0, 0, 0}, S21_N_INF};
  result = s21_is_greater_or_equal(value_39, value_39_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_40 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_40_2 = {{13, 0, 0, 0}, S21_NAN};
  result = s21_is_greater_or_equal(value_40, value_40_2);
  ck_assert_int_eq(result, 0);
}

START_TEST(s21_is_equal_test) {
  s21_decimal value_1 = {{123, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_1_2 = {{124, 0, 0, 0}, S21_NORMAL};
  int result = s21_is_equal(value_1, value_1_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_2 = {{125, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_2_2 = {{124, 0, 0, 0}, S21_NORMAL};
  result = s21_is_equal(value_2, value_2_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_3 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_3_2 = {{124, 0, 0, 0}, S21_NORMAL};
  result = s21_is_equal(value_3, value_3_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_4 = {{124, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_4_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_is_equal(value_4, value_4_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_5 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_5_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_is_equal(value_5, value_5_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_6 = {{234, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_6_2 = {{234, 0, 0, 0}, S21_NORMAL};
  result = s21_is_equal(value_6, value_6_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_7 = {{12, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_7_2 = {{12, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_equal(value_7, value_7_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_8 = {{20, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_8_2 = {{12, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_equal(value_8, value_8_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_9 = {{2, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_9_2 = {{12, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_equal(value_9, value_9_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_10 = {{145, 0, 0, 65536}, S21_NORMAL};
  s21_decimal value_10_2 = {{29, 0, 0, 0}, S21_NORMAL};
  result = s21_is_equal(value_10, value_10_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_11 = {{145, 0, 0, 65536}, S21_NORMAL};
  s21_decimal value_11_2 = {{290, 0, 0, 65536}, S21_NORMAL};
  result = s21_is_equal(value_11, value_11_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_12 = {{145, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_12_2 = {{290, 0, 0, 65536}, S21_NORMAL};
  result = s21_is_equal(value_12, value_12_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_13 = {{145, 0, 0, 2147614720}, S21_NORMAL};
  s21_decimal value_13_2 = {{2, 0, 0, 0}, S21_NORMAL};
  result = s21_is_equal(value_13, value_13_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_14 = {{145, 0, 0, 2147614720}, S21_NORMAL};
  s21_decimal value_14_2 = {{122, 0, 0, 2147614720}, S21_NORMAL};
  result = s21_is_equal(value_14, value_14_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_15 = {{111, 0, 0, 2147614720}, S21_NORMAL};
  s21_decimal value_15_2 = {{1223, 0, 0, 2147614720}, S21_NORMAL};
  result = s21_is_equal(value_15, value_15_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_16 = {{111, 1234, 0, 0}, S21_NORMAL};
  s21_decimal value_16_2 = {{1223, 0, 0, 0}, S21_NORMAL};
  result = s21_is_equal(value_16, value_16_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_17 = {{111, 1234, 0, 0}, S21_NORMAL};
  s21_decimal value_17_2 = {{1223, 0, 23467, 0}, S21_NORMAL};
  result = s21_is_equal(value_17, value_17_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_18 = {{111, 1234, 0, 327680}, S21_NORMAL};
  s21_decimal value_18_2 = {{1223, 0, 23467, 327680}, S21_NORMAL};
  result = s21_is_equal(value_18, value_18_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_19 = {{111, 0, 0, 327680}, S21_NORMAL};
  s21_decimal value_19_2 = {{111, 0, 0, 327680}, S21_NORMAL};
  result = s21_is_equal(value_19, value_19_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_20 = {{111, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_20_2 = {{111, 0, 0, 0}, S21_NORMAL};
  result = s21_is_equal(value_20, value_20_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_21 = {{111, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_21_2 = {{111, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_equal(value_21, value_21_2);
  ck_assert_int_eq(result, 1);

  // INF
  s21_decimal value_24 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal value_24_2 = {{1, 0, 0, 0}, S21_NORMAL};
  result = s21_is_equal(value_24, value_24_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_25 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal value_25_2 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_equal(value_25, value_25_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_28 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal value_28_2 = {{13, 0, 0, 0}, S21_NAN};
  result = s21_is_equal(value_28, value_28_2);
  ck_assert_int_eq(result, 0);

  // -INF
  s21_decimal value_30 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_30_2 = {{1, 0, 0, 0}, S21_NORMAL};
  result = s21_is_equal(value_30, value_30_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_31 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_31_2 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_equal(value_31, value_31_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_32 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_32_2 = {{1, 0, 0, 0}, S21_INF};
  result = s21_is_equal(value_32, value_32_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_34 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_34_2 = {{13, 0, 0, 0}, S21_NAN};
  result = s21_is_equal(value_34, value_34_2);
  ck_assert_int_eq(result, 0);

  // -NAN
  s21_decimal value_36 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_36_2 = {{1, 0, 0, 0}, S21_NORMAL};
  result = s21_is_equal(value_36, value_36_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_37 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_37_2 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_equal(value_37, value_37_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_38 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_38_2 = {{1, 0, 0, 0}, S21_INF};
  result = s21_is_equal(value_38, value_38_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_39 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_39_2 = {{13, 0, 0, 0}, S21_N_INF};
  result = s21_is_equal(value_39, value_39_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_40 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_40_2 = {{13, 0, 0, 0}, S21_NAN};
  result = s21_is_equal(value_40, value_40_2);
  ck_assert_int_eq(result, 0);
}

START_TEST(s21_is_not_equal_test) {
  s21_decimal value_1 = {{123, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_1_2 = {{124, 0, 0, 0}, S21_NORMAL};
  int result = s21_is_not_equal(value_1, value_1_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_2 = {{125, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_2_2 = {{124, 0, 0, 0}, S21_NORMAL};
  result = s21_is_not_equal(value_2, value_2_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_3 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_3_2 = {{124, 0, 0, 0}, S21_NORMAL};
  result = s21_is_not_equal(value_3, value_3_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_4 = {{124, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_4_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_is_not_equal(value_4, value_4_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_5 = {{0, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_5_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_is_not_equal(value_5, value_5_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_6 = {{234, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_6_2 = {{234, 0, 0, 0}, S21_NORMAL};
  result = s21_is_not_equal(value_6, value_6_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_7 = {{12, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_7_2 = {{12, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_not_equal(value_7, value_7_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_8 = {{20, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_8_2 = {{12, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_not_equal(value_8, value_8_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_9 = {{2, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_9_2 = {{12, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_not_equal(value_9, value_9_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_10 = {{145, 0, 0, 65536}, S21_NORMAL};
  s21_decimal value_10_2 = {{29, 0, 0, 0}, S21_NORMAL};
  result = s21_is_not_equal(value_10, value_10_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_11 = {{145, 0, 0, 65536}, S21_NORMAL};
  s21_decimal value_11_2 = {{290, 0, 0, 65536}, S21_NORMAL};
  result = s21_is_not_equal(value_11, value_11_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_12 = {{145, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_12_2 = {{290, 0, 0, 65536}, S21_NORMAL};
  result = s21_is_not_equal(value_12, value_12_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_13 = {{145, 0, 0, 2147614720}, S21_NORMAL};
  s21_decimal value_13_2 = {{2, 0, 0, 0}, S21_NORMAL};
  result = s21_is_not_equal(value_13, value_13_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_14 = {{145, 0, 0, 2147614720}, S21_NORMAL};
  s21_decimal value_14_2 = {{122, 0, 0, 2147614720}, S21_NORMAL};
  result = s21_is_not_equal(value_14, value_14_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_15 = {{111, 0, 0, 2147614720}, S21_NORMAL};
  s21_decimal value_15_2 = {{1223, 0, 0, 2147614720}, S21_NORMAL};
  result = s21_is_not_equal(value_15, value_15_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_16 = {{111, 1234, 0, 0}, S21_NORMAL};
  s21_decimal value_16_2 = {{1223, 0, 0, 0}, S21_NORMAL};
  result = s21_is_not_equal(value_16, value_16_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_17 = {{111, 1234, 0, 0}, S21_NORMAL};
  s21_decimal value_17_2 = {{1223, 0, 23467, 0}, S21_NORMAL};
  result = s21_is_not_equal(value_17, value_17_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_18 = {{111, 1234, 0, 327680}, S21_NORMAL};
  s21_decimal value_18_2 = {{1223, 0, 23467, 327680}, S21_NORMAL};
  result = s21_is_not_equal(value_18, value_18_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_19 = {{111, 0, 0, 327680}, S21_NORMAL};
  s21_decimal value_19_2 = {{111, 0, 0, 327680}, S21_NORMAL};
  result = s21_is_not_equal(value_19, value_19_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_20 = {{111, 0, 0, 0}, S21_NORMAL};
  s21_decimal value_20_2 = {{111, 0, 0, 0}, S21_NORMAL};
  result = s21_is_not_equal(value_20, value_20_2);
  ck_assert_int_eq(result, 0);

  s21_decimal value_21 = {{111, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal value_21_2 = {{111, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_not_equal(value_21, value_21_2);
  ck_assert_int_eq(result, 0);

  // INF
  s21_decimal value_24 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal value_24_2 = {{1, 0, 0, 0}, S21_NORMAL};
  result = s21_is_not_equal(value_24, value_24_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_25 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal value_25_2 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_not_equal(value_25, value_25_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_27 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal value_27_2 = {{13, 0, 0, 0}, S21_N_INF};
  result = s21_is_not_equal(value_27, value_27_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_28 = {{0, 0, 0, 0}, S21_INF};
  s21_decimal value_28_2 = {{13, 0, 0, 0}, S21_NAN};
  result = s21_is_not_equal(value_28, value_28_2);
  ck_assert_int_eq(result, 1);

  // -INF
  s21_decimal value_30 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_30_2 = {{1, 0, 0, 0}, S21_NORMAL};
  result = s21_is_not_equal(value_30, value_30_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_31 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_31_2 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_not_equal(value_31, value_31_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_32 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_32_2 = {{1, 0, 0, 0}, S21_INF};
  result = s21_is_not_equal(value_32, value_32_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_34 = {{0, 0, 0, 0}, S21_N_INF};
  s21_decimal value_34_2 = {{13, 0, 0, 0}, S21_NAN};
  result = s21_is_not_equal(value_34, value_34_2);
  ck_assert_int_eq(result, 1);

  // -NAN
  s21_decimal value_36 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_36_2 = {{1, 0, 0, 0}, S21_NORMAL};
  result = s21_is_not_equal(value_36, value_36_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_37 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_37_2 = {{1, 0, 0, 2147483648}, S21_NORMAL};
  result = s21_is_not_equal(value_37, value_37_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_38 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_38_2 = {{1, 0, 0, 0}, S21_INF};
  result = s21_is_not_equal(value_38, value_38_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_39 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_39_2 = {{13, 0, 0, 0}, S21_N_INF};
  result = s21_is_not_equal(value_39, value_39_2);
  ck_assert_int_eq(result, 1);

  s21_decimal value_40 = {{0, 0, 0, 0}, S21_NAN};
  s21_decimal value_40_2 = {{13, 0, 0, 0}, S21_NAN};
  result = s21_is_not_equal(value_40, value_40_2);
  ck_assert_int_eq(result, 1);
}

START_TEST(s21_truncate_test) {
  s21_decimal value_1 = {{111000, 0, 0, 196608}, S21_NORMAL};
  s21_decimal result_1 = {{0, 0, 0, 0}, S21_NORMAL};
  int result = s21_truncate(value_1, &result_1);
  ck_assert_int_eq(result_1.bits[0], 111);
  ck_assert_int_eq(result_1.bits[1], 0);
  ck_assert_int_eq(result_1.bits[2], 0);
  ck_assert_int_eq(result_1.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_1.value_type, 0);

  s21_decimal value_2 = {{329573, 0, 0, 131072}, S21_NORMAL};
  s21_decimal result_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_truncate(value_2, &result_2);
  ck_assert_int_eq(result_2.bits[0], 3295);
  ck_assert_int_eq(result_2.bits[1], 0);
  ck_assert_int_eq(result_2.bits[2], 0);
  ck_assert_int_eq(result_2.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_2.value_type, 0);

  s21_decimal value_3 = {{4234, 0, 0, 196608}, S21_NORMAL};
  s21_decimal result_3 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_truncate(value_3, &result_3);
  ck_assert_int_eq(result_3.bits[0], 4);
  ck_assert_int_eq(result_3.bits[1], 0);
  ck_assert_int_eq(result_3.bits[2], 0);
  ck_assert_int_eq(result_3.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_3.value_type, 0);

  s21_decimal value_4 = {{1, 0, 0, 196608}, S21_NORMAL};
  s21_decimal result_4 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_truncate(value_4, &result_4);
  ck_assert_int_eq(result_4.bits[0], 0);
  ck_assert_int_eq(result_4.bits[1], 0);
  ck_assert_int_eq(result_4.bits[2], 0);
  ck_assert_int_eq(result_4.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_4.value_type, 0);

  s21_decimal value_5 = {{0, 0, 0, 196608}, S21_NORMAL};
  s21_decimal result_5 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_truncate(value_5, &result_5);
  ck_assert_int_eq(result_4.bits[0], 0);
  ck_assert_int_eq(result_4.bits[1], 0);
  ck_assert_int_eq(result_4.bits[2], 0);
  ck_assert_int_eq(result_4.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_5.value_type, 0);

  s21_decimal value_6 = {{10000000, 0, 0, 196608}, S21_NORMAL};
  s21_decimal result_6 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_truncate(value_6, &result_6);
  ck_assert_int_eq(result_6.bits[0], 10000);
  ck_assert_int_eq(result_6.bits[1], 0);
  ck_assert_int_eq(result_6.bits[2], 0);
  ck_assert_int_eq(result_6.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_6.value_type, 0);

  s21_decimal value_7 = {{10000, 0, 0, 196608}, S21_NORMAL};
  s21_decimal result_7 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_truncate(value_7, &result_7);
  ck_assert_int_eq(result_7.bits[0], 10);
  ck_assert_int_eq(result_7.bits[1], 0);
  ck_assert_int_eq(result_7.bits[2], 0);
  ck_assert_int_eq(result_7.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_7.value_type, 0);

  s21_decimal value_8 = {{1000, 0, 0, 196608}, S21_NORMAL};
  s21_decimal result_8 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_truncate(value_8, &result_8);
  ck_assert_int_eq(result_8.bits[0], 1);
  ck_assert_int_eq(result_8.bits[1], 0);
  ck_assert_int_eq(result_8.bits[2], 0);
  ck_assert_int_eq(result_8.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_8.value_type, 0);

  s21_decimal value_9 = {{100, 0, 0, 196608}, S21_NORMAL};
  s21_decimal result_9 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_truncate(value_9, &result_9);
  ck_assert_int_eq(result_9.bits[0], 0);
  ck_assert_int_eq(result_9.bits[1], 0);
  ck_assert_int_eq(result_9.bits[2], 0);
  ck_assert_int_eq(result_9.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_9.value_type, 0);

  s21_decimal value_10 = {{38560, 0, 0, 2147745792}, S21_NORMAL};
  s21_decimal result_10 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_truncate(value_10, &result_10);
  ck_assert_int_eq(result_10.bits[0], 3);
  ck_assert_int_eq(result_10.bits[1], 0);
  ck_assert_int_eq(result_10.bits[2], 0);
  ck_assert_int_eq(result_10.bits[3], 2147483648);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_10.value_type, 0);

  s21_decimal value_11 = {{1000, 0, 0, 2147745792}, S21_NORMAL};
  s21_decimal result_11 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_truncate(value_11, &result_11);
  ck_assert_int_eq(result_11.bits[0], 0);
  ck_assert_int_eq(result_11.bits[1], 0);
  ck_assert_int_eq(result_11.bits[2], 0);
  ck_assert_int_eq(result_11.bits[3], 2147483648);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_11.value_type, 0);

  s21_decimal value_12 = {{10, 0, 0, 2147745792}, S21_NORMAL};
  s21_decimal result_12 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_truncate(value_12, &result_12);
  ck_assert_int_eq(result_12.bits[0], 0);
  ck_assert_int_eq(result_12.bits[1], 0);
  ck_assert_int_eq(result_12.bits[2], 0);
  ck_assert_int_eq(result_12.bits[3], 2147483648);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_12.value_type, 0);

  s21_decimal value_13 = {{23487565, 0, 0, 2147745792}, S21_NORMAL};
  s21_decimal result_13 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_truncate(value_13, &result_13);
  ck_assert_int_eq(result_13.bits[0], 2348);
  ck_assert_int_eq(result_13.bits[1], 0);
  ck_assert_int_eq(result_13.bits[2], 0);
  ck_assert_int_eq(result_13.bits[3], 2147483648);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_13.value_type, 0);

  s21_decimal value_14 = {{4284967295, 0, 0, 589824}, S21_NORMAL};
  s21_decimal result_14 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_truncate(value_14, &result_14);
  ck_assert_int_eq(result_14.bits[0], 4);
  ck_assert_int_eq(result_14.bits[1], 0);
  ck_assert_int_eq(result_14.bits[2], 0);
  ck_assert_int_eq(result_14.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_14.value_type, 0);

  s21_decimal value_16 = {{1546, 0, 0, 0}, S21_NORMAL};
  s21_decimal result_16 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_truncate(value_16, &result_16);
  ck_assert_int_eq(result_16.bits[0], 1546);
  ck_assert_int_eq(result_16.bits[1], 0);
  ck_assert_int_eq(result_16.bits[2], 0);
  ck_assert_int_eq(result_16.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_16.value_type, 0);
}

START_TEST(s21_negate_test) {
  s21_decimal value_1 = {{111000, 0, 0, 196608}, S21_NORMAL};
  s21_decimal result_1 = {{0, 0, 0, 0}, S21_NORMAL};
  int result = s21_negate(value_1, &result_1);
  ck_assert_int_eq(result_1.bits[0], 111000);
  ck_assert_int_eq(result_1.bits[1], 0);
  ck_assert_int_eq(result_1.bits[2], 0);
  ck_assert_int_eq(result_1.bits[3], 2147680256);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_1.value_type, 0);

  s21_decimal value_2 = {{3535, 0, 0, 0}, S21_NORMAL};
  s21_decimal result_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_negate(value_2, &result_2);
  ck_assert_int_eq(result_2.bits[0], 3535);
  ck_assert_int_eq(result_2.bits[1], 0);
  ck_assert_int_eq(result_2.bits[2], 0);
  ck_assert_int_eq(result_2.bits[3], 2147483648);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_2.value_type, 0);

  s21_decimal value_3 = {{3535, 0, 0, 2147483648}, S21_NORMAL};
  s21_decimal result_3 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_negate(value_3, &result_3);
  ck_assert_int_eq(result_3.bits[0], 3535);
  ck_assert_int_eq(result_3.bits[1], 0);
  ck_assert_int_eq(result_3.bits[2], 0);
  ck_assert_int_eq(result_3.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_3.value_type, 0);

  s21_decimal value_4 = {{111000, 0, 0, 2147680256}, S21_NORMAL};
  s21_decimal result_4 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_negate(value_4, &result_4);
  ck_assert_int_eq(result_4.bits[0], 111000);
  ck_assert_int_eq(result_4.bits[1], 0);
  ck_assert_int_eq(result_4.bits[2], 0);
  ck_assert_int_eq(result_4.bits[3], 196608);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_4.value_type, 0);
}

START_TEST(s21_floor_test) {
  s21_decimal value_1 = {{111000, 0, 0, 196608}, S21_NORMAL};
  s21_decimal result_1 = {{0, 0, 0, 0}, S21_NORMAL};
  int result = s21_floor(value_1, &result_1);
  ck_assert_int_eq(result_1.bits[0], 111);
  ck_assert_int_eq(result_1.bits[1], 0);
  ck_assert_int_eq(result_1.bits[2], 0);
  ck_assert_int_eq(result_1.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_1.value_type, 0);

  s21_decimal value_2 = {{329573, 0, 0, 131072}, S21_NORMAL};
  s21_decimal result_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_floor(value_2, &result_2);
  ck_assert_int_eq(result_2.bits[0], 3295);
  ck_assert_int_eq(result_2.bits[1], 0);
  ck_assert_int_eq(result_2.bits[2], 0);
  ck_assert_int_eq(result_2.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_2.value_type, 0);

  s21_decimal value_3 = {{4234, 0, 0, 196608}, S21_NORMAL};
  s21_decimal result_3 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_floor(value_3, &result_3);
  ck_assert_int_eq(result_3.bits[0], 4);
  ck_assert_int_eq(result_3.bits[1], 0);
  ck_assert_int_eq(result_3.bits[2], 0);
  ck_assert_int_eq(result_3.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_3.value_type, 0);

  s21_decimal value_4 = {{1, 0, 0, 196608}, S21_NORMAL};
  s21_decimal result_4 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_floor(value_4, &result_4);
  ck_assert_int_eq(result_4.bits[0], 0);
  ck_assert_int_eq(result_4.bits[1], 0);
  ck_assert_int_eq(result_4.bits[2], 0);
  ck_assert_int_eq(result_4.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_4.value_type, 0);

  s21_decimal value_5 = {{0, 0, 0, 196608}, S21_NORMAL};
  s21_decimal result_5 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_floor(value_5, &result_5);
  ck_assert_int_eq(result_4.bits[0], 0);
  ck_assert_int_eq(result_4.bits[1], 0);
  ck_assert_int_eq(result_4.bits[2], 0);
  ck_assert_int_eq(result_4.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_5.value_type, 0);

  s21_decimal value_6 = {{10000000, 0, 0, 196608}, S21_NORMAL};
  s21_decimal result_6 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_truncate(value_6, &result_6);
  ck_assert_int_eq(result_6.bits[0], 10000);
  ck_assert_int_eq(result_6.bits[1], 0);
  ck_assert_int_eq(result_6.bits[2], 0);
  ck_assert_int_eq(result_6.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_6.value_type, 0);

  s21_decimal value_7 = {{10000, 0, 0, 196608}, S21_NORMAL};
  s21_decimal result_7 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_floor(value_7, &result_7);
  ck_assert_int_eq(result_7.bits[0], 10);
  ck_assert_int_eq(result_7.bits[1], 0);
  ck_assert_int_eq(result_7.bits[2], 0);
  ck_assert_int_eq(result_7.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_7.value_type, 0);

  s21_decimal value_8 = {{1000, 0, 0, 196608}, S21_NORMAL};
  s21_decimal result_8 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_floor(value_8, &result_8);
  ck_assert_int_eq(result_8.bits[0], 1);
  ck_assert_int_eq(result_8.bits[1], 0);
  ck_assert_int_eq(result_8.bits[2], 0);
  ck_assert_int_eq(result_8.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_8.value_type, 0);

  s21_decimal value_9 = {{100, 0, 0, 196608}, S21_NORMAL};
  s21_decimal result_9 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_floor(value_9, &result_9);
  ck_assert_int_eq(result_9.bits[0], 0);
  ck_assert_int_eq(result_9.bits[1], 0);
  ck_assert_int_eq(result_9.bits[2], 0);
  ck_assert_int_eq(result_9.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_9.value_type, 0);

  s21_decimal value_10 = {{48560, 0, 0, 2147745792}, S21_NORMAL};
  s21_decimal result_10 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_floor(value_10, &result_10);
  ck_assert_int_eq(result_10.bits[0], 5);
  ck_assert_int_eq(result_10.bits[1], 0);
  ck_assert_int_eq(result_10.bits[2], 0);
  ck_assert_int_eq(result_10.bits[3], 2147483648);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_10.value_type, 0);

  s21_decimal value_11 = {{1000, 0, 0, 262144}, S21_NORMAL};
  s21_decimal result_11 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_floor(value_11, &result_11);
  ck_assert_int_eq(result_11.bits[0], 0);
  ck_assert_int_eq(result_11.bits[1], 0);
  ck_assert_int_eq(result_11.bits[2], 0);
  ck_assert_int_eq(result_11.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_11.value_type, 0);

  s21_decimal value_12 = {{10, 0, 0, 2147745792}, S21_NORMAL};
  s21_decimal result_12 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_floor(value_12, &result_12);
  ck_assert_int_eq(result_12.bits[0], 1);
  ck_assert_int_eq(result_12.bits[1], 0);
  ck_assert_int_eq(result_12.bits[2], 0);
  ck_assert_int_eq(result_12.bits[3], 2147483648);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_12.value_type, 0);

  s21_decimal value_13 = {{23487565, 0, 0, 2147745792}, S21_NORMAL};
  s21_decimal result_13 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_truncate(value_13, &result_13);
  ck_assert_int_eq(result_13.bits[0], 2348);
  ck_assert_int_eq(result_13.bits[1], 0);
  ck_assert_int_eq(result_13.bits[2], 0);
  ck_assert_int_eq(result_13.bits[3], 2147483648);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_13.value_type, 0);

  s21_decimal value_14 = {{4284967295, 0, 0, 589824}, S21_NORMAL};
  s21_decimal result_14 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_truncate(value_14, &result_14);
  ck_assert_int_eq(result_14.bits[0], 4);
  ck_assert_int_eq(result_14.bits[1], 0);
  ck_assert_int_eq(result_14.bits[2], 0);
  ck_assert_int_eq(result_14.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_14.value_type, 0);
}

START_TEST(s21_round_test) {
  s21_decimal value_1 = {{5465567, 0, 0, 65536}, S21_NORMAL};
  s21_decimal result_1 = {{0, 0, 0, 0}, S21_NORMAL};
  int result = s21_round(value_1, &result_1);
  ck_assert_int_eq(result_1.bits[0], 546557);
  ck_assert_int_eq(result_1.bits[1], 0);
  ck_assert_int_eq(result_1.bits[2], 0);
  ck_assert_int_eq(result_1.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_1.value_type, 0);

  s21_decimal value_2 = {{5462, 0, 0, 65536}, S21_NORMAL};
  s21_decimal result_2 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_round(value_2, &result_2);
  ck_assert_int_eq(result_2.bits[0], 546);
  ck_assert_int_eq(result_2.bits[1], 0);
  ck_assert_int_eq(result_2.bits[2], 0);
  ck_assert_int_eq(result_2.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_2.value_type, 0);

  s21_decimal value_3 = {{54622343, 0, 0, 65536}, S21_NORMAL};
  s21_decimal result_3 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_round(value_3, &result_3);
  ck_assert_int_eq(result_3.bits[0], 5462234);
  ck_assert_int_eq(result_3.bits[1], 0);
  ck_assert_int_eq(result_3.bits[2], 0);
  ck_assert_int_eq(result_3.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_3.value_type, 0);

  s21_decimal value_4 = {{546, 0, 0, 2147549184}, S21_NORMAL};
  s21_decimal result_4 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_round(value_4, &result_4);
  ck_assert_int_eq(result_4.bits[0], 55);
  ck_assert_int_eq(result_4.bits[1], 0);
  ck_assert_int_eq(result_4.bits[2], 0);
  ck_assert_int_eq(result_4.bits[3], 2147483648);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_4.value_type, 0);

  s21_decimal value_5 = {{541, 0, 0, 2147549184}, S21_NORMAL};
  s21_decimal result_5 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_round(value_5, &result_5);
  ck_assert_int_eq(result_5.bits[0], 54);
  ck_assert_int_eq(result_5.bits[1], 0);
  ck_assert_int_eq(result_5.bits[2], 0);
  ck_assert_int_eq(result_5.bits[3], 2147483648);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_5.value_type, 0);

  s21_decimal value_9 = {{1, 0, 0, 262144}, S21_NORMAL};
  s21_decimal result_9 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_round(value_9, &result_9);
  ck_assert_int_eq(result_9.bits[0], 0);
  ck_assert_int_eq(result_9.bits[1], 0);
  ck_assert_int_eq(result_9.bits[2], 0);
  ck_assert_int_eq(result_9.bits[3], 0);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(result_9.value_type, 0);
}

START_TEST(s21_from_int_to_decimal_test) {
  int num = -12345678;
  s21_decimal d_num;
  s21_from_int_to_decimal(num, &d_num);
  ck_assert_int_eq(d_num.bits[0], 12345678);
  ck_assert_int_eq(d_num.bits[1], 0);
  ck_assert_int_eq(d_num.bits[2], 0);
  ck_assert_int_eq(d_num.bits[3], 2147483648);

  num = 908765432;
  s21_from_int_to_decimal(num, &d_num);
  ck_assert_int_eq(d_num.bits[0], 908765432);
  ck_assert_int_eq(d_num.bits[1], 0);
  ck_assert_int_eq(d_num.bits[2], 0);
  ck_assert_int_eq(d_num.bits[3], 0);

  num = 1;
  s21_from_int_to_decimal(num, &d_num);
  ck_assert_int_eq(d_num.bits[0], 1);
  ck_assert_int_eq(d_num.bits[1], 0);
  ck_assert_int_eq(d_num.bits[2], 0);
  ck_assert_int_eq(d_num.bits[3], 0);

  num = -1;
  s21_from_int_to_decimal(num, &d_num);
  ck_assert_int_eq(d_num.bits[0], 1);
  ck_assert_int_eq(d_num.bits[1], 0);
  ck_assert_int_eq(d_num.bits[2], 0);
  ck_assert_int_eq(d_num.bits[3], 2147483648);

  num = 0;
  s21_from_int_to_decimal(num, &d_num);
  ck_assert_int_eq(d_num.bits[0], 0);
  ck_assert_int_eq(d_num.bits[1], 0);
  ck_assert_int_eq(d_num.bits[2], 0);
  ck_assert_int_eq(d_num.bits[3], 0);
}

START_TEST(s21_from_float_to_decimal_test) {
  int result = 0;

  float num = -1;
  s21_decimal d_num;
  result = s21_from_float_to_decimal(num, &d_num);
  ck_assert_int_eq(d_num.bits[0], 1);
  ck_assert_int_eq(d_num.bits[1], 0);
  ck_assert_int_eq(d_num.bits[2], 0);
  ck_assert_int_eq(d_num.bits[3], 2147483648);
  ck_assert_int_eq(result, 0);

  num = 1;
  result = s21_from_float_to_decimal(num, &d_num);
  ck_assert_int_eq(d_num.bits[0], 1);
  ck_assert_int_eq(d_num.bits[1], 0);
  ck_assert_int_eq(d_num.bits[2], 0);
  ck_assert_int_eq(d_num.bits[3], 0);
  ck_assert_int_eq(result, 0);

  num = INFINITY;
  result = s21_from_float_to_decimal(num, &d_num);
  ck_assert_int_eq(d_num.bits[0], 0);
  ck_assert_int_eq(d_num.bits[1], 0);
  ck_assert_int_eq(d_num.bits[2], 0);
  ck_assert_int_eq(d_num.bits[3], 0);
  ck_assert_int_eq(d_num.value_type, S21_INF);
  ck_assert_int_eq(result, 1);

  num = -INFINITY;
  result = s21_from_float_to_decimal(num, &d_num);
  ck_assert_int_eq(d_num.bits[0], 0);
  ck_assert_int_eq(d_num.bits[1], 0);
  ck_assert_int_eq(d_num.bits[2], 0);
  ck_assert_int_eq(d_num.bits[3], 0);
  ck_assert_int_eq(d_num.value_type, S21_INF);
  ck_assert_int_eq(result, 1);

  num = NAN;
  result = s21_from_float_to_decimal(num, &d_num);
  ck_assert_int_eq(d_num.bits[0], 0);
  ck_assert_int_eq(d_num.bits[1], 0);
  ck_assert_int_eq(d_num.bits[2], 0);
  ck_assert_int_eq(d_num.bits[3], 0);
  ck_assert_int_eq(d_num.value_type, S21_NAN);
  ck_assert_int_eq(result, 1);

  num = 1e-28;
  result = s21_from_float_to_decimal(num, &d_num);
  ck_assert_int_eq(d_num.bits[0], 0);
  ck_assert_int_eq(d_num.bits[1], 0);
  ck_assert_int_eq(d_num.bits[2], 0);
  ck_assert_int_eq(d_num.bits[3], 0);
  ck_assert_int_eq(d_num.value_type, S21_NORMAL);
  ck_assert_int_eq(result, 0);

  num = 1e-27;
  result = s21_from_float_to_decimal(num, &d_num);
  ck_assert_int_eq(d_num.bits[0], 1);
  ck_assert_int_eq(d_num.bits[1], 0);
  ck_assert_int_eq(d_num.bits[2], 0);
  ck_assert_int_eq(d_num.bits[3], 1769472);
  ck_assert_int_eq(d_num.value_type, S21_NORMAL);
  ck_assert_int_eq(result, 0);

  num = 79228162514264337593543950336.;
  result = s21_from_float_to_decimal(num, &d_num);
  ck_assert_int_eq(d_num.bits[0], 0);
  ck_assert_int_eq(d_num.bits[1], 0);
  ck_assert_int_eq(d_num.bits[2], 0);
  ck_assert_int_eq(d_num.bits[3], 0);
  ck_assert_int_eq(d_num.value_type, S21_NORMAL);
  ck_assert_int_eq(result, 0);

  num = 0;
  result = s21_from_float_to_decimal(num, &d_num);
  ck_assert_int_eq(d_num.bits[0], 0);
  ck_assert_int_eq(d_num.bits[1], 0);
  ck_assert_int_eq(d_num.bits[2], 0);
  ck_assert_int_eq(d_num.bits[3], 0);
  ck_assert_int_eq(d_num.value_type, S21_NORMAL);
  ck_assert_int_eq(result, 0);
}

START_TEST(s21_from_decimal_to_int_test) {
  int result = 0;
  int num = 0;

  s21_decimal d_num2 = {{123, 0, 0, 0}, S21_NORMAL};
  result = s21_from_decimal_to_int(d_num2, &num);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(num, 123);

  num = 0;
  result = 0;
  s21_decimal d_num3 = {{123123, 0, 0, 196608}, S21_NORMAL};
  result = s21_from_decimal_to_int(d_num3, &num);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(num, 123);

  num = 0;
  result = 0;
  s21_decimal d_num4 = {{123123, 0, 0, 65536}, S21_NORMAL};
  result = s21_from_decimal_to_int(d_num4, &num);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(num, 12312);

  num = 0;
  result = 0;
  s21_decimal d_num5 = {{25, 0, 0, 131072}, S21_NORMAL};
  result = s21_from_decimal_to_int(d_num5, &num);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(num, 0);

  num = 0;
  result = 0;
  s21_decimal d_num6 = {{0, 0, 0, 0}, S21_NORMAL};
  result = s21_from_decimal_to_int(d_num6, &num);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(num, 0);

  num = 0;
  result = 0;
  s21_decimal d_num7 = {{3, 0, 0, 1 << 31}, S21_NORMAL};
  result = s21_from_decimal_to_int(d_num7, &num);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(num, -3);

  num = 0;
  result = 0;
  s21_decimal d_num8 = {{3, 0, 0, 29 << 16}, S21_NORMAL};
  result = s21_from_decimal_to_int(d_num8, &num);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(num, 0);
}

START_TEST(s21_from_decimal_to_float_test) {
  int result = 0;
  float num = 0;

  s21_decimal d_num2 = {{123, 0, 0, 0}, S21_NORMAL};
  result = s21_from_decimal_to_float(d_num2, &num);
  ck_assert_int_eq(result, 0);
  ck_assert_float_eq(num, 123);

  num = 0;
  result = 0;
  s21_decimal d_num3 = {{123123, 0, 0, 196608}, S21_NORMAL};
  result = s21_from_decimal_to_float(d_num3, &num);
  ck_assert_int_eq(result, 0);
  ck_assert_float_eq(num, 123.123);

  num = 0;
  result = 0;
  s21_decimal d_num4 = {{123123, 0, 0, 65536}, S21_NORMAL};
  result = s21_from_decimal_to_float(d_num4, &num);
  ck_assert_int_eq(result, 0);
  ck_assert_float_eq(num, 12312.3);

  num = 0;
  result = 0;
  s21_decimal d_num5 = {{25, 0, 0, 131072}, S21_NORMAL};
  result = s21_from_decimal_to_float(d_num5, &num);
  ck_assert_int_eq(result, 0);
  ck_assert_float_eq(num, 0.25);

  num = 0;
  result = 0;
  s21_decimal d_num6 = {{4294967295, 4294967295, 4294967295, 0}, S21_NORMAL};
  result = s21_from_decimal_to_float(d_num6, &num);
  ck_assert_int_eq(result, 0);
  ck_assert_float_eq(num, 79228162514264337593543950336.000000);

  num = 0;
  result = 0;
  s21_decimal d_num7 = {{0, 0, 0, 0}, S21_N_INF};
  result = s21_from_decimal_to_float(d_num7, &num);
  ck_assert_int_eq(result, 1);
  ck_assert_float_eq(num, -INFINITY);

  num = 0;
  result = 0;
  s21_decimal d_num8 = {{0, 0, 0, 0}, S21_INF};
  result = s21_from_decimal_to_float(d_num8, &num);
  ck_assert_int_eq(result, 1);
  ck_assert_float_eq(num, INFINITY);

  num = 0;
  result = 0;
  s21_decimal d_num9 = {{4294967295, 4294967295, 4294967295, 0}, S21_NAN};
  result = s21_from_decimal_to_float(d_num9, &num);
  ck_assert_int_eq(result, 1);
  ck_assert_float_nan(num);

  num = 0;
  result = 0;
  s21_decimal d_num10 = {{13, 0, 0, 1 << 31}, S21_NORMAL};
  result = s21_from_decimal_to_float(d_num10, &num);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(num, -13);

  num = 0;
  result = 0;
  s21_decimal d_num11 = {{13, 0, 0, 29 << 16}, S21_NORMAL};
  result = s21_from_decimal_to_float(d_num11, &num);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(num, 0);
}

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);

  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_from_int_to_decimal_test);
  tcase_add_test(tc1_1, s21_from_decimal_to_int_test);
  tcase_add_test(tc1_1, s21_from_float_to_decimal_test);
  tcase_add_test(tc1_1, s21_from_decimal_to_float_test);
  tcase_add_test(tc1_1, s21_add_test);
  tcase_add_test(tc1_1, s21_sub_test);
  tcase_add_test(tc1_1, s21_div_test);
  tcase_add_test(tc1_1, s21_mul_test);
  tcase_add_test(tc1_1, s21_mod_test);
  tcase_add_test(tc1_1, s21_is_less_test);
  tcase_add_test(tc1_1, s21_is_greater_test);
  tcase_add_test(tc1_1, s21_is_less_or_equal_test);
  tcase_add_test(tc1_1, s21_is_greater_or_equal_test);
  tcase_add_test(tc1_1, s21_is_equal_test);
  tcase_add_test(tc1_1, s21_is_not_equal_test);
  tcase_add_test(tc1_1, s21_truncate_test);
  tcase_add_test(tc1_1, s21_negate_test);
  tcase_add_test(tc1_1, s21_floor_test);
  tcase_add_test(tc1_1, s21_round_test);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

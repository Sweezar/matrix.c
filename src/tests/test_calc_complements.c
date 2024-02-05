#include "s21_tests.h"

START_TEST(s21_calc_complements_1) {
  matrix_t matrix_1;
  matrix_t result;
  matrix_t expected_result;

  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &expected_result);
  matrix_1.matrix[0][0] = 127.0;
  matrix_1.matrix[0][1] = -27.0;
  matrix_1.matrix[0][2] = 5.0;
  matrix_1.matrix[1][1] = 58.0;
  matrix_1.matrix[1][2] = -3.0;
  matrix_1.matrix[2][0] = 1.0;
  matrix_1.matrix[2][1] = -2.0;
  matrix_1.matrix[2][2] = 5.0;

  expected_result.matrix[0][0] = 284.0;
  expected_result.matrix[0][1] = -3.0;
  expected_result.matrix[0][2] = -58.0;
  expected_result.matrix[1][0] = 125.0;
  expected_result.matrix[1][1] = 630.0;
  expected_result.matrix[1][2] = 227.0;
  expected_result.matrix[2][0] = -209.0;
  expected_result.matrix[2][1] = 381.0;
  expected_result.matrix[2][2] = 7366.0;

  int return_value = s21_calc_complements(&matrix_1, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected_result), 1);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  matrix_t matrix_1;
  matrix_t result;
  matrix_t expected_result;

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &expected_result);
  matrix_1.matrix[0][0] = 127.0;
  matrix_1.matrix[0][1] = -27.0;
  matrix_1.matrix[0][2] = 5.0;
  matrix_1.matrix[0][3] = 1.0;
  matrix_1.matrix[1][1] = 58.0;
  matrix_1.matrix[1][2] = -3.0;
  matrix_1.matrix[1][3] = 2.0;
  matrix_1.matrix[2][0] = 1.0;
  matrix_1.matrix[2][1] = -2.0;
  matrix_1.matrix[2][2] = 5.0;
  matrix_1.matrix[2][3] = 3.0;
  matrix_1.matrix[3][0] = 3.0;
  matrix_1.matrix[3][1] = -4.0;
  matrix_1.matrix[3][2] = 0;
  matrix_1.matrix[3][3] = 4.0;

  expected_result.matrix[0][0] = 1212.0;
  expected_result.matrix[0][1] = 45.0;
  expected_result.matrix[0][2] = 294.0;
  expected_result.matrix[0][3] = -864.0;
  expected_result.matrix[1][0] = 540.0;
  expected_result.matrix[1][1] = 2550.0;
  expected_result.matrix[1][2] = -375.0;
  expected_result.matrix[1][3] = 2145.0;
  expected_result.matrix[2][0] = -888.0;
  expected_result.matrix[2][1] = 1485.0;
  expected_result.matrix[2][2] = 30144.0;
  expected_result.matrix[2][3] = 2151.0;
  expected_result.matrix[3][0] = 93.0;
  expected_result.matrix[3][1] = -2400.0;
  expected_result.matrix[3][2] = -22494.0;
  expected_result.matrix[3][3] = 35859.0;

  int return_value = s21_calc_complements(&matrix_1, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected_result), 1);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(s21_calc_complements_3) {
  matrix_t matrix_1;
  matrix_t result;
  matrix_t expected_result;

  s21_create_matrix(5, 5, &matrix_1);
  s21_create_matrix(5, 5, &expected_result);
  matrix_1.matrix[0][0] = 127.0;
  matrix_1.matrix[0][1] = -27.0;
  matrix_1.matrix[0][2] = 5.0;
  matrix_1.matrix[0][3] = 1.0;
  matrix_1.matrix[0][4] = -1.0;
  matrix_1.matrix[1][0] = 0;
  matrix_1.matrix[1][1] = 58.0;
  matrix_1.matrix[1][2] = -3.0;
  matrix_1.matrix[1][3] = 2.0;
  matrix_1.matrix[1][4] = -2.0;
  matrix_1.matrix[2][0] = 1.0;
  matrix_1.matrix[2][1] = -2.0;
  matrix_1.matrix[2][2] = 5.0;
  matrix_1.matrix[2][3] = 3.0;
  matrix_1.matrix[2][4] = -3.0;
  matrix_1.matrix[3][0] = 3.0;
  matrix_1.matrix[3][1] = -4.0;
  matrix_1.matrix[3][2] = 0;
  matrix_1.matrix[3][3] = 4.0;
  matrix_1.matrix[3][4] = -4.0;
  matrix_1.matrix[4][0] = 5.0;
  matrix_1.matrix[4][1] = 4.0;
  matrix_1.matrix[4][2] = 2.0;
  matrix_1.matrix[4][3] = 24.0;
  matrix_1.matrix[4][4] = 11.0;

  expected_result.matrix[0][0] = 42420.0;
  expected_result.matrix[0][1] = 1575.0;
  expected_result.matrix[0][2] = 10290.0;
  expected_result.matrix[0][3] = -16332.0;
  expected_result.matrix[0][4] = 13908.0;
  expected_result.matrix[1][0] = 18900;
  expected_result.matrix[1][1] = 89250.0;
  expected_result.matrix[1][2] = -13125.0;
  expected_result.matrix[1][3] = 11445.0;
  expected_result.matrix[1][4] = -63630.0;
  expected_result.matrix[2][0] = -31080.0;
  expected_result.matrix[2][1] = 51975.0;
  expected_result.matrix[2][2] = 1055040.0;
  expected_result.matrix[2][3] = -38127.0;
  expected_result.matrix[2][4] = -113412.0;
  expected_result.matrix[3][0] = 3255.0;
  expected_result.matrix[3][1] = -84000.0;
  expected_result.matrix[3][2] = -787290;
  expected_result.matrix[3][3] = 448572.0;
  expected_result.matrix[3][4] = -806493.0;
  expected_result.matrix[4][0] = 0;
  expected_result.matrix[4][1] = 0;
  expected_result.matrix[4][2] = 0;
  expected_result.matrix[4][3] = 153315.0;
  expected_result.matrix[4][4] = 153315.0;

  int return_value = s21_calc_complements(&matrix_1, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected_result), 1);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(s21_calc_complements_4) {
  matrix_t matrix_1;
  matrix_t result;

  s21_create_matrix(5, 3, &matrix_1);

  int return_value = s21_calc_complements(&matrix_1, &result);
  ck_assert_int_eq(return_value, 2);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(s21_calc_complements_5) {
  matrix_t matrix_1;

  s21_create_matrix(5, 3, &matrix_1);

  int return_value = s21_calc_complements(&matrix_1, NULL);
  ck_assert_int_eq(return_value, 1);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(s21_calc_complements_6) {
  matrix_t matrix_1;
  matrix_t result;

  s21_create_matrix(5, -3, &matrix_1);

  int return_value = s21_calc_complements(&matrix_1, &result);
  ck_assert_int_eq(return_value, 1);

  s21_remove_matrix(&matrix_1);
}
END_TEST

Suite *test_calc_complements(void) {
  Suite *s = suite_create("\033[45m-=S21_CALC_COMPLEMENTS=-\033[0m");
  TCase *tc = tcase_create("CALC_COMPLEMENTS");

  tcase_add_test(tc, s21_calc_complements_1);
  tcase_add_test(tc, s21_calc_complements_2);
  tcase_add_test(tc, s21_calc_complements_3);
  tcase_add_test(tc, s21_calc_complements_4);
  tcase_add_test(tc, s21_calc_complements_5);
  tcase_add_test(tc, s21_calc_complements_6);

  suite_add_tcase(s, tc);
  return s;
}
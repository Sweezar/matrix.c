#include "s21_tests.h"

START_TEST(s21_mult_number_1) {
  matrix_t matrix_1;
  matrix_t result;
  matrix_t expected_result;
  double num = 9.2;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &expected_result);

  matrix_1.matrix[0][0] = 9.4;
  matrix_1.matrix[1][0] = 9.7;
  matrix_1.matrix[0][2] = 19.4;

  expected_result.matrix[0][0] = matrix_1.matrix[0][0] * num;
  expected_result.matrix[1][0] = matrix_1.matrix[1][0] * num;
  expected_result.matrix[0][2] = matrix_1.matrix[0][2] * num;

  int return_value = s21_mult_number(&matrix_1, num, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected_result), 1);
  ck_assert_int_eq(return_value, 0);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(s21_mult_number_2) {
  matrix_t matrix_1;
  double num = 9.2;
  matrix_t result;
  s21_create_matrix(3, 2, &matrix_1);
  int return_value = s21_mult_number(&matrix_1, num, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &matrix_1), 1);
  ck_assert_int_eq(return_value, 0);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_3) {
  matrix_t matrix_1;
  double num = 8.2;
  matrix_t result;
  matrix_t expected_result;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &expected_result);

  matrix_1.matrix[0][0] = 127.0;
  matrix_1.matrix[0][1] = 27.0;
  matrix_1.matrix[1][1] = 57.0;

  expected_result.matrix[0][0] = matrix_1.matrix[0][0] * num;
  expected_result.matrix[0][1] = matrix_1.matrix[0][1] * num;
  expected_result.matrix[1][1] = matrix_1.matrix[1][1] * num;

  int return_value = s21_mult_number(&matrix_1, num, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected_result), 1);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(s21_mult_number_4) {
  matrix_t matrix_1;
  double num = 4.7;
  s21_create_matrix(3, 3, &matrix_1);

  int return_value = s21_mult_number(&matrix_1, num, NULL);
  ck_assert_int_eq(return_value, 1);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(s21_mult_number_5) {
  matrix_t matrix_1;
  matrix_t result;
  double num = 4.7;
  s21_create_matrix(3, 3, &matrix_1);
  s21_remove_matrix(&matrix_1);

  int return_value = s21_mult_number(&matrix_1, num, &result);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

Suite *test_mult_number(void) {
  Suite *s = suite_create("\033[45m-=S21_MULT_NUMBER=-\033[0m");
  TCase *tc = tcase_create("MULT_NUMBER");

  tcase_add_test(tc, s21_mult_number_1);
  tcase_add_test(tc, s21_mult_number_2);
  tcase_add_test(tc, s21_mult_number_3);
  tcase_add_test(tc, s21_mult_number_4);
  tcase_add_test(tc, s21_mult_number_5);

  suite_add_tcase(s, tc);
  return s;
}
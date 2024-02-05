#include "s21_tests.h"

START_TEST(s21_mult_matrix_1) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &matrix_2);
  int return_value = s21_mult_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &matrix_1), 1);
  ck_assert_int_eq(return_value, 0);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  s21_create_matrix(3, 2, &matrix_1);
  s21_create_matrix(3, 3, &matrix_2);
  int return_value = s21_mult_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(return_value, 2);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  matrix_t expected_result;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &matrix_2);
  s21_create_matrix(3, 3, &expected_result);

  matrix_1.matrix[0][0] = 127.0;
  matrix_1.matrix[0][1] = 27.0;
  matrix_1.matrix[1][1] = 57.0;

  matrix_2.matrix[0][0] = 127.0;
  matrix_2.matrix[0][1] = 27.0;
  matrix_2.matrix[1][1] = 57.0;

  expected_result.matrix[0][0] = 16129.0;
  expected_result.matrix[0][1] = 4968.0;
  expected_result.matrix[1][1] = 3249.0;

  int return_value = s21_mult_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected_result), 1);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(s21_mult_matrix_4) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &matrix_2);
  int return_value = s21_mult_matrix(&matrix_1, &matrix_2, NULL);
  ck_assert_int_eq(return_value, 1);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(s21_mult_matrix_5) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, -3, &matrix_2);
  int return_value = s21_mult_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(return_value, 1);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

Suite *test_mult_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_MULT_MATRIX=-\033[0m");
  TCase *tc = tcase_create("MULT_MATRIX");

  tcase_add_test(tc, s21_mult_matrix_2);
  tcase_add_test(tc, s21_mult_matrix_1);
  tcase_add_test(tc, s21_mult_matrix_3);
  tcase_add_test(tc, s21_mult_matrix_4);
  tcase_add_test(tc, s21_mult_matrix_5);

  suite_add_tcase(s, tc);
  return s;
}
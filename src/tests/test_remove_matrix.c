#include "s21_tests.h"

START_TEST(s21_remove_matrix_1) {
  matrix_t matrix;
  s21_create_matrix(3, 3, &matrix);
  ck_assert_int_eq(matrix.rows, 3);
  ck_assert_int_eq(matrix.columns, 3);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
}
END_TEST

START_TEST(s21_remove_matrix_2) {
  matrix_t matrix;
  s21_create_matrix(3, -3, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
}
END_TEST

Suite *test_remove_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_REMOVE_MATRIX=-\033[0m");
  TCase *tc = tcase_create("REMOVE_MATRIX");

  tcase_add_test(tc, s21_remove_matrix_1);
  tcase_add_test(tc, s21_remove_matrix_2);

  suite_add_tcase(s, tc);
  return s;
}
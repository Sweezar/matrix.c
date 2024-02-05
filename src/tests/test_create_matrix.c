#include "s21_tests.h"

START_TEST(s21_create_matrix_1) {
  matrix_t matrix;
  int return_value = s21_create_matrix(3, 3, &matrix);

  ck_assert_int_eq(matrix.rows, 3);
  ck_assert_int_eq(matrix.columns, 3);
  ck_assert_int_eq(return_value, 0);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  matrix_t matrix;
  int return_value = s21_create_matrix(-3, 3, &matrix);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  matrix_t matrix;
  int return_value = s21_create_matrix(3, -3, &matrix);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  int return_value = s21_create_matrix(3, 3, NULL);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_create_matrix_5) {
  matrix_t matrix;
  int return_value = s21_create_matrix(13, 3, &matrix);
  ck_assert_int_eq(matrix.rows, 13);
  ck_assert_int_eq(matrix.columns, 3);
  ck_assert_int_eq(return_value, 0);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_6) {
  matrix_t matrix;
  int return_value = s21_create_matrix(3, 13, &matrix);
  ck_assert_int_eq(matrix.rows, 3);
  ck_assert_int_eq(matrix.columns, 13);
  ck_assert_int_eq(return_value, 0);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_7) {
  matrix_t matrix;
  int return_value = s21_create_matrix(1, 1, &matrix);
  ck_assert_int_eq(matrix.rows, 1);
  ck_assert_int_eq(matrix.columns, 1);
  ck_assert_int_eq(return_value, 0);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_8) {
  matrix_t matrix;
  int return_value = s21_create_matrix(0, 0, &matrix);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
  ck_assert_int_eq(return_value, 1);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_9) {
  int return_value = s21_create_matrix(3, 0, NULL);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

Suite *test_create_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_CREATE_MATRIX=-\033[0m");
  TCase *tc = tcase_create("CREATE_MATRIX");

  tcase_add_test(tc, s21_create_matrix_1);
  tcase_add_test(tc, s21_create_matrix_2);
  tcase_add_test(tc, s21_create_matrix_3);
  tcase_add_test(tc, s21_create_matrix_4);
  tcase_add_test(tc, s21_create_matrix_5);
  tcase_add_test(tc, s21_create_matrix_6);
  tcase_add_test(tc, s21_create_matrix_7);
  tcase_add_test(tc, s21_create_matrix_8);
  tcase_add_test(tc, s21_create_matrix_9);
  suite_add_tcase(s, tc);
  return s;
}
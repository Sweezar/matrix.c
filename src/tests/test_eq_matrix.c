#include "s21_tests.h"

START_TEST(s21_eq_matrix_1) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &matrix_2);
  int return_value = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(return_value, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(2, 5, &matrix_1);
  s21_create_matrix(2, 5, &matrix_2);
  int return_value = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(return_value, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(5, 5, &matrix_1);
  s21_create_matrix(2, 5, &matrix_2);
  int return_value = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(return_value, 0);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  matrix_t matrix_1;
  s21_create_matrix(5, 5, &matrix_1);
  int return_value = s21_eq_matrix(&matrix_1, NULL);
  ck_assert_int_eq(return_value, 0);
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(5, 5, &matrix_1);
  s21_create_matrix(5, 5, &matrix_2);
  matrix_2.matrix[0][0] += 1E-6;
  int return_value = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(return_value, 0);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_6) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(5, 5, &matrix_1);
  s21_create_matrix(5, 5, &matrix_2);
  matrix_2.matrix[0][0] += 1E-8;
  int return_value = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(return_value, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

Suite *test_eq_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_EQ_MATRIX=-\033[0m");
  TCase *tc = tcase_create("EQ_MATRIX");

  tcase_add_test(tc, s21_eq_matrix_1);
  tcase_add_test(tc, s21_eq_matrix_2);
  tcase_add_test(tc, s21_eq_matrix_3);
  tcase_add_test(tc, s21_eq_matrix_4);
  tcase_add_test(tc, s21_eq_matrix_5);
  tcase_add_test(tc, s21_eq_matrix_6);

  suite_add_tcase(s, tc);
  return s;
}
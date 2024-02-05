#include "s21_tests.h"

START_TEST(s21_transpose_1) {
  matrix_t matrix_1;
  matrix_t result;
  matrix_t expected_result;
  s21_create_matrix(4, 3, &matrix_1);
  s21_create_matrix(3, 4, &expected_result);

  matrix_1.matrix[0][0] = 127.0;
  matrix_1.matrix[0][1] = 27.0;
  matrix_1.matrix[1][1] = 57.0;

  expected_result.matrix[0][0] = 127.0;
  expected_result.matrix[1][0] = 27.0;
  expected_result.matrix[1][1] = 57.0;

  int return_value = s21_transpose(&matrix_1, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected_result), 1);
  ck_assert_int_eq(return_value, 0);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(s21_transpose_2) {
  matrix_t matrix_1;
  matrix_t result;
  matrix_t expected_result;
  s21_create_matrix(4, 2, &matrix_1);
  s21_create_matrix(2, 4, &expected_result);

  matrix_1.matrix[0][0] = 127.0;
  matrix_1.matrix[0][1] = 27.0;
  matrix_1.matrix[1][1] = 57.0;

  expected_result.matrix[0][0] = 127.0;
  expected_result.matrix[1][0] = 27.0;
  expected_result.matrix[1][1] = 57.0;

  int return_value = s21_transpose(&matrix_1, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected_result), 1);
  ck_assert_int_eq(return_value, 0);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(s21_transpose_3) {
  matrix_t matrix_1;
  matrix_t result;
  matrix_t expected_result;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &expected_result);

  matrix_1.matrix[0][0] = 127.0;
  matrix_1.matrix[0][1] = 27.0;
  matrix_1.matrix[1][1] = 57.0;

  expected_result.matrix[0][0] = 127.0;
  expected_result.matrix[1][0] = 27.0;
  expected_result.matrix[1][1] = 57.0;

  int return_value = s21_transpose(&matrix_1, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected_result), 1);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(s21_transpose_4) {
  int return_value = s21_transpose(NULL, NULL);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_transpose_5) {
  matrix_t matrix_1;
  s21_create_matrix(3, 3, &matrix_1);
  int return_value = s21_transpose(&matrix_1, NULL);
  ck_assert_int_eq(return_value, 1);
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(s21_transpose_6) {
  matrix_t matrix_1;
  matrix_t result;
  matrix_t expected_result;
  s21_create_matrix(5, 3, &matrix_1);
  s21_create_matrix(3, 5, &expected_result);

  matrix_1.matrix[0][0] = 127.0;
  matrix_1.matrix[0][1] = 27.0;
  matrix_1.matrix[1][1] = 57.0;
  matrix_1.matrix[1][0] = 67.0;
  matrix_1.matrix[1][2] = 37.0;
  matrix_1.matrix[2][2] = 7.0;

  expected_result.matrix[0][0] = 127.0;
  expected_result.matrix[1][0] = 27.0;
  expected_result.matrix[1][1] = 57.0;
  expected_result.matrix[0][1] = 67.0;
  expected_result.matrix[2][1] = 37.0;
  expected_result.matrix[2][2] = 7.0;

  int return_value = s21_transpose(&matrix_1, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected_result), 1);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(s21_transpose_7) {
  matrix_t matrix_1;
  matrix_t result;
  s21_create_matrix(-3, -3, &matrix_1);
  int return_value = s21_transpose(&matrix_1, &result);
  ck_assert_int_eq(return_value, 1);
  s21_remove_matrix(&matrix_1);
}
END_TEST

Suite *test_transpose(void) {
  Suite *s = suite_create("\033[45m-=S21_TRANSPOSE=-\033[0m");
  TCase *tc = tcase_create("TRANSPOSE");

  tcase_add_test(tc, s21_transpose_1);
  tcase_add_test(tc, s21_transpose_2);
  tcase_add_test(tc, s21_transpose_3);
  tcase_add_test(tc, s21_transpose_4);
  tcase_add_test(tc, s21_transpose_5);
  tcase_add_test(tc, s21_transpose_6);
  tcase_add_test(tc, s21_transpose_7);

  suite_add_tcase(s, tc);
  return s;
}
#include "s21_tests.h"

START_TEST(s21_inverse_matrix_1) {
  matrix_t matrix_1;
  matrix_t result;
  matrix_t expected_result;

  s21_create_matrix(3, 3, &matrix_1);
  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[0][1] = 5;
  matrix_1.matrix[0][2] = 7;
  matrix_1.matrix[1][0] = 6;
  matrix_1.matrix[1][1] = 3;
  matrix_1.matrix[1][2] = 4;
  matrix_1.matrix[2][0] = 5;
  matrix_1.matrix[2][1] = -2;
  matrix_1.matrix[2][2] = -3;

  s21_create_matrix(3, 3, &expected_result);
  expected_result.matrix[0][0] = 1;
  expected_result.matrix[0][1] = -1;
  expected_result.matrix[0][2] = 1;
  expected_result.matrix[1][0] = -38;
  expected_result.matrix[1][1] = 41;
  expected_result.matrix[1][2] = -34;
  expected_result.matrix[2][0] = 27;
  expected_result.matrix[2][1] = -29;
  expected_result.matrix[2][2] = 24;

  int return_code = s21_inverse_matrix(&matrix_1, &result);
  ck_assert_int_eq(return_code, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected_result), 1);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  matrix_t matrix_1;
  matrix_t result;

  s21_create_matrix(3, 3, &matrix_1);
  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[0][2] = 3;
  matrix_1.matrix[1][0] = 4;
  matrix_1.matrix[1][1] = 5;
  matrix_1.matrix[1][2] = 6;
  matrix_1.matrix[2][0] = 7;
  matrix_1.matrix[2][1] = 8;
  matrix_1.matrix[2][2] = 9;

  int return_code = s21_inverse_matrix(&matrix_1, &result);
  ck_assert_int_eq(return_code, 2);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  matrix_t matrix_1;
  matrix_t result;

  s21_create_matrix(3, 4, &matrix_1);
  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[0][2] = 3;
  matrix_1.matrix[1][0] = 4;
  matrix_1.matrix[1][1] = 5;
  matrix_1.matrix[1][2] = 6;
  matrix_1.matrix[2][0] = 7;
  matrix_1.matrix[2][1] = 8;
  matrix_1.matrix[2][2] = 9;

  int return_code = s21_inverse_matrix(&matrix_1, &result);
  ck_assert_int_eq(return_code, 2);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(s21_inverse_matrix_4) {
  matrix_t matrix_1;

  s21_create_matrix(4, 4, &matrix_1);
  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[0][2] = 3;
  matrix_1.matrix[1][0] = 4;
  matrix_1.matrix[1][1] = 5;
  matrix_1.matrix[1][2] = 6;
  matrix_1.matrix[2][0] = 7;
  matrix_1.matrix[2][1] = 8;
  matrix_1.matrix[2][2] = 9;

  int return_code = s21_inverse_matrix(&matrix_1, NULL);
  ck_assert_int_eq(return_code, 1);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(s21_inverse_matrix_5) {
  matrix_t matrix_1;
  matrix_t result;

  s21_create_matrix(-5, -5, &matrix_1);

  int return_code = s21_inverse_matrix(&matrix_1, &result);
  ck_assert_int_eq(return_code, 1);

  s21_remove_matrix(&matrix_1);
}
END_TEST

Suite *test_inverse_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_INVERSE_MATRIX=-\033[0m");
  TCase *tc = tcase_create("INVERSE_MATRIX");

  tcase_add_test(tc, s21_inverse_matrix_1);
  tcase_add_test(tc, s21_inverse_matrix_2);
  tcase_add_test(tc, s21_inverse_matrix_3);
  tcase_add_test(tc, s21_inverse_matrix_4);
  tcase_add_test(tc, s21_inverse_matrix_5);

  suite_add_tcase(s, tc);
  return s;
}
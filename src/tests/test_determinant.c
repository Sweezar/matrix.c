#include "s21_tests.h"

START_TEST(s21_determinant_1) {
  matrix_t matrix_1;
  double result = 0;
  double expected_result = -2;

  s21_create_matrix(3, 3, &matrix_1);

  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[0][2] = 2;
  matrix_1.matrix[1][0] = 3;
  matrix_1.matrix[1][1] = 4;
  matrix_1.matrix[1][2] = 5;
  matrix_1.matrix[2][0] = 6;
  matrix_1.matrix[2][1] = 7;
  matrix_1.matrix[2][2] = 7;

  int return_value = s21_determinant(&matrix_1, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_double_eq(result, expected_result);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(s21_determinant_2) {
  matrix_t matrix_1;
  double result = 0;
  double expected_result = 20;

  s21_create_matrix(4, 4, &matrix_1);

  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[0][2] = 2;
  matrix_1.matrix[0][3] = 2;
  matrix_1.matrix[1][0] = 3;
  matrix_1.matrix[1][1] = 4;
  matrix_1.matrix[1][2] = 5;
  matrix_1.matrix[1][3] = 5;
  matrix_1.matrix[2][0] = 6;
  matrix_1.matrix[2][1] = 7;
  matrix_1.matrix[2][2] = 7;
  matrix_1.matrix[2][3] = 7;
  matrix_1.matrix[3][0] = -6;
  matrix_1.matrix[3][1] = -7;
  matrix_1.matrix[3][2] = -7;
  matrix_1.matrix[3][3] = -17;

  int return_value = s21_determinant(&matrix_1, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_double_eq(result, expected_result);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(s21_determinant_3) {
  matrix_t matrix_1;
  double result = 0;
  double expected_result = 60;

  s21_create_matrix(5, 5, &matrix_1);

  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[0][2] = 2;
  matrix_1.matrix[0][3] = 2;
  matrix_1.matrix[0][4] = 2;
  matrix_1.matrix[1][0] = 3;
  matrix_1.matrix[1][1] = 4;
  matrix_1.matrix[1][2] = 5;
  matrix_1.matrix[1][3] = 5;
  matrix_1.matrix[1][4] = 5;
  matrix_1.matrix[2][0] = 6;
  matrix_1.matrix[2][1] = 7;
  matrix_1.matrix[2][2] = 7;
  matrix_1.matrix[2][3] = 7;
  matrix_1.matrix[2][4] = 7;
  matrix_1.matrix[3][0] = -6;
  matrix_1.matrix[3][1] = -7;
  matrix_1.matrix[3][2] = -7;
  matrix_1.matrix[3][3] = -17;
  matrix_1.matrix[3][4] = -17;
  matrix_1.matrix[4][0] = -2;
  matrix_1.matrix[4][1] = -3;
  matrix_1.matrix[4][2] = -3;
  matrix_1.matrix[4][3] = -13;
  matrix_1.matrix[4][4] = -10;

  int return_value = s21_determinant(&matrix_1, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_double_eq(result, expected_result);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(s21_determinant_4) {
  matrix_t matrix_1;
  double result = 0;
  s21_create_matrix(-3, 3, &matrix_1);

  int return_value = s21_determinant(&matrix_1, &result);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_determinant_5) {
  matrix_t matrix_1;

  s21_create_matrix(3, 3, &matrix_1);

  int return_value = s21_determinant(&matrix_1, NULL);
  ck_assert_int_eq(return_value, 1);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(s21_determinant_6) {
  double result = 0;
  matrix_t matrix_1;

  s21_create_matrix(2, 3, &matrix_1);

  int return_value = s21_determinant(&matrix_1, &result);
  ck_assert_int_eq(return_value, 2);

  s21_remove_matrix(&matrix_1);
}
END_TEST

Suite *test_determinant(void) {
  Suite *s = suite_create("\033[45m-=S21_DETERMINANT=-\033[0m");
  TCase *tc = tcase_create("DETERMINANT");

  tcase_add_test(tc, s21_determinant_1);
  tcase_add_test(tc, s21_determinant_2);
  tcase_add_test(tc, s21_determinant_3);
  tcase_add_test(tc, s21_determinant_4);
  tcase_add_test(tc, s21_determinant_5);
  tcase_add_test(tc, s21_determinant_6);

  suite_add_tcase(s, tc);
  return s;
}
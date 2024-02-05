#ifndef S21_UTILS_H
#define S21_UTILS_H
#include "s21_matrix.h"

int ptr_is_null(matrix_t *A);
int negative_size(int rows, int columns);
int is_square_matrix(matrix_t *A);

void s21_print_matrix(matrix_t A);
int s21_sum_or_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result, int sign);
void s21_get_minor(int row, int column, matrix_t *A, matrix_t *result);
int s21_get_matrix_of_minors(matrix_t *A, matrix_t *result);

#endif
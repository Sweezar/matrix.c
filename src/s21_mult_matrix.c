#include "s21_matrix.h"

/**
 * Умножение матриц.
 * Произведением матрицы A = m × k на матрицу B = k × n называется матрица C = m
 * × n = A × B размера m × n, элементы которой определяются равенством C(i,j) =
 * A(i,1) × B(1,j) + A(i,2) × B(2,j) + … + A(i,k) × B(k,j).
 * @param A указатель на первую матрицу
 * @param B число
 * @param result указатель на результирующую матрицу
 * @return 0 - OK
 * 1 - Ошибка, некорректная матрица
 * 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
 * нельзя провести вычисления и т.д.)
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (ptr_is_null(A) || ptr_is_null(B) || ptr_is_null(result)) {
    return 1;
  }
  if (A->matrix == NULL || B->matrix == NULL ||
      negative_size(A->rows, A->columns) ||
      negative_size(B->rows, B->columns)) {
    return 1;
  }
  if (A->columns != B->rows) {
    return 2;
  }

  int return_code = s21_create_matrix(A->rows, A->columns, result);
  if (0 == return_code) {
    for (int i = 0; i < A->rows; i++) {
      for (int ii = 0; ii < B->columns; ii++) {
        result->matrix[i][ii] = 0;
        for (int iii = 0; iii < A->columns; iii++) {
          result->matrix[i][ii] += A->matrix[i][iii] * B->matrix[iii][ii];
        }
      }
    }
  }

  return return_code;
}
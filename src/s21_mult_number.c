#include "s21_matrix.h"

/**
 * Умножение матрицы на число.
 * Произведением матрицы A = m × n на число λ называется матрица B = m × n = λ ×
 * A, элементы которой определяются равенствами B = λ × A(i,j).
 * @param A указатель на матрицу
 * @param number число
 * @param result указатель на результирующую матрицу
 * @return 0 - OK
 * 1 - Ошибка, некорректная матрица
 * 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
 * нельзя провести вычисления и т.д.)
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (ptr_is_null(A) || ptr_is_null(result)) {
    return 1;
  }
  if (A->matrix == NULL || negative_size(A->rows, A->columns)) {
    return 1;
  }

  int return_code = s21_create_matrix(A->rows, A->columns, result);
  if (0 == return_code) {
    for (int i = 0; i < A->rows; i++) {
      for (int ii = 0; ii < A->columns; ii++) {
        result->matrix[i][ii] = A->matrix[i][ii] * number;
      }
    }
  }

  return return_code;
}
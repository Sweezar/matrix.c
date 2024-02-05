#include "s21_matrix.h"

/**
 * Вычисление определителя матрицы.
 * @param A указатель на матрицу
 * @param result указатель на результирующую матрицу
 * @return 0 - OK
 * 1 - Ошибка, некорректная матрица
 * 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
 * нельзя провести вычисления и т.д.)
 */
int s21_determinant(matrix_t *A, double *result) {
  if (ptr_is_null(A) || result == NULL) {
    return 1;
  }
  if (negative_size(A->rows, A->columns)) {
    return 1;
  }
  if (A->rows != A->columns) {
    return 2;
  }
  double tmp_result = 0;
  matrix_t minor_matrix;

  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else {
    for (int i = 0; i < A->rows; i++) {
      tmp_result = 0;
      s21_get_minor(i, 0, A, &minor_matrix);
      s21_determinant(&minor_matrix, &tmp_result);

      if (i % 2) {
        *result -= A->matrix[i][0] * tmp_result;
      } else {
        *result += A->matrix[i][0] * tmp_result;
      }

      s21_remove_matrix(&minor_matrix);
    }
  }

  return 0;
}

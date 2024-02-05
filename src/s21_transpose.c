#include "s21_matrix.h"

/**
 * Транспонирование матрицы.
 * Транспонирование матрицы А заключается в замене строк этой матрицы ее
 * столбцами с сохранением их номеров.
 * @param A указатель на матрицу
 * @param result указатель на результирующую матрицу
 * @return 0 - OK
 * 1 - Ошибка, некорректная матрица
 * 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
 * нельзя провести вычисления и т.д.)
 */
int s21_transpose(matrix_t *A, matrix_t *result) {
  if (ptr_is_null(A) || ptr_is_null(result)) {
    return 1;
  }
  if (A->matrix == NULL || negative_size(A->rows, A->columns)) {
    return 1;
  }
  int return_code = s21_create_matrix(A->columns, A->rows, result);
  if (0 == return_code) {
    for (int i = 0; i < A->rows; i++) {
      for (int ii = 0; ii < A->columns; ii++) {
        result->matrix[ii][i] = A->matrix[i][ii];
      }
    }
  }

  return return_code;
}

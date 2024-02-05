#include "s21_matrix.h"

/**
 * Очистка матриц
 * @param A указатель на матрицу
 * @return 0 - OK
 * 1 - Ошибка, некорректная матрица
 * 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
 * нельзя провести вычисления и т.д.)
 */
void s21_remove_matrix(matrix_t *A) {
  if (!ptr_is_null(A) && A->matrix) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) {
        free(A->matrix[i]);
      }
    }
    free(A->matrix);
    if (A != NULL) {
      A->matrix = NULL;
    }
    A->rows = 0;
    A->columns = 0;
  }
}
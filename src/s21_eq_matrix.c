#include "s21_matrix.h"

/**
 * Сравнение матриц
 * @param A указатель на первую матрицу
 * @param B указатель на вторую матрицу
 * @return 0 - матрицы не равны
 * 1 - матрицы равны
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int return_code = SUCCESS;
  if (ptr_is_null(A) || ptr_is_null(B)) {
    return_code = FAILURE;
  } else if (A->rows != B->rows || A->columns != B->columns ||
             A->matrix == NULL || B->matrix == NULL ||
             negative_size(A->rows, A->columns) ||
             negative_size(B->rows, B->columns)) {
    return_code = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int ii = 0; ii < A->columns; ii++) {
        if (fabs(A->matrix[i][ii] - B->matrix[i][ii]) > ACCURACY) {
          return_code = FAILURE;
          i = A->rows;
          ii = A->columns;
        }
      }
    }
  }

  return return_code;
}

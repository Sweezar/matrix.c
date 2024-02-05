#include "s21_matrix.h"
#include "s21_utils.h"

/**
 * Вычисление матрицы алгебраических дополнений.
 * Алгебраическим дополнением элемента матрицы является значение минора
 * умноженное на -1^(i+j).
 * @param A указатель на матрицу
 * @param result указатель на результирующую матрицу
 * @return 0 - OK
 * 1 - Ошибка, некорректная матрица
 * 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
 * нельзя провести вычисления и т.д.)
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (ptr_is_null(A) || ptr_is_null(result)) {
    return 1;
  }
  if (negative_size(A->rows, A->columns)) {
    return 1;
  }
  if (!is_square_matrix(A)) {
    return 2;
  }

  int return_code = s21_get_matrix_of_minors(A, result);
  if (0 == return_code) {
    for (int i = 0; i < A->rows; i++) {
      for (int ii = 0; ii < A->columns; ii++) {
        if (result->matrix[i][ii] != 0.0) {
          result->matrix[i][ii] *= pow(-1, i + ii);
        }
      }
    }
  }

  return 0;
}
#include "s21_matrix.h"

/**
 * Обратная матрица .
 * Матрицу A в степени -1 называют обратной к квадратной матрице А, если
 * произведение этих матриц равняется единичной матрице. Обратной матрицы не
 * существует, если определитель равен 0.
 * @param A указатель на матрицу
 * @param result указатель на результирующую матрицу
 * @return 0 - OK
 * 1 - Ошибка, некорректная матрица
 * 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
 * нельзя провести вычисления и т.д.)
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (ptr_is_null(A) || ptr_is_null(result)) {
    return 1;
  }
  if (negative_size(A->rows, A->columns)) {
    return 1;
  }
  if (!is_square_matrix(A)) {
    return 2;
  }
  int return_code = 0;
  double determinant = 0;
  matrix_t complements_matrix;
  matrix_t transpose_complements_matrix;
  s21_determinant(A, &determinant);
  if (0 == determinant) {
    return_code = 2;
  } else {
    return_code = s21_calc_complements(A, &complements_matrix);
    if (0 == return_code)
      return_code =
          s21_transpose(&complements_matrix, &transpose_complements_matrix);
    if (0 == return_code)
      return_code = s21_mult_number(&transpose_complements_matrix,
                                    1 / determinant, result);

    s21_remove_matrix(&complements_matrix);
    s21_remove_matrix(&transpose_complements_matrix);
  }

  return return_code;
}
#include "s21_matrix.h"

/**
 * Создание матриц
 * @param rows количество строк матрицы
 * @param columns количество столбцов матрицы
 * @param result указатель на структуру матрицы
 * @return 0 - OK
 * 1 - Ошибка, некорректная матрица
 * 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
 * нельзя провести вычисления и т.д.)
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (ptr_is_null(result)) {
    return 1;
  }
  if (negative_size(rows, columns)) {
    result->rows = 0;
    result->columns = 0;
    result->matrix = NULL;
    return 1;
  }
  int return_code = 0;
  int rows_allocated_counter = 0;
  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix == NULL) return_code = 2;

  if (!return_code) {
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) {
        return_code = 2;
        rows_allocated_counter = i;
      }
    }

    if (return_code) {
      for (int i = 0; i < rows_allocated_counter; i++) {
        free(result->matrix[i]);
      }
    } else {
      result->columns = columns;
      result->rows = rows;
    }
  }

  return return_code;
}
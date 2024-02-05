#include "s21_utils.h"

/**
 * Проверяет указатель на структуру матрицы
 * @param A указатель на структуру
 * @return 1 - указателя нет, 0 - указатель есть.
 */
int ptr_is_null(matrix_t *A) { return A == NULL; }

/**
 * Проверяет строки и столбцы
 * @param rows количество строк
 * @param columns количество столбцов
 * @return 1 - ошибочное количество, 0 - количество приемлемо.
 */
int negative_size(int rows, int columns) { return (0 >= rows || 0 >= columns); }

/**
 * Проверяет, что матрица квадратная
 * @param A указатель на структуру
 * @return 1 - матрица квадратная, 0 - не квадратная.
 */
int is_square_matrix(matrix_t *A) { return (A->rows == A->columns); }

// void s21_print_matrix(matrix_t A) {
// 	for(int i = 0; i < A.rows; i++) {
// 		for(int ii = 0; ii < A.columns; ii++) {
// 			printf("| %5.6lf |", A.matrix[i][ii]);
// 		}
// 		printf("\n");
// 	}
// 	printf("\n");

// }

int s21_sum_or_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result,
                          int sign) {
  if (ptr_is_null(A) || ptr_is_null(B) || ptr_is_null(result)) {
    return 1;
  }
  if (A->matrix == NULL || B->matrix == NULL) {
    return 1;
  }
  if (negative_size(A->rows, A->columns) ||
      negative_size(B->rows, B->columns) || A->rows != B->rows ||
      A->columns != B->columns) {
    return 2;
  }
  int return_code = s21_create_matrix(A->rows, A->columns, result);

  if (0 == return_code) {
    for (int i = 0; i < A->rows; i++) {
      for (int ii = 0; ii < A->columns; ii++) {
        result->matrix[i][ii] = A->matrix[i][ii] + (B->matrix[i][ii] * sign);
      }
    }
  }

  return return_code;
}

/**
 * Возвращает минор матрицы
 * @param row строка для которой вычисляется минор
 * @param column столбец для которого вычисляется минор
 * @param A указатель на матрицу
 * @param result указатель на результирующую матрицу
 */
void s21_get_minor(int row, int column, matrix_t *A, matrix_t *result) {
  if (A->rows > 1) {
    s21_create_matrix(A->rows - 1, A->columns - 1, result);
    for (int i = 0; i < A->rows; i++) {
      for (int ii = 0; ii < A->columns; ii++) {
        if (i < row && ii < column) {
          result->matrix[i][ii] = A->matrix[i][ii];
        } else if (i > row && ii < column) {
          result->matrix[i - 1][ii] = A->matrix[i][ii];
        } else if (i < row && ii > column) {
          result->matrix[i][ii - 1] = A->matrix[i][ii];
        } else if (i > row && ii > column) {
          result->matrix[i - 1][ii - 1] = A->matrix[i][ii];
        }
      }
    }
  }
}

int s21_get_matrix_of_minors(matrix_t *A, matrix_t *result) {
  int return_code = 0;
  matrix_t tmp_matrix;

  return_code = s21_create_matrix(A->rows, A->columns, result);
  if (0 == return_code) {
    for (int i = 0; i < A->rows; i++) {
      for (int ii = 0; ii < A->columns; ii++) {
        s21_get_minor(i, ii, A, &tmp_matrix);
        s21_determinant(&tmp_matrix, &(result->matrix[i][ii]));
        s21_remove_matrix(&tmp_matrix);
      }
    }
  }

  return return_code;
}
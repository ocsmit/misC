#include <stddef.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "util.h"
#include <math.h>

#define getName(var)  #var

#define FALSE 0
#define TRUE 1

typedef struct {
    int  rows;
    int  cols;
    size_t member_size;
    double *data;         
} Array2d;

/**
 * @brief      Allocate mem for Array2d and data matrix 
 *
 * @param[in]  rows  number of rows in matrix
 * @param[in]  cols  number of columns in matrix
 *
 * @return     Pointer to Array2d struct
 */
Array2d *Array2d_malloc(int rows, int cols) {

	// Allocate all the memory needed for the struct plus the 2d array
	Array2d *array = (Array2d*) malloc(sizeof(Array2d));
	assert(array != NULL);

	// Possible to alloc memory for array in the struct malloc?
	double *mat = (double*) malloc(sizeof(double[cols][rows]));
	assert(mat != NULL);

	array->rows = rows;
	array->cols = cols;
	array->data = mat;
	array->member_size = sizeof(double);

	return array;
}

/**
 * @brief     Free memory of Array2d struct and data 
 *
 * @param      array  pointer to Array2d 
 */
void Array2d_free(Array2d *array) {
	// TODO: Add checks
	free(array->data), array->data = NULL;
	free(array);
}


Array2d *Array2d_copy(Array2d *array) {
	return Array2d_malloc(array->rows, array->cols);
}

/**
 * @brief     Get matrix value at (row, col) 
 *
 * @param      array  pointer to Array2d 
 * @param[in]  row    The row
 * @param[in]  col    The col
 *
 * @return     returns either value at (row, col), or NAN
 */
double Array2d_get(Array2d *array, int row, int col){
	if(row < array->rows && col < array->cols) {
		return array->data[row * array->cols + col];
	}
	else {
		return NAN;
	}
}

/**
 * @brief      Assign value to array at (row, col)
 *
 * @param      array  pointer to Array2d 
 * @param[in]  row    row of cell
 * @param[in]  col    column of cell
 * @param[in]  value  value to assign
 */
void Array2d_assign(Array2d *array, int row, int col, double value){
	if(row < array->rows && col < array->cols) {
		array->data[row * array->cols + col] = value;
	} else {
	}
}


/**
 * @brief      Prints out values of array 
 *
 * @param      array  pointer to Array2d 
 */
void Array2d_print(Array2d* array){
	int i, j;

	printf("\n ARRAY (%d x %d) \n --- \n", 
		(int) array->rows, (int) array->cols);
	for(i = 0; i < array->rows; i++){
		for(j = 0; j < array->cols; j++){
			printf(" %.2f\t", Array2d_get(array, i, j));
		}
		printf("\n");
	}
}

/**
 * @brief      Compares the axis size of two arrays
 *
 * @param      arr_a  Array2d a
 * @param      arr_b  Array2d b
 * @param[in]  axis   Axis to compare, 0 = row, 1 = col, ...
 *
 * @return     Returns 1 if axis size is the same, 0 otherwise
 */
int Array2d_compare_axis(Array2d *arr_a, Array2d *arr_b, int axis) {
	switch (axis) {
	case 0:
		if (arr_a->rows == arr_b->rows) return 1;
		break;
	case 1:
		if (arr_a->cols == arr_b->cols) return 1;
		break;
	}
	return 0;
}


int Array2d_same_size(Array2d *arr_a, Array2d *arr_b) {
	if (Array2d_compare_axis(arr_a, arr_b, 0) != 1 ||
		Array2d_compare_axis(arr_a, arr_b, 1) != 1) {
		return FALSE;
	} else {
		return TRUE;
	}
}

Array2d *Array2d_add(Array2d *arr_a, Array2d *arr_b) {
	int rows, cols;

	if (Array2d_same_size(arr_a, arr_b) == FALSE) {
		return 0;
	}

	Array2d *arr_result = Array2d_copy(arr_a);
	rows = arr_result->rows;
	cols = arr_result->cols;

	// Difficulty of SIMD for arm chip?
	// Difficulty of portable SIMD?
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j ++) {
			Array2d_assign(arr_result, i, j, 
				Array2d_get(arr_a, i, j) + Array2d_get(arr_b, i, j));
		}
	}

	return arr_result;
}


Array2d *Array2d_subtract(Array2d *arr_a, Array2d *arr_b) {
	int rows, cols;

	if (Array2d_same_size(arr_a, arr_b) == FALSE) {
		return 0;
	}

	Array2d *arr_result = Array2d_copy(arr_a);
	rows = arr_result->rows;
	cols = arr_result->cols;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j ++) {
			Array2d_assign(arr_result, i, j, 
				Array2d_get(arr_a, i, j) - Array2d_get(arr_b, i, j));
		}
	}

	return arr_result;
}

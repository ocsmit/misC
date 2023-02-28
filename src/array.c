#include <stddef.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "util.h"

#define getName(var)  #var


typedef struct {
    size_t rows;
    size_t cols;
    int member_size;
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
Array2d *Array2d_malloc(size_t rows, size_t cols) {

	Array2d *array = (Array2d*) malloc(sizeof(Array2d));
	// Allocate all the memory needed for the struct plus the 2d array
	array = malloc(sizeof(*array));
	assert(array != NULL);

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
	free(array->data);
	free(array);
};

/**
 * @brief     Get matrix value at (row, col) 
 *
 * @param      array  pointer to Array2d 
 * @param[in]  row    The row
 * @param[in]  col    The col
 *
 * @return     returns either value at (row, col), or 0
 */
double Array2d_get(Array2d *array, int row, int col){
	if(row < array->rows && col < array->cols) {
		//return array->data[col + (row * array->cols)];
		return array->data[row * array->cols + col];
	}
	else {
		// add warning for outof bounds
		return 0;
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
		// add warning for outof bounds
		//log_warn("(%d, %d)\t Out of bounds", row, col);
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

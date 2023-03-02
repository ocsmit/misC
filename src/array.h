#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

typedef struct {
    int rows;               /* Rows in the 2D array */
    int cols;            /* Columns in the 2D array */
    size_t member_size;        /* Size of each entry in the array */
    double *data;         /* Pointer to the data storage for the array */
} Array2d;

Array2d *Array2d_malloc(size_t rows, size_t cols);
void Array2d_free(Array2d *array);
double Array2d_get(Array2d* m, int row, int col);
void Array2d_assign(Array2d* m, int row, int col, double value);
void Array2d_print(Array2d* m);

// Math funcs
Array2d *Array2d_add(Array2d *arr_a, Array2d *arr_b);
Array2d *Array2d_subtract(Array2d *arr_a, Array2d *arr_b);


#endif

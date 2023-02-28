#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>


typedef struct {
    size_t rows;               /* Rows in the 2D array */
    size_t cols;            /* Columns in the 2D array */
    int member_size;        /* Size of each entry in the array */
    double *data;         /* Pointer to the data storage for the array */
} Array2d;

Array2d *Array2d_malloc(size_t rows, size_t cols);

void Array2d_free(Array2d *array);

double Array2d_get(Array2d* m, int row, int col);

void Array2d_assign(Array2d* m, int row, int col, double value);

void Array2d_print(Array2d* m);


#endif
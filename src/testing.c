#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// Local includes
#include "geom.h"
#include "array.h"

int random_int(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}


int main(int argc, char const *argv[])
{
    // Seed and populate array
    srand(42);

    Array2d *array_a = Array2d_malloc(2, 2);
    Array2d *array_b = Array2d_malloc(2, 2);
    Array2d *array_c;
    // If we want to access just the data array
    // we can use -> double *data = array->data;

    for (int i = 0; i < array_a->rows; i++) {
        for (int j = 0; j < array_a->cols; j ++) {
            Array2d_assign(array_a, i, j, random_int(1, 255));
            Array2d_assign(array_b, i, j, random_int(1, 255));
        }

    }

    Array2d_print(array_a);
    Array2d_print(array_b);

    array_c = Array2d_add(array_a, array_b);
    Array2d_print(array_c);

    array_c = Array2d_subtract(array_a, array_b);
    Array2d_print(array_c);

    Array2d_free(array_b)   ;

    return 0;
}


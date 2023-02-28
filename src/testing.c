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

	Array2d *array = Array2d_malloc(10, 10);
	// If we want to access just the data array
	// we can use -> double *data = array->data;

	printf("%f\n", Array2d_get(array, 0, 1));

	for (int i = 0; i < array->rows; i++) {
		for (int j = 0; j < array->cols; j ++) {
			Array2d_assign(array, i, j, random_int(1, 255));
			//printf("idx %lu | i %d | j %d | v %f | p %p\n", 
			// 		i + (j* array->cols), i, j, data[i + (j* array->cols)], &data[i]);
		}

	}

	Array2d_print(array);

	Array2d_free(array)	;

	return 0;
}
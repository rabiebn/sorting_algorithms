#include "sort.h"

/**
 * swap - Swap position of 2 elements in an array.
 *
 * @x: element to swap with @y
 * @y: element to swap with @x
 */
void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
}

/**
 * selection_sort - Selection sort array of ints
 *
 * @array: array of ints to sort;
 * @size: number of elements in @array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i; j < size; j++)
			if (array[min] > array[j])
				min = j;
		swap(&array[min], &array[i]);
		print_array(array, size);
	}
}

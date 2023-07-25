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
 * bubble_sort - Bubble Sort.
 *
 * @array: array of elemnts to sort.
 * @size: number of elements in @array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	if (!array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = true;
				print_array(array, size);
			}
		}
		if (swapped == false)
			break;
	}
}

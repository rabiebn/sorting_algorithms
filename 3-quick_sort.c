#include "sort.h"

/**
 * partition - Selects a pivot and partitions the array.
 *
 * @array: array to partition;
 * @high: highest index in @array;
 * @low: lowest index in @array;
 * @size: number of elements in @array.
 * Return: index of 1st element after pivot.
 */
size_t partition(int **array, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int tmp, pivot;

	pivot = (*array)[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if ((*array)[j] <= pivot)
		{
			i++;
			tmp = (*array)[i];
			(*array)[i] = (*array)[j];
			(*array)[j] = tmp;
			if ((*array)[i] !=  (*array)[j])
				print_array(*array, size);
		}
	}

	tmp =  (*array)[i + 1];
	(*array)[i + 1] = (*array)[high];
	(*array)[high] = tmp;
	if ((*array)[i + 1] !=  (*array)[high])
		print_array(*array, size);
	return (i + 1);
}

/**
 * quick_s - quick sort with more arguments.
 *
 * @array: array to partition;
 * @high: highest index in @array;
 * @low: lowest index in @array;
 * @size: number of @array 's elements.
 */
void quick_s(int **array, size_t low, size_t high, size_t size)
{
	size_t pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		if (pi != 0)
			quick_s(array, low, (pi - 1), size);
		if (pi < size - 1)
			quick_s(array, (pi + 1), high, size);
	}
}

/**
 * quick_sort - Quick sort an array of ints.
 *
 * @array: array of ints to sort;
 * @size: number of elements in @array.
 */
void quick_sort(int *array, size_t size)
{
	if (size > 1)
		quick_s(&array, 0, (size - 1), size);
}

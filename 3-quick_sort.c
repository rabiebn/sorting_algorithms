#include "sort.h"

/**
 * partition - Desc
 *
 * @high: 
 * @low:
 * Return: 
*/
size_t partition(int *array, size_t high, size_t low)
{
    size_t i = low - 1, j;
    int pivot = array[high];

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    return (i + 1);
}

// define another quick sort function that takes array, high and low as args.

/**
 * quick_sort - Quick sort an array of ints.
 * 
 * @array: array of ints to sort;
 * @size: number of elements in @array.
*/
void quick_sort(int *array, size_t size)
{
    size_t pivot = partition(array, size - 1, 0);

}
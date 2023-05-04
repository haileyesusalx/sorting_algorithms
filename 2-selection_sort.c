#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_ints - swaps two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 *
 * Return: void
 */
static void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sorts an array of integers in ascending order using the
 *                  Selection sort algorithm
 * @array: pointer to the array of integers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t j, k;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		min = array + j;
		for (k = j + 1; k < size; k++)
			min = (array[k] < *min) ? (array + k) : min;

		if ((array + j) != min)
		{
			swap_ints(array + j, min);
			print_array(array, size);
		}
	}
}


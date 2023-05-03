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
 * bubble_sort - sorts an array of integers in ascending order using the
 *               bubble sort algorithm
 * @array: the array of integers to be sorted
 * @size: the size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int swapped;

	if (array == NULL || size < 2)
		return;
	do {
		swapped = 0;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				swapped = 1;
				print_array(array, size);
			}
		}
		len--;
	} while (swapped);
}

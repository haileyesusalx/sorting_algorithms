#include "sort.h"
void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - swaps two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 *
 * Return: void
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - sorts an array of integers in ascending order using the
 *                  Selection sort algorithm
 * @array: pointer to the array of integers
 * @size: size of the array
 * @left: the size of the array
 * @right: thesize of the array
 * Return:The final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *driver, up, down;

	driver = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *driver)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *driver)
	{
		swap_ints(array + up, driver);
		print_array(array, size);
	}
	return (up);
}


/**
 * lomuto_sort - sorts an array of integers in ascending order using the
 *                  Selection sort algorithm
 * @array: pointer to the array of integers
 * @size: size of the array
 * @left: the size of the array
 * @right: thesize of the array
 * Return:The final partition index
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, belong - 1);
		lomuto_sort(array, size, belong + 1, right);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * @array: pointer to the array of integers
 * @size: size of the array
 * Return: The final partition index
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <  2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
**
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
void counting_sort(int *array, size_t size)
{
    int i, j, max = 0;
    int *count, *output;

    for (i = 0; i < (int)size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    count = malloc(sizeof(int) * (max + 1));
    if (count == NULL)
        return;

    output = malloc(sizeof(int) * size);
    if (output == NULL) {
        free(count);
        return;
    }

    for (i = 0; i <= max; i++)
        count[i] = 0;

    for (i = 0; i < (int)size; i++)
        count[array[i]]++;

    printf("%d", count[0]);
    for (i = 1; i <= max; i++)
        printf(", %d", count[i]);
    printf("\n");

    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (i = (int)size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = output[i];

    free(count);
    free(output);
}

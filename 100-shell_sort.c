#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int hlder;

	hlder = *a;
	*a = *b;
	*b = hlder;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Use Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t g, i, j;

	if (array == NULL || size < 2)
		return;

	for (g = 1; g < (size / 3);)
		g = g * 3 + 1;

	for (; g >= 1; g /= 3)
	{
		for (i = g; i < size; i++)
		{
			j = i;
			while (j >= g && array[j - g] > array[j])
			{
				swap_ints(array + j, array + (j - g));
				j -= g;
			}
		}
		print_array(array, size);
	}
}

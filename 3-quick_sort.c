#include "sort.h"

void swap_ints(int *a, int *b);
int lomutopartition(int *array, size_t size, int left, int right);
void lomutosort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomutopartition - Order a subset of an array of integers according to
 *                    the lomuto partition (last element as pivot).
 * @array: Array of integers.
 * @size: Size of the array.
 * @left: Starting index of the subset to order.
 * @right: Ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomutopartition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomutosort - Implements a quicksort algorithm using recursion.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @left: Starting index of the array partition to order.
 * @right: Ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomutosort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomutopartition(array, size, left, right);
		lomutosort(array, size, left, part - 1);
		lomutosort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quicksort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomutosort(array, size, 0, size - 1);
}

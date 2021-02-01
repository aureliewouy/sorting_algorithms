#include "sort.h"
/**
 * swap - function that swap two number)
 * @x: the first number
 * @y: the secund number
 *
 * Return: Nothing
 */
void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
}
/**
 * partition - partitions the array
 * @a: the array
 * @start: the start of the array the lower
 * @end: the end of the array
 * @size: size of the array
 *
 * Return: the pivot index
 */

int partition(int *a, int start, int end, size_t size)
{
	int pivot, pindex, i;

	pivot = a[end];
	pindex = start;
	for (i = start; i < end; i++)
	{
		if (a[i] <= pivot)
		{
			if (pindex != i)
			{
				swap(&a[i], &a[pindex]);
				print_array(a, size);
			}
			pindex++;
		}

	}
	if (pindex != i)
	{
		swap(&a[pindex], &a[end]);
		print_array(a, size);
	}
	return (pindex);
}
/**
 * quick_help - helps to index the be partition
 * @array: the array
 * @start: the lower
 * @end: the higher
 * @size: the size of the array
 *
 * Return: Nothing
 */

void quick_help(int *array, int start, int end, size_t size)
{
	int pivot_index;

	if (start >= end)
		return;
	pivot_index = partition(array, start, end, size);
	quick_help(array, start, pivot_index - 1, size);
	quick_help(array, pivot_index + 1, end, size);

}



/**
 * quick_sort - Implement the Quick sort algorithm
 * @array: the array of integers
 * @size: the size of the array
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{

	quick_help(array, 0, size - 1, size);
}

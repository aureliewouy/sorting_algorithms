#include "sort.h"

void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
}

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
	return pindex;
}


void quick(int *array, int start, int end, size_t size)
{
	int pivot_index;

	if (start >= end)
		return;
	pivot_index = partition(array, start, end, size);
	quick(array, start, pivot_index - 1, size);
	quick(array, pivot_index + 1, end, size);

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

	quick(array, 0, size - 1, size);
}

#include "sort.h"
/**
 * selection_sort - Functions that sort array with the Selection sort algorithm
 * @array: the array of integers
 * @size: the size of the array
 *
 * Return: Nothing.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx, tmp;

	if ((array != NULL) && (size >= 2))
	{
		for (i = 0; i < size - 1; i++)
		{
			min_idx = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[min_idx])
					min_idx = j;
			}
			if (min_idx != i)
			{
				tmp = array[min_idx];
				array[min_idx] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
		}
	}

}

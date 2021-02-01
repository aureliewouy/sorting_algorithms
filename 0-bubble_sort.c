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
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: the array
 * @size: the size of the array
 *
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if ((array != NULL) && (size >= 2))
	{
		for (i = 0; i < size - 1; i++)
		{
			for (j = 0; j < size - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					swap(&array[j], &array[j + 1]);
					print_array(array, size);
				}
			}
		}
	}
}

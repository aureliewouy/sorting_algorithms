#include "sort.h"
/**
 * counting_sort - Sorts an array using the Counting sort algorithm
 * @array: the array
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *count = NULL;
	int *new = NULL;
	size_t max = 0;

	if (array == NULL || size < 2)
		return;
	count = malloc(sizeof(int) * size);
	if (count == NULL)
		return;
	/* Search for the maximum number in the array*/
	for (i = 0; i < size; i++)
	{
		count[i] = array[i];
		if (array[i] > (int)max)
			max = array[i];
	}
	new = malloc(sizeof(int) * (max + 1));
	if (new == NULL)
		return;
	/*Initialize count array with all zeros.*/
	for (i = 0; i <= max; ++i)
		count[i] = 0;
	/*Store count of each character */
	for (i = 0; i < size; i++)
		count[array[i]]++;
	/*count[i] now contains actual position of this char in output array*/
	for (i = 1; i <= max; ++i)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	/*Build the output character array*/
	for (i = 0; i < size; i++)
	{
		new[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; array[i]; i++)
	{/*Copy the output ar to ar, ar now contains sorted characters*/
		array[i] = new[i];
	}
}

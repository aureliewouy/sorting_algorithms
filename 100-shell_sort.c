#include "sort.h"
/**
 * shell_sort - sorts an array using the Shell sort algorithm
 * using the Knuth sequence
 * @array: the array
 * @size: the size of the array
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1;
	size_t outer, inner;
	int valueToInsert;

	if (array != NULL && size >= 1)
	{
		/* Calculate interval*/
		while (interval < (size / 3))
			interval = interval * 3 + 1;
		while (interval > 0)
		{
			for (outer = interval; outer < size; outer++)
			{
				/*Select value to be inserted*/
				valueToInsert = array[outer];
				inner = outer;
				/*shift element towards right*/
				while (inner > interval - 1 && array[inner - interval] >=
						valueToInsert)
				{
					array[inner] = array[inner - interval];
					inner = inner - interval;
				}
				array[inner] = valueToInsert;
			}
			/*calculate interval*/
			interval = (interval - 1) / 3;
			print_array(array, size);
		}
	}
}

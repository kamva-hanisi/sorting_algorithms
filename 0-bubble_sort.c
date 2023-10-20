#include "sort.h"

/**
* bubble_sort - Bubble algorithm to sort an array
* @array: array to be sorted
* @size: size of the array
* Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped = 0;

	for (i = 0; i < size; i++)
	{
		swapped = 0;

		for (j = 0; j + 1 + i < size; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}

		if (swapped == 0)
			break;
	}
}

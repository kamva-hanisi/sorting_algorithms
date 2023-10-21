#include "sort.h" 
/**
 * swap - Swap values of start and next index
 * @a: array to be sorted
 * @b: size of the array
 * Return: void
*/

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * partition - Using Lomuto partition scheme for quicksort
 * @array: array to be sorted
 * @low: left most value
 * @high: right most value
 * @size: size of the array
 * Return: i + 1
 */

int partition(int *array, int low, int high, int size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{

			i++;

			if (array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}

	}

	if (array[i + 1] != array[high])
	{
		temp = array[i+ 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * recursive_quick_sort - Sorts an array of integers in ascending order
 * @array: array to be sorted
 * @low: left most value
 * @high: right most value
 * @size: size of the array
 * Return: void
 */

void recursive_quick_sort(int *array, int low, int high, int size)

{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		recursive_quick_sort(array, low, pi - 1, size);
		recursive_quick_sort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted.
 * @size: The number of elements in the array
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_quick_sort(array, 0, size - 1, size);
}

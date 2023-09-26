#include "sort.h"

/**
 * counting_sort - fuction name
 * @array: array to be sorted
 * @size: size of array
 */

void counting_sort(int *array, size_t size)
{
	int max = array[0], *count, *output;
	size_t i, range, k;

	if (array == NULL || size <= 1)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	range = max + i;
	count = malloc(sizeof(int) * range);
	if (count == NULL)
		return;
	for (k = 0; k < range; k++)
		count[k] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i < range; i++)
		count[i] += count[i - 1];
	print_array(count, range);
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (i = size - 1; i != SIZE_MAX; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
	free(count);
}

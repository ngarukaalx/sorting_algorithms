#include "sort.h"

/**
 * swap - swap intergers
 * @y: first interger
 * @x: second interger
 */

void swap(int *y, int *x)
{
	int temp;

	temp = *y;
	*y = *x;
	*x = temp;
}
/**
 * selection_sort - fuction for selection sort
 * @array: pointer to array
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	unsigned long int i, j, min_num;

	if (size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		min_num = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_num])
			{
				min_num = j;
			}
		}
		if (min_num != i)
		{
			swap(&array[min_num], &array[i]);
			print_array(array, size);
		}
	}
}


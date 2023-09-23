#include "sort.h"

/**
 * swap - swap intergers
 * @x: pointer to fisrt interger
 * @y: poinyrt to second interger
 */

void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;

	*y = temp;
}

/**
 * bubble_sort - name of the fuction
 * @array: array to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	unsigned long int i, j;

	int swapped;

	if (size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		swapped = 1;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 0;
				print_array(array, size);
			}
		}
		if (swapped == 1)
		{
			break;
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "sort.h"

/**
 * swap - fuction name
 * @x: parameter to swap
 * @y: parameter to swap
 */

void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

/**
 * lomuto_partition - fuction name
 * @array: array to be partition
 * @low: first index
 * @size: size of array
 * @high: last index
 * Return: pivot
 */

int lomuto_partition(int array[], int low, int high, size_t size)
{
	int j, i, pivot;

	pivot = array[high];

	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}

	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * sort - fuction name
 * @array: array to sort
 * @low: index 0 of array
 * @size: size of array
 * @high: last index of array
 */

void sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);

		sort(array, low, pivot - 1, size);
		sort(array, pivot + 1, high, size);
	}

}

/**
 * quick_sort - fuction name
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	int low = 0;

	int high = size - 1;

	if (array == NULL || size < 2)
		return;

	sort(array, low, high, size);
}

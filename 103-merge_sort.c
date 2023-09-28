#include "sort.h"

/**
 * cont_merge - fuction name
 * @array: to merge
 * @left: first index
 * @mid: pivot index
 * @right: last index
 * @temp: pointer to allocated memory
 */

void cont_merge(int *array, int left, int mid, int right, int *temp)
{
	int i, j, k, *l, *r, left_size = mid - left + 1, right_size = right - mid;

	l = temp, r = temp + left_size;
	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < left_size; i++)
		l[i] = array[left + i];
	print_array(l, left_size);
	printf("[right]: ");
	for (j = 0; j < right_size; j++)
		r[j] = array[mid + 1 + j];
	print_array(r, right_size);
	i = 0, j = 0, k = left;
	while (i < left_size && j < right_size)
	{
		if (l[i] <= r[j])
		{
			array[k] = l[i];
			i++;
		}
		else
		{
			array[k] = r[j];
			j++;
		}
		k++;
	}
	while (i < left_size)
	{
		array[k] = l[i];
		i++;
		k++;
	}
	while (j < right_size)
	{
		array[k] = r[j];
		j++;
		k++;
	}
	printf("[Done]: ");
}

/**
 * merge - fuction name
 * @array: array to merge
 * @left: first index
 * @mid: middle
 * @right: last index
 */

void merge(int *array, int left, int mid, int right)
{
	int *temp = malloc(sizeof(int) * (right - left + 1));

	if (temp == NULL)
		return;
	cont_merge(array, left, mid, right, temp);

	print_array(array, right + 1);

	free(temp);

}
/**
 * sort - fuction name
 * @array: array to be sorted
 * @left: first index
 * @right: last index
 */

void sort(int *array, int left, int right)
{
	int middle;

	if (left < right)
	{
		middle = (left + (right - left) / 2);

		sort(array, left, middle);
		sort(array, middle + 1, right);

		merge(array, left, middle, right);
	}
}

/**
 * merge_sort - fuction name
 * @array: array to sort
 * @size: size of array
 */

void merge_sort(int *array, size_t size)
{
	int low = 0;

	int right = size - 1;

	if (array == NULL || size < 2)
		return;
	sort(array, low, right);
}

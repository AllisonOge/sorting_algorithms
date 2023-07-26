#include "sort.h"
#include <stdlib.h>

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp = NULL;

	if (!array || size < 2)
		return;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;
	merge_sort_rec(array, tmp, 0, size - 1);
	free(tmp);
}

/**
 * merge_sort_rec - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array of integers
 * @tmp: temporary array of integers
 * @low: low index
 * @high: high index
 */
void merge_sort_rec(int *array, int *tmp, int low, int high)
{
	int mid = 0;

	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort_rec(array, tmp, low, mid);
		merge_sort_rec(array, tmp, mid + 1, high);
		merge(array, tmp, low, mid, high);
	}
}

/**
 * merge - merges two subarrays of integers
 * @array: array of integers
 * @tmp: temporary array of integers
 * @low: low index
 * @mid: middle index
 * @high: high index
 */
void merge(int *array, int *tmp, int low, int mid, int high)
{
	/*
	 * i tracks left subarray and j tracks right subarray.
	 * k tracks merged subarray. The logic of the merge
	 * subroutine is to use the temporary array to store
	 * the sorted elements of the left and right subarrays
	 * determined by the indices i and j.
	 */
	int i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + low, mid - low + 1);
	printf("[right]: ");
	print_array(array + mid + 1, high - mid);
	/*
	 * interleave the elements of the left and right subarrays
	 * in sorted order into the temporary array using the two
	 * pointer algorithm.
	 */
	for (i = low, j = mid + 1, k = low; k <= high; k++)
	{
		if (i <= mid
			&& (j > high /* first right subarray element not considered */
			|| array[i] <= array[j]))
		{
			tmp[k] = array[i]; /* left subarray element is smaller */
			i++;
		}
		else
		{
			tmp[k] = array[j]; /* right subarray element is smaller */
			j++;
		}
	}
	for (k = low; k <= high; k++) /* copy sorted elements to array */
		array[k] = tmp[k];
	printf("[Done]: ");
	print_array(array + low, high - low + 1);
}

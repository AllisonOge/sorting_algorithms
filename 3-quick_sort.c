#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_rec(array, 0, size - 1, size); /* call recursive function */
}

/**
 * quick_sort_rec - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 * @low: low index
 * @high: high index
*/
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high) /* check if the length of subarrays is more than 1 */
	{
		/*
		 * select a pivot and partition the array into two subarrays
		 * left subarray contains elements less than or equal to the pivot
		 * right subarray contains elements greater than the pivot
		*/
		pivot = partition(array, low, high, size);
		quick_sort_rec(array, low, pivot - 1, size); /* sort left subarray */
		quick_sort_rec(array, pivot + 1, high, size); /* sort right subarray */
	}
}

/**
 * partition - partitions the array
 * @array: array to sort
 * @size: size of the array
 * @low: low index
 * @high: high index
 * Return: index of the pivot
*/
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	/*
	 * i is the index of the last element of the left subarray
	 * j is the index of the first element of the right subarray
	 */
	int i = low - 1, j, tmp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			/*
			 * only swap if the last index of the left subarray
			 * is not equal to the first index of the right subarray
			 */
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high) /* correctly place the pivot */
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

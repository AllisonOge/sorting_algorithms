#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm, using the Knuth sequence
 * @array: array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/*
	 * initialize the gap to the biggest number less than size / 3
	 * in the Knuth sequence
	 */
	while (gap < size / 3)
		gap = gap * 3 + 1; /* Knuth sequence T(n+1) = T(n) * 3 + 1 */

	/*
	 * decrement the gap until it is 1 while sorting the array
	 * using insertion sort
	 */
	while (gap > 0)
	{
		/*
		 * iterates over the array and compares the current element
		 * index i with the previous element index j = i - gap that
		 * are gap positions away, if the current element is smaller
		 * than the previous element, swap them
		 */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j > gap - 1 /* protect beginning of array */
				   && array[j - gap] >= temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		gap = (gap - 1) / 3;	  /* decrement the gap */
		print_array(array, size); /* print after decreasing the interval */
	}
}

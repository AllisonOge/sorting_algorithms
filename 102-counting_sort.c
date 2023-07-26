#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *count = NULL, *output = NULL;
	int i = 0, max = 0;

	if (!array || size < 2)
		return;
	max = array[0];
	for (i = 1; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}
	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	print_array(count, max + 1);
	free(count);
	free(output);
}

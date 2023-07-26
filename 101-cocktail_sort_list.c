#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: doubly linked list of integers
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	int swapped = 1; /* sorted list state initialize to false */

	if (!list || !(*list) || !(*list)->next)
		return;

	current = *list;
    /*
     * perform bidirectional bubble sort in forward and reverse directions
     * until no swaps occur
     */
	while (swapped)
	{
		swapped = 0;
		while (current->next) /* forward bubble sort */
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (current->prev) /* reverse bubble sort */
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: doubly linked list of integers
 * @node1: first node to swap
 * @node2: second node to swap
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *tmp = NULL;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2; /* update head */
	if (node2->next)
		node2->next->prev = node1;
	tmp = node2->next;
	node2->next = node1;
	node2->prev = node1->prev;
	node1->next = tmp;
	node1->prev = node2;
}

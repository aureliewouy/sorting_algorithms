#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * with the insertion sort algorithm in ascending order
 * @list: unsorted doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *previous_node, *current_node;

	if (*list == NULL || (*list)->next == NULL)
		return;

	current_node = *list;
	while (current_node != NULL)
	{
		previous_node = current_node;
		/*go throught the list if ascending order*/
		while (previous_node->prev != NULL &&
				previous_node->n < previous_node->prev->n)
		{
			/*if not asc order, swap two nodes*/
			previous_node->prev->next = previous_node->next;
			/*if not last node*/
			if (previous_node->next != NULL)
				previous_node->next->prev = previous_node->prev;
				previous_node->next = previous_node->prev;
				previous_node->prev = previous_node->prev->prev;
				previous_node->next->prev = previous_node;

			if (previous_node->prev == NULL)
				*list = previous_node;
			else
				previous_node->prev->next = previous_node;
				print_list(*list);
		}
		current_node = current_node->next;
	}
}

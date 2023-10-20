#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next_node = current->next;
		sorted = current->prev;
		while (sorted != NULL && sorted->n > current->n)
		{
			sorted->next = current->next;
			if (current->next != NULL)
				current->next->prev = sorted;
			current->next = sorted;
			current->prev = sorted->prev;
			if (sorted->prev != NULL)
				sorted->prev->next = current;
			else
				*list = current;
			sorted->prev = current;
			sorted = current->prev;
			print_list(*list);
		}
		current = next_node;
	}
}

#include "sort.h"
#include <stddef.h>

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order using
 * Insertion Sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */

void insertion_sort_list(listint_t **list)
{

	listint_t *current = (*list)->next;
	listint_t *to_insert, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		to_insert = current;
		prev = to_insert->prev;

		while (prev != NULL && to_insert->n < prev->n)
		{
			prev->next = to_insert->next;
			if (to_insert->next != NULL)
				to_insert->next->prev = prev;

			to_insert->next = prev;
			to_insert->prev = prev->prev;

			if (prev->prev != NULL)
				prev->prev->next = to_insert;
			else
				*list = to_insert;

			prev->prev = to_insert;

			prev = to_insert->prev;

			print_list(*list);
		}
		current = current->next;
	}
}

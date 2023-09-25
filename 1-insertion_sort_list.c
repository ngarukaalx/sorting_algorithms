#include "sort.h"

/**
 * insertion_sort_list - fuction to sort a list
 * @list: pointer to pointer list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *current_next;

	if (list == NULL || *list == NULL || (*list)->next->next == NULL)
	{
		return;
	}

	current = (*list)->next;

	while (current != NULL)
	{
		current_next = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			current->prev->next = current->next;
			if (current->next != NULL)
			{
				current->next->prev = current->prev;
			}
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;

			if (current->prev == NULL)
			{
				*list = current;
			}
			else
			{
				current->prev->next = current;
			}
			print_list(*list);
		}
		current = current_next;
	}

}

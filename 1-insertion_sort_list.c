#include "sort.h"

/**
 * swap_nodes - swaps position of two nodes in a doubly linked list.
 *
 * @list: head of the list;
 * @node1: pointer to the 1st node to swap;
 * @node2: pointer to the 2nd node to swap.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (!node1->prev)
		node2->prev = NULL;
	else
	{
		node1->prev->next = node2;
		node2->prev = node1->prev;
	}

	if (!node2->next)
		node1->next = NULL;
	else
	{
		node2->next->prev = node1;
		node1->next = node2->next;
	}

	node1->prev = node2;
	node2->next = node1;

	if (!node2->prev)
		*list = node2;
}

/**
 * insertion_sort_list - Insertion sort doubly linked list.
 *
 * @list: pointer to the head of the doubly linked list to sort.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *dummy, *tmp;

	if (!list || !(*list) || !(*list)->next)
		return;

	curr = *list;
	tmp = (*list)->next;
	while (tmp)
	{
		if (curr->n > tmp->n)
		{
			swap_nodes(list, curr, tmp);
			print_list(*list);
			dummy = tmp->prev;
			while (dummy && (dummy->n > tmp->n))
			{
				swap_nodes(list, dummy, tmp);
				print_list(*list);
				dummy = tmp->prev;
			}
			tmp = curr->next;
		}
		else
		{
			tmp = tmp->next;
			curr = curr->next;
		}
	}
}

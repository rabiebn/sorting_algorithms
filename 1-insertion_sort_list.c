#include "sort.h"

/**
 * swap_list - swaps position of two nodes in a doubly linked list.
 *
 * @node_a: pointer to the 1st node to swap;
 * @node_b: pointer to the 2nd node to swap.
*/
void swap_list(listint_t *node1, listint_t *node2)
{
    listint_t *next, *prev;


    next = node2->next;
    prev = node1->prev;

    node2->prev = prev;
    node1->next = next;

    prev->next = node2;
    next->prev = node1;

    node1->prev = node2;
    node2->next = node1;
}

/**
 * insertion_sort_list - Insertion sort doubly linked list.
 *
 * @list: pointer to the head of the doubly linked list to sort.
*/
void insertion_sort_list(listint_t **list)
{
    listint_t *tmp, *tmp2;
    bool swapped;

    if (!list)
        return;
    
    tmp = *list;
    while (tmp->next)
    {
        swapped = false;
        if (tmp->n > tmp->next->n)
        {
            swap_list(tmp, tmp->next);
            print_list(*list);
            swapped = true;
        }
        if (swapped)
        {
            tmp2 = tmp;
            while (tmp2->prev)
            {
                swapped = false;
                if (tmp2->prev->n > tmp2->n)
                {
                    swap_list(tmp2->prev, tmp2);
                    print_list(*list);
                    swapped = true;
                }
                if (!swapped)
                    break;
                tmp2 = tmp2->prev;
            }
            if (!tmp2->prev)
                *list = tmp2;
        }
        tmp = tmp->next;
    }
}

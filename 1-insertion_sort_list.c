#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm
 * @list: Double pointer to the first element of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *prev, *next;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;
    while (current != NULL)
    {
        prev = current->prev;
        next = current->next;
        while (prev != NULL && prev->n > current->n)
        {
            /* Swap current and prev nodes */
            if (prev->prev != NULL)
                prev->prev->next = current;
            else
                *list = current;
            if (current->next != NULL)
                current->next->prev = prev;
            prev->next = current->next;
            current->prev = prev->prev;
            prev->prev = current;
            current->next = prev;

            /* Print the list after each swap */
            print_list(*list);

            prev = current->prev;
        }
        current = next;
    }
}

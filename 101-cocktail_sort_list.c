#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: Pointer to the head of a doubly-linked list of integers.
 * @tail: Pointer to the tail of the list.
 * @shaker: Pointer to the current swapping node of the cocktail algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a list of integers.
 * @tail: A pointer to the tail of the list.
 * @shaker: Pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker_algo;
	bool shaken_not_stirred_ = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred_ == false)
	{
		shaken_not_stirred_ = true;
		for (shaker_algo = *list; shaker_algo != tail; shaker_algo = shaker_algo->next)
		{
			if (shaker_algo->n > shaker_algo->next->n)
			{
				swap_node_ahead(list, &tail, &shaker_algo);
				print_list((const listint_t *)*list);
				shaken_not_stirred_ = false;
			}
		}
		for (shaker_algo = shaker_algo->prev; shaker_algo != *list;
				shaker_algo = shaker_algo->prev)
		{
			if (shaker_algo->n < shaker_algo->prev->n)
			{
				swap_node_behind(list, &tail, &shaker_algo);
				print_list((const listint_t *)*list);
				shaken_not_stirred_ = false;
			}
		}
	}
}

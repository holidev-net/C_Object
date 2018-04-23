/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** list6.c
*/

#include <string.h>
#include <stdlib.h>

#define PRIVATE_LIST
#include "list.h"

__APPROVED_BY(Alexandre)
void	list_merge(list_t *other, sort_func_t func, list_t *this)
{
	size_t i = 0;
	elem_t *elem = this->_front;

	while (other->_size != 0) {
		if (elem == NULL ||
		func(other->_front->data, elem->data) == true) {
			list_insert(i, other->_front->data, this);
			list_pop_front(other);
		} else {
			elem = NEXT(elem);
		}
		++i;
	}
}

__APPROVED_BY(Alexandre)
void	list_reverse(list_t *this)
{
	elem_t	*first_elem = this->_front;
	elem_t	*second_elem = this->_back;
	void	*swap;

	if (this->_size <= 1)
		return;
	while (first_elem != second_elem) {
		swap = first_elem->data;
		first_elem->data = second_elem->data;
		second_elem->data = swap;
		first_elem = NEXT(first_elem);
		if (first_elem == second_elem)
			break;
		second_elem = PREV(second_elem);
	}
}

void	list_unique(egal_comp_func_t func, list_t *this)
{
	size_t i = 1;
	elem_t *elem = this->_front;

	while (elem) {
		if (elem != this->_back &&
		func(elem->data, elem->next->data) == true) {
			list_remove(i, this);
		} else {
			elem = NEXT(elem);
			i++;
		}
	}
}

__APPROVED_BY(Alexandre)
void	list_sort(sort_func_t func, list_t *this)
{
	elem_t	*elem = NULL;
	bool	sorted = false;
	void	*swap;

	if (this->_size <= 1)
		return;
	while (sorted == false) {
		sorted = true;
		elem = this->_front;
		while (elem->next != NULL) {
			if (func(elem->data, elem->next->data) == false) {
				swap = elem->data;
				elem->data = elem->next->data;
				elem->next->data = swap;
				sorted = false;
			}
			elem = NEXT(elem);
		}
	}
}

__APPROVED_BY(Alexandre)
void	list_foreach(foreach_func_t func, list_t *this)
{
	for (elem_t *elem = this->_front; elem != NULL; elem = NEXT(elem))
		func(elem->data);
}


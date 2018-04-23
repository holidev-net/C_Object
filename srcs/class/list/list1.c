/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** list1.c
*/

#include <string.h>
#include <stdlib.h>

#define PRIVATE_LIST
#include "list.h"

__APPROVED_BY(Alexandre)
elem_t *create_new_elem(void *data)
{
	elem_t *elem = malloc(sizeof(*elem));

	if (elem == NULL)
		return (false);
	memset(elem, 0, sizeof(*elem));
	elem->data = data;
	return (elem);
}


__APPROVED_BY(Alexandre)
void	list_assign(size_t n, void const *data, list_t *this)
{
	elem_t *elem;
	void *dupdata;

	list_clear(this);
	if (this->_dup_data == NULL)
		throw_list("dup function not assigned");
	for (size_t i = 0; i < n; ++i) {
		dupdata = this->_dup_data(data);
		if (dupdata == NULL)
			throw_list("error malloc");
		elem = create_new_elem(dupdata);
		if (elem == NULL)
			throw_list("error malloc");
		elem->alloced = true;
		push_elem_back(elem, this);
	}
}

__APPROVED_BY(Alexandre)
void	list_push_back(void *data, list_t *this)
{
	elem_t *elem = create_new_elem(data);

	if (elem == NULL)
		throw_list("error malloc");
	push_elem_back(elem, this);
}

__APPROVED_BY(Alexandre)
void	list_push_front(void *data, list_t *this)
{
	elem_t *elem = create_new_elem(data);

	if (elem == NULL)
		throw_list("error malloc");
	push_elem_front(elem, this);
}
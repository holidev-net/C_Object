/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** list_it.c
*/

#define __PRIVATE_ITERATOR__
#include "list_it.h"
#include "private_list.h"
#include "list.h"

void list_it_prev(list_it_t *this)
{
	if (this->_elem != ((list_t *)this->_list)->_front)
		this->_elem = this->_elem->prev;
}

void list_it_next(list_it_t *this)
{
	if (this->_elem != NULL)
		this->_elem = this->_elem->next;
}

void list_it_move(long n, list_it_t *this)
{
	long i = 0;

	while (i != n) {
		if (n > 0) {
			this->next();
			++i;
		} else {
			this->prev();
			--i;
		}
	}
}

void *list_it_get(list_it_t *this)
{
	return (this->_elem->data);
}

bool list_it_is_start(list_it_t *this)
{
	return (this->_elem == ((list_t *)this->_list)->_front);
}

bool list_it_is_end(list_it_t *this)
{
	return (this->_elem == NULL);
}

static const member_wrap_t	members_tab[] = {
	MEMBER_WRAP(list_it_t, prev, &list_it_prev, 0),
	MEMBER_WRAP(list_it_t, next, &list_it_next, 0),
	MEMBER_WRAP(list_it_t, move, &list_it_move, 1),
	MEMBER_WRAP(list_it_t, is_start, &list_it_is_start, 0),
	MEMBER_WRAP(list_it_t, is_end, &list_it_is_end, 0),
	MEMBER_WRAP(list_it_t, get, &list_it_get, 0)
};

it_t	*init_list_it(void *list)
{
	list_it_t *obj = malloc(sizeof(list_it_t));

	if (obj == NULL)
		throw_it("error malloc");
	if (((list_t *)list)->size() != 0)
		obj->_elem = ((list_t *)list)->_front;
	else
		obj->_elem = NULL;
	obj->_list = list;
	obj->destr = (void *)delete_list_it;
	init_members(obj, PASS_MEMBERS_WRAP(members_tab));
	return ((it_t *)obj);
}

void	delete_list_it(list_it_t **obj)
{
	if (*obj == NULL)
		return;
	free_members(*obj, PASS_MEMBERS_WRAP(members_tab));
	free(*obj);
}
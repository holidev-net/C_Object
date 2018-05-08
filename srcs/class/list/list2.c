/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** list2.c
*/

#include <string.h>
#include <stdlib.h>

#include "init.h"
#include "private_list.h"
#include "list.h"

__APPROVED_BY(Alexandre)
static void push_elem_at(long at, elem_t *elem, list_t *this)
{
	elem_t *it = this->_front;

	if (at < 0)
		at = this->_size + at + 1;
	if (at < 0 || at > (long)this->_size)
		throw_list_elem(at);
	if (this->_size == 0 || at == 0) {
		push_elem_front(elem, this);
	} else if (at >= (long)this->_size) {
		push_elem_back(elem, this);
	} else {
		for (long i = 0; i < at; i++)
			it = NEXT(it);
		if (it != NULL) {
			elem->prev = it->prev;
			elem->next = it;
			it->prev->next = elem;
			it->prev = elem;
			++this->_size;
		}
	}
}

__APPROVED_BY(Alexandre)
void	list_insert(long at, void *data, list_t *this)
{
	elem_t *new_elem = create_new_elem(data);

	if (new_elem == NULL)
		throw_list("error malloc");
	push_elem_at(at, new_elem, this);
}

__APPROVED_BY(Alexandre)
void	list_emplace(long at, void *data, list_t *this)
{
	void *dupdata;
	elem_t *new_elem;

	if (this->_dup_data == NULL)
		throw_list("dup function not assigned");
	dupdata = this->_dup_data(data);
	if (dupdata == NULL)
		throw_list("error malloc");
	new_elem = create_new_elem(dupdata);
	if (new_elem == NULL)
		throw_list("error malloc");
	new_elem->alloced = true;
	push_elem_at(at, new_elem, this);
}

__APPROVED_BY(Alexandre)
void	list_rotate(list_t *this)
{
	if (this->_size < 2)
		return;
	this->_back->next = this->_front;
	this->_front = this->_front->next;
	this->_front->prev = NULL;
	this->_back->next->prev = this->_back;
	this->_back = this->_back->next;
	this->_back->next = NULL;
}

__APPROVED_BY(Alexandre)
void	list_rrotate(list_t *this)
{
	if (this->_size < 2)
		return;
	this->_front->prev = this->_back;
	this->_back = this->_back->prev;
	this->_back->next = NULL;
	this->_front->prev->next = this->_front;
	this->_front = this->_front->prev;
	this->_front->prev = NULL;
}
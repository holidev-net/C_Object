/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** list5.c
*/

#include <string.h>
#include <stdlib.h>

#define PRIVATE_LIST
#include "list.h"

__APPROVED_BY(Alexandre)
void push_elem_front(elem_t *elem, list_t *this)
{
	if (this->_size == 0) {
		this->_front = elem;
		this->_back = elem;
	} else {
		this->_front->prev = elem;
		elem->next = this->_front;
		this->_front = elem;
	}
	++this->_size;
}

__APPROVED_BY(Alexandre)
void push_elem_back(elem_t *elem, list_t *this)
{
	if (this->_size == 0) {
		this->_front = elem;
		this->_back = elem;
	} else {
		this->_back->next = elem;
		elem->prev = this->_back;
		this->_back = elem;
	}
	++this->_size;
}


__APPROVED_BY(Alexandre)
void	list_emplace_back(void *data, list_t *this)
{
	void *dupdata;

	if (this->_dup_data == NULL)
		throw_list("dup function not assigned");
	dupdata = this->_dup_data(data);
	if (dupdata == NULL)
		throw_list("error malloc");
	list_push_back(dupdata, this);
	this->_back->alloced = true;
}

__APPROVED_BY(Alexandre)
void	list_emplace_front(void *data, list_t *this)
{
	void *dupdata;

	if (this->_dup_data == NULL)
		throw_list("dup function not assigned");
	dupdata = this->_dup_data(data);
	if (dupdata == NULL)
		throw_list("error malloc");
	push_elem_front(dupdata, this);
	this->_front->alloced = true;
}

/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** list4.c
*/

#include <string.h>
#include <stdlib.h>

#include "init.h"
#define PRIVATE_LIST
#include "list.h"

__APPROVED_BY(Alexandre)
static elem_t *remove_elem(elem_t *elem, list_t *this)
{
	elem_t *to_free = elem;
	elem_t *next = elem->next ? elem->next : elem->prev;

	--this->_size;
	if (elem->prev != NULL)
		elem->prev->next = elem->next;
	if (elem->next != NULL)
		elem->next->prev = elem->prev;
	if (this->_front == elem)
		this->_front = this->_front->next;
	if (this->_back == elem)
		this->_back = this->_back->prev;
	if (this->_free_data != NULL && to_free->alloced == true)
		this->_free_data(to_free->data);
	free(to_free);
	return (next);
}

__APPROVED_BY(Alexandre)
void	list_remove_if(validator_func_t func, list_t *this)
{
	elem_t *elem = this->_front;

	while (elem != NULL) {
		if (func(elem->data) == true)
			elem = remove_elem(elem, this);
		else
			elem = NEXT(elem);
	}
}

__APPROVED_BY(Alexandre)
void	list_pop_back(list_t *this)
{
	elem_t *elem = this->_back;

	if (this->_size == 0)
		throw_list("list is empty");
	this->_back = this->_back->prev;
	--this->_size;
	if (this->_size != 0)
		this->_back->next = NULL;
	else
		this->_front = NULL;
	if (this->_free_data != NULL && elem->alloced == true)
		this->_free_data(elem->data);
	free(elem);
}

__APPROVED_BY(Alexandre)
void	list_pop_front(list_t *this)
{
	elem_t *elem = this->_front;

	if (this->_size == 0)
		throw_list("list is empty");
	this->_front = this->_front->next;
	--this->_size;
	if (this->_size != 0)
		this->_front->prev = NULL;
	else
		this->_back = NULL;
	if (this->_free_data != NULL && elem->alloced == true)
		this->_free_data(elem->data);
	free(elem);
}

__APPROVED_BY(Alexandre)
void	list_remove(long at, list_t *this)
{
	elem_t *elem = this->_front;

	if (at < 0)
		at = this->_size + at;
	if (at < 0 || at >= (long)this->_size)
		throw_list_elem(at);
	for (long i = 0; i < at; i++)
		elem = NEXT(elem);
	if (elem != this->_front)
		elem->prev->next = elem->next;
	else
		this->_front = elem->next;
	if (elem != this->_back)
		elem->next->prev = elem->prev;
	else
		this->_back = elem->prev;
	--this->_size;
	if (this->_free_data != NULL && elem->alloced == true)
		this->_free_data(elem->data);
	free(elem);
}


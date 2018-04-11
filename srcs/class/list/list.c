/*
** EPITECH PROJECT, 2017
** list.c for C_Object
** File description:
** description
*/

#include <string.h>
#include <stdlib.h>

#include "init.h"
#define PRIVATE_LIST
#include "list.h"

static elem_t *create_new_elem(void *data)
{
	elem_t *elem = malloc(sizeof(*elem));

	if (elem == NULL)
		return (false);
	memset(elem, 0, sizeof(*elem));
	elem->data = data;
	return (elem);
}

void	list_push_front(void *data, list_t *this)
{
	elem_t *elem = create_new_elem(data);

	if (elem == NULL)
		abort();
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

void	list_push_back(void *data, list_t *this)
{
	elem_t *elem = create_new_elem(data);

	if (elem == NULL)
		abort();
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

void	list_insert_at(long at, void *data, list_t *this)
{
	elem_t *elem = this->_front;
	elem_t *new_elem = create_new_elem(data);

	if (at < 0)
		at = this->_size + at;
	if (at < 0)
		abort();
	if (new_elem == NULL)
		abort();
	if (this->_size == 0) {
		this->_front = new_elem;
		this->_back = new_elem;
		++this->_size;
	} else if (at >= (long)this->_size) {
		free(new_elem);
		list_push_back(data, this);
	} else if (at == 0){
		free(new_elem);
		list_push_front(data, this);
	} else {
		for (long i = 0; i < at; i++)
			elem = NEXT(elem);
		if (elem != NULL) {
			new_elem->prev = elem->prev;
			new_elem->next = elem;
			elem->prev->next = new_elem;
			elem->prev = new_elem;
			++this->_size;
		}
	}
}

void	list_pop_front(list_t *this)
{
	elem_t *elem = this->_front;

	if (this->_size == 0)
		abort();
	this->_front = this->_front->next;
	--this->_size;
	if (this->_size != 0)
		this->_front->prev = NULL;
	else
		this->_back = NULL;
	free(elem);
}

void	list_pop_back(list_t *this)
{
	elem_t *elem = this->_back;

	if (this->_size == 0)
		abort();
	this->_back = this->_back->prev;
	--this->_size;
	if (this->_size != 0)
		this->_back->next = NULL;
	else
		this->_front = NULL;
	free(elem);
}

int	*list_front(list_t *this)
{
	if (this->_size == 0)
		abort();
	return (this->_front->data);
}

int	*list_back(list_t *this)
{
	if (this->_size == 0)
		abort();
	return (this->_back->data);
}

size_t list_size(list_t *this)
{
	return this->_size;
}

bool	list_empty(list_t *this)
{
	return this->_size == 0;
}

void	list_assign(size_t n, void const *data,
			dup_data_func_t func, list_t *this)
{
	elem_t *elem;
	void *dupdata;

	for (size_t i = 0; i < n; ++i) {
		dupdata = func(data);
		if (dupdata == NULL)
			abort();
		elem = create_new_elem(dupdata);
		list_push_back(elem, this);
	}
}

void	list_remove_at(long at, list_t *this)
{
	elem_t *elem = this->_front;

	if (at < 0)
		at = this->_size + at;
	if (at < 0 || at >= (long)this->_size)
		abort();
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
	free(elem);
}

void	list_emplace_front(void *data, dup_data_func_t func, list_t *this)
{
	void *dupdata = func(data);

	if (dupdata == NULL)
		abort();
	list_push_front(dupdata, this);
}

void	list_emplace_back(void *data, dup_data_func_t func, list_t *this)
{
	void *dupdata = func(data);

	if (dupdata == NULL)
		abort();
	list_push_back(dupdata, this);
}

void	list_emplace_at(long at, void *data, dup_data_func_t fnc, list_t *this)
{
	void *dupdata = fnc(data);

	if (dupdata == NULL)
		abort();
	list_insert_at(at, dupdata, this);
}

void	list_clear(list_t *this)
{
	while (this->_size != 0)
		list_pop_front(this);
}

void	list_foreach(foreach_func_t func, list_t *this)
{
	for (elem_t *elem = this->_front; elem != NULL; elem = NEXT(elem))
		func(elem->data);
}

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
	free(to_free);
	return (next);
}

void	list_remove_if(removeif_func_t func, list_t *this)
{
	elem_t *elem = this->_front;

	while (elem != NULL) {
		if (func(elem->data) == true)
			elem = remove_elem(elem, this);
		else
			elem = NEXT(elem);
	}
}

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
			list_remove_at(i, this);
		} else {
			elem = NEXT(elem);
			i++;
		}
	}
}

void	list_merge(list_t *other, sort_func_t func, list_t *this)
{
	size_t i = 0;
	elem_t *elem = this->_front;

	while (other->_size != 0) {
		if (elem == NULL ||
		func(other->_front->data, elem->data) == true) {
			list_insert_at(i, other->_front->data, this);
			list_pop_front(other);
		} else {
			elem = NEXT(elem);
		}
		++i;
	}
}

list_t	*init_list(void)
{
	list_t *obj = malloc(sizeof(list_t));

	if (obj == NULL)
		abort();
	obj->_size = 0;
	obj->_front = NULL;
	obj->_back = NULL;
	init_members(obj, 22,
		CREATE_WRAP(obj, assign, &list_assign, 3),
		CREATE_WRAP(obj, front, &list_front, 0),
		CREATE_WRAP(obj, back, &list_back, 0),
		CREATE_WRAP(obj, empty, &list_empty, 0),
		CREATE_WRAP(obj, size, &list_size, 0),
		CREATE_WRAP(obj, clear, &list_clear, 0),
		CREATE_WRAP(obj, insert, &list_insert_at, 2),
		CREATE_WRAP(obj, remove, &list_remove_at, 1),
		CREATE_WRAP(obj, emplace, &list_emplace_at, 3),
		CREATE_WRAP(obj, erase, NULL, 2),
		CREATE_WRAP(obj, push_back, &list_push_back, 1),
		CREATE_WRAP(obj, emplace_back, &list_emplace_back, 2),
		CREATE_WRAP(obj, pop_back, &list_pop_back, 0),
		CREATE_WRAP(obj, push_front, &list_push_front, 1),
		CREATE_WRAP(obj, emplace_front, &list_emplace_front, 2),
		CREATE_WRAP(obj, pop_front, &list_pop_front, 0),
		CREATE_WRAP(obj, merge, &list_merge, 2),
		CREATE_WRAP(obj, remove_if, &list_remove_if, 1),
		CREATE_WRAP(obj, reverse, &list_reverse, 0),
		CREATE_WRAP(obj, unique, &list_unique, 1),
		CREATE_WRAP(obj, sort, &list_sort, 1),
		CREATE_WRAP(obj, foreach, &list_foreach, 1)
	);
	return (obj);
}

void	delete_list(list_t *obj)
{
	list_clear(obj);
	delete_members(obj->push_front);
	free(obj);
}

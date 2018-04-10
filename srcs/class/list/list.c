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

static elem_t *create_new_elem(int nb)
{
	elem_t *elem = malloc(sizeof(*elem));

	if (elem == NULL)
		return (false);
	memset(elem, 0, sizeof(*elem));
	elem->data = nb;
	return (elem);
}

void	list_push_front(int data, list_t *list)
{
	elem_t *elem = create_new_elem(data);

	if (elem == NULL)
		abort();
	if (list->_size == 0) {
		list->_front = elem;
		list->_back = elem;
	} else {
		list->_front->prev = elem;
		elem->next = list->_front;
		list->_front = elem;
	}
	++list->_size;
}

void	list_push_back(int data, list_t *list)
{
	elem_t *elem = create_new_elem(data);

	if (elem == NULL)
		abort();
	if (list->_size == 0) {
		list->_front = elem;
		list->_back = elem;
	} else {
		list->_back->next = elem;
		elem->prev = list->_back;
		list->_back = elem;
	}
	++list->_size;
}

void	list_insert_at(size_t at, int data, list_t *list)
{
	elem_t *elem = list->_front;
	elem_t *new_elem = create_new_elem(data);

	if (new_elem == NULL)
		abort();
	if (list->_size == 0) {
		list->_front = new_elem;
		list->_back = new_elem;
		++list->_size;
	} else if (at >= list->_size) {
		list_push_back(data, list);
	} else if (at == 0){
		list_push_front(data, list);
	} else {
		for (size_t i = 0; i < at; i++)
			elem = NEXT(elem);
		if (elem != NULL) {
			new_elem->prev = elem->prev;
			new_elem->next = elem;
			elem->prev->next = new_elem;
			elem->prev = new_elem;
			++list->_size;
		}
	}
}

void	list_pop_front(list_t *list)
{
	elem_t *elem = list->_front;

	if (list->_size == 0)
		abort();
	list->_front = list->_front->next;
	--list->_size;
	if (list->_size != 0)
		list->_front->prev = NULL;
	else
		list->_back = NULL;
	free(elem);
}

void	list_pop_back(list_t *list)
{
	elem_t *elem = list->_back;

	if (list->_size == 0)
		abort();
	list->_back = list->_back->prev;
	--list->_size;
	if (list->_size != 0)
		list->_back->next = NULL;
	else
		list->_front = NULL;
	free(elem);
}

int	*list_front(list_t *list)
{
	if (list->_size == 0)
		abort();
	return (&list->_front->data);
}

int	*list_back(list_t *list)
{
	if (list->_size == 0)
		abort();
	return (&list->_back->data);
}

size_t list_size(list_t *list)
{
	return list->_size;
}

void	list_remove_at(size_t at, list_t *list)
{
	elem_t *elem = list->_front;

	if (at >= list->_size)
		abort();
	for (size_t i = 0; i < at; i++)
		elem = NEXT(elem);
	if (elem != list->_front)
		elem->prev->next = elem->next;
	else
		list->_front = elem->next;
	if (elem != list->_back)
		elem->next->prev = elem->prev;
	else
		list->_back = elem->prev;
	--list->_size;
	free(elem);
}

void	list_clear(list_t *list)
{
	while (list->_size != 0)
		list_pop_front(list);
}

void	list_foreach(void (*func)(int *), list_t *list)
{
	for (elem_t *elem = list->_front; elem != NULL; elem = NEXT(elem))
		func(&elem->data);
}

static elem_t *remove_elem(elem_t *elem, list_t *list)
{
	elem_t *to_free = elem;
	elem_t *next = elem->next ? elem->next : elem->prev;

	--list->_size;
	if (elem->prev != NULL)
		elem->prev->next = elem->next;
	if (elem->next != NULL)
		elem->next->prev = elem->prev;
	if (list->_front == elem)
		list->_front = list->_front->next;
	if (list->_back == elem)
		list->_back = list->_back->prev;
	free(to_free);
	return (next);
}

void	list_remove_if(bool (*func)(int), list_t *list)
{
	elem_t *elem = list->_front;

	while (elem != NULL) {
		if (func(elem->data) == true)
			elem = remove_elem(elem, list);
		else
			elem = NEXT(elem);
	}
}

void	list_sort(int (*func)(int, int), list_t *list)
{
	elem_t *elem = NULL;
	bool sorted = false;
	int swap;

	if (list->_size <= 1)
		return;
	while (sorted == false) {
		sorted = true;
		elem = list->_front;
		while (elem->next != NULL) {
			if (func(elem->data, elem->next->data) > 0) {
				swap = elem->data;
				elem->data = elem->next->data;
				elem->next->data = swap;
				sorted = false;
			}
			elem = NEXT(elem);
		}
	}
}

void	list_reverse(list_t *list)
{
	elem_t *first_elem = list->_front;
	elem_t *second_elem = list->_back;
	int swap;

	if (list->_size <= 1)
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

list_t	*init_list(unsigned long sizeof_var)
{
	list_t *obj = malloc(sizeof(list_t));

	if (obj == NULL)
		abort();
	obj->_size = 0;
	obj->_data_size = sizeof_var;
	obj->_front = NULL;
	obj->_back = NULL;
	init_members(obj, 14,
		CREATE_WRAP(obj, push_front, &list_push_front, 1),
		CREATE_WRAP(obj, push_back, &list_push_back, 1),
		CREATE_WRAP(obj, pop_front, &list_pop_front, 0),
		CREATE_WRAP(obj, pop_back, &list_pop_back, 0),
		CREATE_WRAP(obj, front, &list_front, 0),
		CREATE_WRAP(obj, back, &list_back, 0),
		CREATE_WRAP(obj, size, &list_size, 0),
		CREATE_WRAP(obj, insert_at, &list_insert_at, 2),
		CREATE_WRAP(obj, remove_at, &list_remove_at, 1),
		CREATE_WRAP(obj, clear, &list_clear, 0),
		CREATE_WRAP(obj, reverse, &list_reverse, 0),
		CREATE_WRAP(obj, sort, &list_sort, 1),
		CREATE_WRAP(obj, foreach, &list_foreach, 1),
		CREATE_WRAP(obj, remove_if, &list_remove_if, 1)
	);
	return (obj);
}

void	delete_list(list_t *obj)
{
	list_clear(obj);
	delete_members(obj->push_front);
	free(obj);
}

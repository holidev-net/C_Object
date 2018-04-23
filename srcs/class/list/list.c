/*
** EPITECH PROJECT, 2017
** list.c for C_Object
** File description:
** description
*/

#include <string.h>
#include <stdlib.h>

#define PRIVATE_LIST
#include "list.h"

__APPROVED_BY(Alexandre)
list_t	*__init_list(dup_data_func_t dup_func, free_data_func_t free_func)
{
	list_t *obj = malloc(sizeof(list_t));

	if (obj == NULL)
		throw_list("error malloc");
	obj->_size = 0;
	obj->_front = NULL;
	obj->_back = NULL;
	obj->_dup_data = dup_func;
	obj->_free_data = free_func;
	init_members(obj, 23,
		CREATE_WRAP(obj, assign, &list_assign, 2),
		CREATE_WRAP(obj, front, &list_front, 0),
		CREATE_WRAP(obj, back, &list_back, 0),
		CREATE_WRAP(obj, empty, &list_empty, 0),
		CREATE_WRAP(obj, size, &list_size, 0),
		CREATE_WRAP(obj, clear, &list_clear, 0),
		CREATE_WRAP(obj, insert, &list_insert, 2),
		CREATE_WRAP(obj, remove, &list_remove, 1),
		CREATE_WRAP(obj, emplace, &list_emplace, 2),
		CREATE_WRAP(obj, push_back, &list_push_back, 1),
		CREATE_WRAP(obj, emplace_back, &list_emplace_back, 1),
		CREATE_WRAP(obj, pop_back, &list_pop_back, 0),
		CREATE_WRAP(obj, push_front, &list_push_front, 1),
		CREATE_WRAP(obj, emplace_front, &list_emplace_front, 1),
		CREATE_WRAP(obj, pop_front, &list_pop_front, 0),
		CREATE_WRAP(obj, rotate, &list_rotate, 0),
		CREATE_WRAP(obj, rrotate, &list_rrotate, 0),
		CREATE_WRAP(obj, merge, &list_merge, 2),
		CREATE_WRAP(obj, remove_if, &list_remove_if, 1),
		CREATE_WRAP(obj, reverse, &list_reverse, 0),
		CREATE_WRAP(obj, unique, &list_unique, 1),
		CREATE_WRAP(obj, sort, &list_sort, 1),
		CREATE_WRAP(obj, foreach, &list_foreach, 1)
	);
	return (obj);
}

__APPROVED_BY(Alexandre)
void	delete_list(list_t **obj)
{
	if (*obj == NULL)
		return;
	list_clear(*obj);
	delete_members((*obj)->assign);
	free(*obj);
}

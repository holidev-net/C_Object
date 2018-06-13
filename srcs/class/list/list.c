/*
** EPITECH PROJECT, 2017
** list.c for C_Object
** File description:
** description
*/

#include <string.h>
#include <stdlib.h>

#include "cobject.h"
#include "private_list.h"
#include "list.h"

// static const init_wrap_t list_init_member [] = {
// 		CREATE_WRAP(obj, assign, &list_assign, 2),
// 		CREATE_WRAP(obj, front, &list_front, 0),
// 		CREATE_WRAP(obj, back, &list_back, 0),
// 		CREATE_WRAP(obj, empty, &list_empty, 0),
// 		CREATE_WRAP(obj, size, &list_size, 0),
// 		CREATE_WRAP(obj, clear, &list_clear, 0),
// 		CREATE_WRAP(obj, insert, &list_insert, 2),
// 		CREATE_WRAP(obj, remove, &list_remove, 1),
// 		CREATE_WRAP(obj, emplace, &list_emplace, 2),
// 		CREATE_WRAP(obj, push_back, &list_push_back, 1),
// 		CREATE_WRAP(obj, emplace_back, &list_emplace_back, 1),
// 		CREATE_WRAP(obj, pop_back, &list_pop_back, 0),
// 		CREATE_WRAP(obj, push_front, &list_push_front, 1),
// 		CREATE_WRAP(obj, emplace_front, &list_emplace_front, 1),
// 		CREATE_WRAP(obj, pop_front, &list_pop_front, 0),
// 		CREATE_WRAP(obj, rotate, &list_rotate, 0),
// 		CREATE_WRAP(obj, rrotate, &list_rrotate, 0),
// 		CREATE_WRAP(obj, merge, &list_merge, 2),
// 		CREATE_WRAP(obj, remove_if, &list_remove_if, 1),
// 		CREATE_WRAP(obj, reverse, &list_reverse, 0),
// 		CREATE_WRAP(obj, unique, &list_unique, 1),
// 		CREATE_WRAP(obj, sort, &list_sort, 1),
// 		CREATE_WRAP(obj, foreach, &list_foreach, 1)
// }

// static const int nb_member = sizeof(list_init_member) / sizeof(init_wrap_t);

static const member_wrap_t	members_tab[] = {
	MEMBER_WRAP(list_t, assign, &list_assign, 2),
	MEMBER_WRAP(list_t, front, &list_front, 0),
	MEMBER_WRAP(list_t, back, &list_back, 0),
	MEMBER_WRAP(list_t, empty, &list_empty, 0),
	MEMBER_WRAP(list_t, size, &list_size, 0),
	MEMBER_WRAP(list_t, clear, &list_clear, 0),
	MEMBER_WRAP(list_t, insert, &list_insert, 2),
	MEMBER_WRAP(list_t, remove, &list_remove, 1),
	MEMBER_WRAP(list_t, emplace, &list_emplace, 2),
	MEMBER_WRAP(list_t, push_back, &list_push_back, 1),
	MEMBER_WRAP(list_t, emplace_back, &list_emplace_back, 1),
	MEMBER_WRAP(list_t, pop_back, &list_pop_back, 0),
	MEMBER_WRAP(list_t, push_front, &list_push_front, 1),
	MEMBER_WRAP(list_t, emplace_front, &list_emplace_front, 1),
	MEMBER_WRAP(list_t, pop_front, &list_pop_front, 0),
	MEMBER_WRAP(list_t, rotate, &list_rotate, 0),
	MEMBER_WRAP(list_t, rrotate, &list_rrotate, 0),
	MEMBER_WRAP(list_t, merge, &list_merge, 2),
	MEMBER_WRAP(list_t, remove_if, &list_remove_if, 1),
	MEMBER_WRAP(list_t, reverse, &list_reverse, 0),
	MEMBER_WRAP(list_t, unique, &list_unique, 1),
	MEMBER_WRAP(list_t, sort, &list_sort, 1),
	MEMBER_WRAP(list_t, foreach, &list_foreach, 1)
};

static const list_t list_skeleton = {
	._size = 0, ._front = NULL, ._back = NULL,
	._dup_data = NULL, ._free_data = NULL};

__APPROVED_BY(Alexandre)
list_t	*init_list_f(dup_data_func_t dup_func, free_data_func_t free_func)
{
	list_t *obj = malloc(sizeof(list_t));

	if (obj == NULL)
		throw_list("error malloc");
	memcpy(obj, &list_skeleton, sizeof(*obj));
	obj->_dup_data = dup_func;
	obj->_free_data = free_func;
	init_members(obj, PASS_MEMBERS_WRAP(members_tab));
	return (obj);
}

__APPROVED_BY(Alexandre)
void	delete_list(list_t **obj)
{
	if (*obj == NULL)
		return;
	list_clear(*obj);
	free_members(*obj, PASS_MEMBERS_WRAP(members_tab));
	free(*obj);
}

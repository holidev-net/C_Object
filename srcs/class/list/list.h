/*
** EPITECH PROJECT, 2017
** list.h for C_Object
** File description:
** description
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

#include "init.h"
#include "list_it.h"

#ifndef DUP_DATA_FUNC
#define DUP_DATA_FUNC
typedef void *(*dup_data_func_t)(void const *);
#endif

#ifndef FREE_DATA_FUNC
#define FREE_DATA_FUNC
typedef void (*free_data_func_t)(void *);
#endif

#ifndef SORT_FUNC
#define SORT_FUNC
typedef bool (*sort_func_t)(void const *, void const *);
#endif

#ifndef EGAL_COMP_FUNC
#define EGAL_COMP_FUNC
typedef bool (*egal_comp_func_t)(void const *, void const *);
#endif

#ifndef FOREACH_FUNC
#define FOREACH_FUNC
typedef void (*foreach_func_t)(void *);
#endif

#ifndef VALIDATOR_FUNC
#define VALIDATOR_FUNC
typedef bool (*validator_func_t)(void const *);
#endif

#ifdef PRIVATE_LIST
#ifdef NEXT
#undef NEXT
#endif
#define NEXT(elem) (elem != NULL ? elem->next : NULL)
#ifdef PREV
#undef PREV
#endif
#define PREV(elem) (elem != NULL ? elem->prev : NULL)

typedef struct list_elem {
	void			*data;
	bool			alloced;
	struct list_elem 	*prev;
	struct list_elem 	*next;
}	elem_t;
elem_t *create_new_elem(void *data);
#endif

typedef struct list {
	void	(*assign)(size_t n, void *data);
	void	*(*front)(void);
	void	*(*back)(void);
	bool	(*empty)(void);
	size_t	(*size)(void);
	void	(*clear)(void);
	void	(*insert)(size_t at, void *data);
	void	(*remove)(size_t at);
	void	(*emplace)(long at, void *data);
	void	(*push_back)(void *data);
	void	(*emplace_back)(void *data);
	void	(*pop_back)(void);
	void	(*push_front)(void *data);
	void	(*emplace_front)(void *data);
	void	(*pop_front)(void);
	void	(*rotate)(void);
	void	(*rrotate)(void);
	void	(*merge)(struct list *other, sort_func_t);
	void	(*remove_if)(validator_func_t);
	void	(*reverse)(void);
	void	(*unique)(egal_comp_func_t);
	void	(*sort)(sort_func_t);
	void	(*foreach)(foreach_func_t);

	#ifdef PRIVATE_LIST
	dup_data_func_t		_dup_data;
	free_data_func_t 	_free_data;
	elem_t			*_front;
	elem_t			*_back;
	size_t			_size;
	#endif
}	list_t;

#define __LIST_DEF_ARG2 NULL
#define __LIST_DEF_ARG1 NULL

#define __LIST_GET_DEF_ARG2(x) (__NONULL(x) ? x : __LIST_DEF_ARG2)
#define __LIST_GET_DEF_ARG1(x) (__NONULL(x) ? x : __LIST_DEF_ARG1)
#define LIST_ARG2(x, unused...) 	__LIST_GET_DEF_ARG2(x)
#define LIST_ARG1(x, args...) 	__LIST_GET_DEF_ARG1(x), LIST_ARG2(args)
#define init_list(x, args...) 	__init_list(LIST_ARG1(x, args))

list_t		*__init_list(dup_data_func_t, free_data_func_t);
void		delete_list(list_t **);

#ifdef PRIVATE_LIST
void	throw_list(char const *msg)__attribute__((nonnull));
void	throw_list_elem(int n);

void	push_elem_front(elem_t *elem, list_t *);
void	push_elem_back(elem_t *elem, list_t *);

void	list_assign(size_t n, void const *data, list_t *);
int	*list_front(list_t *);
int	*list_back(list_t *);
bool	list_empty(list_t *);
size_t	list_size(list_t *);
void	list_clear(list_t *);
void	list_insert(long at, void *data, list_t *);
void	list_remove(long at, list_t *);
void	list_emplace(long at, void *data, list_t *);
void	list_push_back(void *data, list_t *);
void	list_emplace_back(void *data, list_t *);
void	list_pop_back(list_t *);
void	list_push_front(void *data, list_t *);
void	list_emplace_front(void *data, list_t *);
void	list_pop_front(list_t *);
void	list_rotate(list_t *);
void	list_rrotate(list_t *);
void	list_merge(list_t *other, sort_func_t, list_t *);
void	list_remove_if(validator_func_t func, list_t *);
void	list_reverse(list_t *);
void	list_unique(egal_comp_func_t, list_t *);
void	list_sort(sort_func_t func, list_t *);
void	list_foreach(foreach_func_t func, list_t *);
#endif

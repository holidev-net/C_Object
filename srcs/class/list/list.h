/*
** EPITECH PROJECT, 2017
** list.h for C_Object
** File description:
** description
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

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
	struct list_elem	*prev;
	struct list_elem	*next;
}	elem_t;
#endif

typedef struct list {
	int 	*first;
	void	(*assign)(size_t n, void *data, dup_data_func_t);
	void	*(*front)(void);
	void	*(*back)(void);
	bool	(*empty)(void);
	size_t	(*size)(void);
	void	(*clear)(void);
	void	(*erase_all)(free_data_func_t);
	void	(*insert)(size_t at, void *data);
	void	(*remove)(size_t at);
	void	(*emplace)(long at, void *data, dup_data_func_t);
	void	(*erase)(long at, free_data_func_t);
	void	(*push_back)(void *data);
	void	(*emplace_back)(void *data, dup_data_func_t);
	void	(*pop_back)(void);
	void	(*push_front)(void *data);
	void	(*emplace_front)(void *data, dup_data_func_t);
	void	(*pop_front)(void);
	void	(*merge)(struct list *other, sort_func_t);
	void	(*remove_if)(validator_func_t);
	void	(*reverse)(void);
	void	(*unique)(egal_comp_func_t);
	void	(*sort)(sort_func_t);
	void	(*foreach)(foreach_func_t);

	#ifdef PRIVATE_LIST
	elem_t	*_front;
	elem_t	*_back;
	size_t	_size;
	#endif
}	list_t;

list_t		*init_list(void);
void		delete_list(list_t *);

#ifdef PRIVATE_LIST

void	list_assign(size_t n, void const *data, dup_data_func_t dup, list_t *);
int	*list_front(list_t*);
int	*list_back(list_t*);
bool	list_empty(list_t *);
size_t	list_size(list_t *);
void	list_clear(list_t*);
void	list_erase_all(free_data_func_t, list_t*);
void	list_insert_at(long at, void *data, list_t*);
void	list_remove_at(long at, list_t*);
void	list_emplace_at(long at, void *data, dup_data_func_t, list_t*);
/* void list_erase(long at, free_data_func_t); */
void	list_push_back(void *data, list_t*);
void	list_emplace_back(void *data, dup_data_func_t, list_t*);
void	list_pop_back(list_t*);
void	list_push_front(void *data, list_t*);
void	list_emplace_front(void *data, dup_data_func_t, list_t*);
void	list_pop_front(list_t*);
void	list_merge(list_t *other, sort_func_t, list_t*);
void	list_remove_if(validator_func_t func, list_t*);
void	list_reverse(list_t*);
void	list_unique(egal_comp_func_t, list_t*);
void	list_sort(sort_func_t func, list_t*);
void	list_foreach(foreach_func_t func, list_t*);
#endif

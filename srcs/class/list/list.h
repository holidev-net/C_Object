/*
** EPITECH PROJECT, 2017
** list.h for C_Object
** File description:
** description
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

#ifndef SORT_FUNC
#define SORT_FUNC
typedef bool (*sort_func_t)(void *, void *);
#endif

#ifndef FOREACH_FUNC
#define FOREACH_FUNC
typedef void (*foreach_func_t)(int *);
#endif

#ifndef REMOVEIF_FUNC
#define REMOVEIF_FUNC
typedef int (*removeif_func_t)(int);
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
	int			data;
	struct list_elem	*prev;
	struct list_elem	*next;
}	elem_t;
#endif

typedef struct {
	void	(*push_front)(int data);
	void	(*push_back)(int data);
	void	(*pop_front)();
	void	(*pop_back)();
	int	*(*front)();
	int	*(*back)();
	size_t	(*size)();
	void	(*insert_at)(size_t at, int data);
	void	(*remove_at)(size_t at);
	void	(*clear)();
	void	(*reverse)();
	void	(*sort)(sort_func_t);
	void	(*foreach)(foreach_func_t);
	void	(*remove_if)(removeif_func_t);

	#ifdef PRIVATE_LIST
	elem_t	*_front;
	elem_t	*_back;
	size_t	_size;
	size_t	_data_size;
	#endif
}	list_t;

list_t		*init_list(unsigned long sizeof_var);
void		delete_list(list_t *);

#ifdef PRIVATE_STRING

void	list_push_front(int data, list_t*);
void	list_push_back(int data, list_t*);
void	list_pop_front(list_t*);
void	list_pop_back(list_t*);
int	*list_front(list_t*);
int	*list_back(list_t*);
size_t	list_size(list_t *);
void	list_insert_at(size_t at, int data, list_t*);
void	list_remove_at(size_t at, list_t*);
void	list_clear(list_t*);
void	list_reverse(list_t*);
void	list_sort(sort_func_t func, list_t*);
void	list_foreach(foreach_func_t func, list_t*);
void	list_remove_if(remove_if_func_t func, list_t*);
#endif

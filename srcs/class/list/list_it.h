/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** list_it.h
*/

#pragma once

#include "iterator.h"

CLASS {
	void (*prev)(void);
	void (*next)(void);
	void (*move)(long);
	bool (*is_start)(void);
	bool (*is_end)(void);
	void *(*get)(void);
#ifdef __PRIVATE_ITERATOR__
	void		*(*destr)(void **);
	void		*_list; /* aka `list_t *` */
	struct list_elem *_elem;
#endif
}	list_it_t;

it_t	*init_list_it(void *); /* aka `list_t *` */
void	delete_list_it(list_it_t **);
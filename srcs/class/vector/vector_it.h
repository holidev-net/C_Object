/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** vec_it.h
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
	struct vector	*_vec;
	size_t		_pos;
#endif
}	vec_it_t;

it_t	*init_vec_it(void *); /* aka `vector_t *` */
void	delete_vec_it(vec_it_t **);
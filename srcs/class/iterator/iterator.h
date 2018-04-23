/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** iterator.h
*/

#pragma once

#include <stdbool.h>
#include "init.h"

/*	This class is a pure virtual class.
	His member functions must be define by the heredity. */
CLASS {
	void (*prev)(void);
	void (*next)(void);
	void (*move)(long);
	bool (*is_start)(void);
	bool (*is_end)(void);
	void *(*get)(void);
#ifdef __PRIVATE_ITERATOR__
	void *(*destr)(void **);
#endif
}	it_t;

void delete_it(it_t **);

#ifdef __PRIVATE_ITERATOR__
void throw_it(char *msg)__attribute__((nonnull));
#endif
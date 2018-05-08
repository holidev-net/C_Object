/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** pair.h
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

CLASS {
	void *first;
	void *second;
}	pair_t;

pair_t		*init_pair(void *first, void *second);
void		delete_pair(pair_t **);

#define		MAKE_PAIR(f, s) {.first = f, .second = s}

#ifdef __PRIVATE_PAIR__
#endif
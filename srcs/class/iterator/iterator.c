/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** iterator.c
*/

#include <stdio.h>

#define __PRIVATE_ITERATOR__
#include "iterator.h"

void delete_it(it_t **obj)
{
	if (*obj == NULL)
		return;
	(*obj)->destr((void**)obj);
}

void throw_it(char *msg)
{
	fprintf(stderr, "%s : %s\n", "iterator", msg);
	abort();
}
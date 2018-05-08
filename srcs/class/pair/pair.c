/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** pair.c
*/

#include "init.h"

pair_t		*init_pair(void *first, void *second)
{
	pair_t	*obj = malloc(sizeof(*obj));

	obj.first = first;
	obj.second = second;
	return (obj);
}

void		delete_pair(pair_t **obj)
{
	if (*obj == NULL)
		return;
	free(obj);
}
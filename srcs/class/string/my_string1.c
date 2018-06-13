/*
** EPITECH PROJECT, 2017
** string.c for C_Object
** File description:
** description
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "cobject.h"
#include "private_string.h"
#include "str.h"

char *front(string_t *this)
{
	return (&this->_str[0]);
}

char *back(string_t *this)
{
	return (&this->_str[this->_size - 1]);
}

static const member_wrap_t	members_tab[] = {
	MEMBER_WRAP(string_t, assign, &assign, 1),
	MEMBER_WRAP(string_t, length, &length, 0),
	MEMBER_WRAP(string_t, clear, &clear, 0),
	MEMBER_WRAP(string_t, empty, &empty, 0),
	MEMBER_WRAP(string_t, at, &at, 1),
	MEMBER_WRAP(string_t, front, &front, 0),
	MEMBER_WRAP(string_t, back, &back, 0)
};

string_t	*init_string(void)
{
	string_t *obj = malloc(sizeof(string_t));

	if (obj == NULL)
		abort();
	obj->_size = 0;
	obj->_str = strdup("");
	if (obj->_str == NULL)
		abort();
	init_members(obj, PASS_MEMBERS_WRAP(members_tab));
	return (obj);
}

void		delete_string(string_t **obj)
{
	(*obj)->clear();
	free((*obj)->_str);
	free_members(*obj, PASS_MEMBERS_WRAP(members_tab));
	free(*obj);
}

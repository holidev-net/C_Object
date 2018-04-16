/*
** EPITECH PROJECT, 2017
** string.c for C_Object
** File description:
** description
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "init.h"
#define PRIVATE_STRING
#include "str.h"

void assign(const char *str, string_t *this)
{
	free(this->_str);
	this->_str = strdup(str);
	if (this->_str == NULL)
		abort();
	this->_size = strlen(this->_str);
}

size_t length(string_t *this)
{
	return (this->_size);
}

void clear(string_t *this)
{
	free(this->_str);
	this->_str = strdup("");
	if (this->_str == NULL)
		abort();
	this->_size = 0;
}

bool empty(string_t *this)
{
	return (this->_size == 0);
}

char *at(long i, string_t *this)
{
	if (i < 0)
		i = this->_size - i;
	if (i >= 0 && i < (long)this->_size) {
		return (&this->_str[i]);
	}
	abort();
}

char *front(string_t *this)
{
	return (&this->_str[0]);
}

char *back(string_t *this)
{
	return (&this->_str[this->_size - 1]);
}

string_t	*init_string(void)
{
	string_t *obj = malloc(sizeof(string_t));

	if (obj == NULL)
		abort();
	obj->_size = 0;
	obj->_str = strdup("");
	if (obj->_str == NULL)
		abort();
	init_members(obj, 7,
		CREATE_WRAP(obj, assign, &assign, 1),
		CREATE_WRAP(obj, length, &length, 0),
		CREATE_WRAP(obj, clear, &clear, 0),
		CREATE_WRAP(obj, empty, &empty, 0),
		CREATE_WRAP(obj, at, &at, 1),
		CREATE_WRAP(obj, front, &front, 0),
		CREATE_WRAP(obj, back, &back, 0));
	return (obj);
}

void		delete_string(string_t *obj)
{
	obj->clear();
	free(obj->_str);
	delete_members(obj->assign);
	free(obj);
}

/*
** EPITECH PROJECT, 2017
** string.c for C_Object
** File description:
** description
*/

#define PRIVATE_STRING

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "init.h"

void assign(const char *str, string_t *this)
{
	if (this->_str != NULL) {
		free(this->_str);
	}
	this->_str = strdup(str);
	this->_size = (this->_str != NULL ? strlen(this->_str) : 0);
}

size_t length(string_t *this)
{
	return (this->_size);
}

void clear(string_t *this)
{
	if (this->_str != NULL) {
		free(this->_str);
		this->_str = NULL;
		this->_size = 0;
	}
}

bool empty(string_t *this)
{
	return (this->_size == 0);
}

char *at(size_t i, string_t *this)
{
	if (i < this->_size) {
		return (&this->_str[i]);
	}
	return (NULL);
}

char *front(string_t *this)
{
	if (this->_size != 0) {
		return (&this->_str[0]);
	}
	return (NULL);
}

char *back(string_t *this)
{
	if (this->_size != 0) {
		return (&this->_str[this->_size - 1]);
	}
	return (NULL);
}

string_t	*init_string()
{
	string_t *obj = malloc(sizeof(string_t));

	if (obj == NULL) {
		return (NULL);
	}
	obj->_size = 0;
	obj->_str = NULL;
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
	delete_members(obj->assign);
	free(obj);
}

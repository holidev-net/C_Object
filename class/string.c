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
	obj->assign = init_member(obj, &assign, 1);
	obj->length = init_member(obj, &length, 0);
	obj->clear = init_member(obj, &clear, 0);
	obj->empty = init_member(obj, &empty, 0);
	obj->at = init_member(obj, &at, 1);
	obj->front = init_member(obj, &front, 0);
	obj->back = init_member(obj, &back, 0);
	return (obj);
}

void		delete_string(string_t *obj)
{
	obj->clear();
	delete_member(obj->assign);
	delete_member(obj->length);
	delete_member(obj->clear);
	delete_member(obj->empty);
	delete_member(obj->at);
	delete_member(obj->front);
	delete_member(obj->back);
	free(obj);
}

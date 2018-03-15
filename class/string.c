/*
** EPITECH PROJECT, 2017
** string.c for C_Object
** File description:
** description
*/

#define PRIVATE_STRING

#include <stdlib.h>
#include <string.h>
#include "string.h"
#include "init.h"

void assign(const char *str, string_t *this)
{
	if (this->_str != NULL) {
		free(this->_str);
	}
	this->_str = strdup(str);
}

string_t	*init_string()
{
	string_t *obj = malloc(sizeof(string_t));

	if (obj == NULL)
		return (NULL);
	obj->_size = 0;
	obj->_str = malloc(sizeof(char));
	if (obj->_str == NULL)
		return (free(obj), NULL);
	*obj->_str = '\0';
	obj->assign = init_member(obj, &assign, 0, &obj->memberSize);
	return obj;
}

void		delete_string(string_t *obj)
{
	// delete_member(obj->setA, obj->memberSize);
	free(obj);
}

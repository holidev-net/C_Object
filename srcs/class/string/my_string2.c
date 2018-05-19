/*
** EPITECH PROJECT, 2017
** PSU_myftp_2017
** File description:
** my_string1.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "cobject.h"
#include "private_string.h"
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
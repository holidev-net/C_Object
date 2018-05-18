/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** list3.c
*/

#include <string.h>
#include <stdlib.h>

#include "cobject.h"
#define PRIVATE_LIST
#include "list.h"

__APPROVED_BY(Alexandre)
int	*list_front(list_t *this)
{
	if (this->_size == 0)
		throw_list("list is empty");
	return (this->_front->data);
}

__APPROVED_BY(Alexandre)
int	*list_back(list_t *this)
{
	if (this->_size == 0)
		throw_list("list is empty");
	return (this->_back->data);
}

__APPROVED_BY(Alexandre)
bool	list_empty(list_t *this)
{
	return (this->_size == 0);
}

__APPROVED_BY(Alexandre)
size_t list_size(list_t *this)
{
	return (this->_size);
}

__APPROVED_BY(Alexandre)
void	list_clear(list_t *this)
{
	while (this->_size != 0)
		list_pop_front(this);
}

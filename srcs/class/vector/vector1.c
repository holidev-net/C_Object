/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** vector1.c
*/

#include <string.h>

#define PRIVATE_VECTOR
#include "vector.h"

__APPROVED_BY(Alexandre)
size_t	vector_size(vector_t *this)
{
	return (this->_size);
}

__APPROVED_BY(Alexandre)
void	vector_resize(size_t n, void *data, vector_t *this)
{
	if (n < this->_size) {
		for (size_t i = n; i < this->_size; ++i)
			remove_elem(i, this);
	} else if (n > this->_size) {
		if (n > this->_capacity)
			vector_reserve(n, this);
		for (size_t i = this->_size; i < n; ++i)
			insert_elem(i, data, this);
	}
	this->_size = n;
}

__APPROVED_BY(Alexandre)
size_t	vector_capacity(vector_t *this)
{
	return (this->_capacity);
}

__APPROVED_BY(Alexandre)
bool	vector_empty(vector_t *this)
{
	return (this->_size == 0);
}

__APPROVED_BY(Alexandre)
void	vector_reserve(size_t n, vector_t *this)
{
	void *new_datas;

	if (n > this->_capacity) {
		new_datas = calloc(sizeof(void *), n);
		if (new_datas == NULL)
			throw_vector("error malloc");
		memcpy(new_datas, this->_datas, sizeof(void *) * this->_size);
		free(this->_datas);
		this->_datas = new_datas;
		this->_capacity = n;
	}
}


/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** vector2.c
*/

#include <string.h>

#define PRIVATE_VECTOR
#include "vector.h"

__APPROVED_BY(Alexandre)
void	vector_shrink_to_fit(vector_t *this)
{
	void *new_datas;

	if (this->_capacity > this->_size) {
		for (size_t i = this->_size; i < this->_capacity; ++i)
			remove_elem(i, this);
		new_datas = calloc(sizeof(void *), this->_size);
		if (new_datas == NULL)
			throw_vector("error malloc");
		bzero(new_datas, sizeof(void *) * this->_size);
		memcpy(new_datas, this->_datas, sizeof(void *) * this->_size);
		free(this->_datas);
		this->_datas = new_datas;
	}
	this->_capacity = this->_size;
}

__APPROVED_BY(Alexandre)
void	*vector_at(long at, vector_t *this)
{
	if (at < 0)
		at = this->_size + at;
	if (at < 0 || at >= (long)this->_size)
		throw_vector_elem(at);
	return (this->_datas[at]);
}

__APPROVED_BY(Alexandre)
void	*vector_front(vector_t *this)
{
	if (this->_size == 0)
		throw_vector("vector is empty");
	return (*this->_datas);
}

__APPROVED_BY(Alexandre)
void	*vector_back(vector_t *this)
{
	if (this->_size == 0)
		throw_vector("vector is empty");
	return (this->_datas[this->_size - 1]);
}


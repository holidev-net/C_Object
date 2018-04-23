/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** vector3.c
*/

#include <string.h>

#define PRIVATE_VECTOR
#include "vector.h"

__APPROVED_BY(Alexandre)
void	vector_assign(size_t n, void *data, vector_t *this)
{
	vector_clear(this);
	if (n > this->_capacity)
		vector_reserve(n, this);
	for (size_t i = 0; i < n; ++i)
		insert_elem(i, data, this);
	this->_size = n;
}

__APPROVED_BY(Alexandre)
void	vector_push_back(void *data, vector_t *this)
{
	if (this->_capacity == 0)
		vector_reserve(1, this);
	else if (this->_size == this->_capacity)
		vector_reserve(this->_capacity * 2, this);
	insert_elem(this->_size, data, this);
	++this->_size;
}

__APPROVED_BY(Alexandre)
void	vector_pop_back(vector_t *this)
{
	if (this->_size == 0)
		throw_vector("vector is empty");
	remove_elem(this->_size - 1, this);
	--this->_size;
}

__APPROVED_BY(Alexandre)
void	vector_insert(long at, void *data, vector_t *this)
{
	if (at < 0)
		at = this->_size + at + 1;
	if (at < 0 || at > (long)this->_size)
		throw_vector_elem(at);
	if (this->_capacity == 0)
		vector_reserve(1, this);
	else if (this->_size == this->_capacity)
		vector_reserve(this->_capacity * 2, this);
	if (at != (long)this->_size)
		memmove(this->_datas + at + 1, this->_datas + at,
			sizeof(void*) * (this->_size - at));
	insert_elem(at, data, this);
	++this->_size;
}

__APPROVED_BY(Alexandre)
void	vector_erase(long at, vector_t *this)
{
	if (at < 0)
		at = this->_size + at;
	if (at < 0 || at >= (long)this->_size)
		throw_vector_elem(at);
	if (at != (long)this->_size) {
		remove_elem(at, this);
		memmove(this->_datas + at, this->_datas + at + 1,
			sizeof(void *) * (this->_size - at - 1));
	}
	--this->_size;
}

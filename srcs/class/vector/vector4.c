/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** vector4.c
*/


#define PRIVATE_VECTOR
#include "vector.h"

void	vector_swap(long p1, long p2, vector_t *this)
{
	void *swap;

	if (p1 < 0)
		p1 = this->_size + p1 - 1;
	if (p2 < 0)
		p2 = this->_size + p2 - 1;
	if (p1 < 0 || p1 >= (long)this->_size ||
			p2 < 0 || p2 >= (long)this->_size)
		throw_vector_elem(p1 < 0 || p1 >= (long)this->size ? p1 : p2);
	swap = this->_datas[p1];
	this->_datas[p1] = this->_datas[p2];
	this->_datas[p2] = swap;
}

__APPROVED_BY(Alexandre)
void	vector_clear(vector_t *this)
{
	for (size_t i = 0; i < this->_size; ++i)
		remove_elem(i, this);
	this->_size = 0;
}
/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** vec_it.c
*/

#define __PRIVATE_ITERATOR__
#include "vector_it.h"
#include "vector.h"

void vec_it_prev(vec_it_t *this)
{
	if (this->_pos != 0)
		--this->_pos;
}

void vec_it_next(vec_it_t *this)
{
	if (this->_pos != this->_vec->size())
		++this->_pos;
}

void vec_it_move(long n, vec_it_t *this)
{
	if ((long)this->_pos - n < 0 || (long)this->_pos + n < 0)
		this->_pos = 0;
	else if (this->_pos + n > this->_vec->size() ||
		this->_pos - n > this->_vec->size())
		this->_pos = this->_vec->size() - 1;
	else
		this->_pos += n;
}

void *vec_it_get(vec_it_t *this)
{
	return (this->_vec->at(this->_pos));
}

bool vec_it_is_start(vec_it_t *this)
{
	return (this->_pos == 0);
}

bool vec_it_is_end(vec_it_t *this)
{
	return (this->_pos == this->_vec->size());
}

it_t	*init_vec_it(void *vec)
{
	vec_it_t *obj = malloc(sizeof(vec_it_t));

	if (obj == NULL)
		throw_it("error malloc");
	obj->_pos = 0;
	obj->_vec = vec;
	obj->destr = (void *)delete_vec_it;
	init_members(obj, 6,
		CREATE_WRAP(obj, prev, &vec_it_prev, 0),
		CREATE_WRAP(obj, next, &vec_it_next, 0),
		CREATE_WRAP(obj, move, &vec_it_move, 1),
		CREATE_WRAP(obj, is_start, &vec_it_is_start, 0),
		CREATE_WRAP(obj, is_end, &vec_it_is_end, 0),
		CREATE_WRAP(obj, get, &vec_it_get, 0)
	);
	return ((it_t *)obj);
}

void	delete_vec_it(vec_it_t **obj)
{
	if (*obj == NULL)
		return;
	delete_members((*obj)->prev);
	free(*obj);
}
/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** vector.c
*/

#include <string.h>
#include <stdlib.h>

#define PRIVATE_VECTOR
#include "vector.h"

size_t	vector_size(vector_t *this)
{
	return (this->_size);
}

void	vector_resize(size_t n, void *data, vector_t *this)
{
	void *dupdata;

	if (n < this->_size) {
		for (size_t i = n; i < this->_size; ++i) {
			if (this->_free_data != NULL)
				this->_free_data(this->_datas[i]);
		}
	} else if (n > this->_size) {
		if (n > this->_capacity)
			vector_reserve(n, this);
		for (size_t i = this->_size; i < n; ++i)
			if (this->_dup_data != NULL) {
				dupdata = this->_dup_data(data);
				if (dupdata == NULL)
					abort();
				this->_datas[i] = dupdata;
			} else {
				this->_datas[i] = data;
			}
	}
	this->_size = n;
}

size_t	vector_capacity(vector_t *this)
{
	return (this->_capacity);
}

bool	vector_empty(vector_t *this)
{
	return (this->_size == 0);
}

void	vector_reserve(size_t n, vector_t *this)
{
	void *new_datas;

	if (n > this->_capacity) {
		new_datas = malloc(sizeof(void *) * n);
		if (new_datas == NULL)
			abort();
		memcpy(new_datas, this->_datas, sizeof(void *) * this->_size);
		bzero(new_datas + this->_size, sizeof(void *) * (n - this->_size));
		free(this->_datas);
		this->_datas = new_datas;
		this->_capacity = n;
	}
}

void	vector_shrink_to_fit(vector_t *this)
{
	void *new_datas;

	if (this->_capacity > this->_size) {
		if (this->_free_data != NULL)
			for (size_t i = this->_size; i < this->_capacity; ++i)
				this->_free_data(this->_datas[i]);
		new_datas = malloc(sizeof(void *) * this->_size);
		if (new_datas == NULL)
			abort();
		memcpy(new_datas, this->_datas, sizeof(void *) * this->_size);
		free(this->_datas);
		this->_datas = new_datas;
	}
	this->_capacity = this->_size;
}

void	*vector_at(long at, vector_t *this)
{
	if (at < 0)
		at = this->_size + at;
	if (at < 0 || at >= (long)this->_size)
		abort();
	return (this->_datas + at);
}

void	*vector_front(vector_t *this)
{
	if (this->_size == 0)
		abort();
	return (this->_datas);
}

void	*vector_back(vector_t *this)
{
	if (this->_size == 0)
		abort();
	return (&this->_datas[this->_size - 1]);
}

void	vector_assign(size_t n, void *data, vector_t *this)
{
	void *dupdata;

	vector_clear(this);
	if (n > this->_capacity)
		vector_reserve(n, this);
	for (size_t i = 0; i < n; ++i) {
		if (this->_dup_data != NULL) {
			dupdata = this->_dup_data(data);
			if (dupdata == NULL)
				abort();
			this->_datas[i] = dupdata;
		} else {
			this->_datas[i] = data;
		}		
	}
	this->_size = n;
}

void	vector_push_back(void *data, vector_t *this)
{
	if (this->_size == this->_capacity)
		vector_reserve(this->_capacity * 2, this);
	this->_datas[this->_size] = data;
	++this->_size;
}

void	vector_pop_back(vector_t *this)
{
	if (this->_size == 0)
		abort();
	--this->_size;
}

void	vector_insert(long at, void *data, vector_t *this)
{
	if (at < 0)
		at = this->_size + at;
	if (at < 0 || at > (long)this->_size)
		abort();
	if (this->_size == this->_capacity)
		vector_reserve(this->_capacity * 2, this);
	if (at != (long)this->_size)
		memmove(this->_datas + at + 1, this->_datas + at,
			sizeof(void*) * (this->_size - at));
	this->_datas[at] = data;
	++this->_size;
}

void	vector_erase(long at, vector_t *this)
{
	if (at < 0)
		at = this->_size + at - 1;
	if (at < 0 || at >= (long)this->_size)
		abort();
	if (at != (long)this->_size)
		memmove(this->_datas + at, this->_datas + at + 1,
			sizeof(void *) * (this->_size - at - 1));
	--this->_size;
}

void	vector_swap(long p1, long p2, vector_t *this)
{
	void *swap;

	if (p1 < 0)
		p1 = this->_size + p1 - 1;
	if (p2 < 0)
		p2 = this->_size + p2 - 1;
	if (p1 < 0 || p2 < 0 || p1 >= (long)this->_size ||
				p2 >= (long)this->_size)
		abort();
	swap = this->_datas[p1];
	this->_datas[p1] = this->_datas[p2];
	this->_datas[p2] = swap;
}

void	vector_clear(vector_t *this)
{
	this->_size = 0;
}

void	vector_emplace(long at, void *data, vector_t *this)
{
	if (this->_dup_data == NULL)
		abort();
	data = this->_dup_data(data);
	if (data == NULL)
		abort();
	vector_assign(at, data, this);
}

void	vector_emplace_back(void *data, vector_t *this)
{
	if (this->_dup_data == NULL)
		abort();
	data = this->_dup_data(data);
	if (data == NULL)
		abort();
	vector_push_back(data, this);	
}
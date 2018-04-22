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

__APPROVED_BY(Alexandre)
void insert_elem(size_t i, void *data, vector_t *this)
{
	void *dupdata;

	if (this->_dup_data != NULL) {
		dupdata = this->_dup_data(data);
		if (dupdata == NULL)
			throw_vector("error malloc");
		this->_datas[i] = dupdata;
	} else {
		this->_datas[i] = data;
	}
}

__APPROVED_BY(Alexandre)
void remove_elem(size_t i, vector_t *this)
{
	if (this->_free_data != NULL && this->_datas[i] != NULL)
		this->_free_data(this->_datas[i]);
	this->_datas[i] = NULL;
}

__APPROVED_BY(Alexandre)
vector_t *__init_vector(dup_data_func_t dup_func, free_data_func_t free_func)
{
	vector_t *obj = malloc(sizeof(vector_t));

	if (obj == NULL)
		throw_vector("error malloc");
	obj->_dup_data = dup_func;
	obj->_free_data = free_func;
	obj->_datas = NULL;
	obj->_size = 0;
	obj->_capacity = 0;
	init_members(obj, 16,
		CREATE_WRAP(obj, size, &vector_size, 0),
		CREATE_WRAP(obj, resize, &vector_resize, 2),
		CREATE_WRAP(obj, capacity, &vector_capacity, 0),
		CREATE_WRAP(obj, empty, &vector_empty, 0),
		CREATE_WRAP(obj, reserve, &vector_reserve, 1),
		CREATE_WRAP(obj, shrink_to_fit, &vector_shrink_to_fit, 0),
		CREATE_WRAP(obj, at, &vector_at, 1),
		CREATE_WRAP(obj, front, &vector_front, 0),
		CREATE_WRAP(obj, back, &vector_back, 0),
		CREATE_WRAP(obj, assign, &vector_assign, 2),
		CREATE_WRAP(obj, push_back, &vector_push_back, 1),
		CREATE_WRAP(obj, pop_back, &vector_pop_back, 0),
		CREATE_WRAP(obj, insert, &vector_insert, 2),
		CREATE_WRAP(obj, erase, &vector_erase, 1),
		CREATE_WRAP(obj, swap, &vector_swap, 2),
		CREATE_WRAP(obj, clear, &vector_clear, 0)
	);
	return (obj);
}

__APPROVED_BY(Alexandre)
void	delete_vector(vector_t **obj)
{
	if (*obj == NULL)
		return;
	(*obj)->clear();
	free((*obj)->_datas);
	delete_members((*obj)->size);
	free(*obj);
}

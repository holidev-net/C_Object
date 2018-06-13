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

static const member_wrap_t	members_tab[] = {
	MEMBER_WRAP(vector_t, size, &vector_size, 0),
	MEMBER_WRAP(vector_t, resize, &vector_resize, 2),
	MEMBER_WRAP(vector_t, capacity, &vector_capacity, 0),
	MEMBER_WRAP(vector_t, empty, &vector_empty, 0),
	MEMBER_WRAP(vector_t, reserve, &vector_reserve, 1),
	MEMBER_WRAP(vector_t, shrink_to_fit, &vector_shrink_to_fit, 0),
	MEMBER_WRAP(vector_t, at, &vector_at, 1),
	MEMBER_WRAP(vector_t, front, &vector_front, 0),
	MEMBER_WRAP(vector_t, back, &vector_back, 0),
	MEMBER_WRAP(vector_t, assign, &vector_assign, 2),
	MEMBER_WRAP(vector_t, push_back, &vector_push_back, 1),
	MEMBER_WRAP(vector_t, pop_back, &vector_pop_back, 0),
	MEMBER_WRAP(vector_t, insert, &vector_insert, 2),
	MEMBER_WRAP(vector_t, erase, &vector_erase, 1),
	MEMBER_WRAP(vector_t, swap, &vector_swap, 2),
	MEMBER_WRAP(vector_t, clear, &vector_clear, 0)
};

__APPROVED_BY(Alexandre, Benjamin)
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
	init_members(obj, PASS_MEMBERS_WRAP(members_tab));
	return (obj);
}

__APPROVED_BY(Alexandre)
void	delete_vector(vector_t **obj)
{
	if (*obj == NULL)
		return;
	(*obj)->clear();
	free((*obj)->_datas);
	free_members(*obj, PASS_MEMBERS_WRAP(members_tab));
	free(*obj);
}

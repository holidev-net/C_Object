/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** test_vector.cpp
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "vector.h"
#include "cobject.h"

typedef struct {
	int i;
	void *ptr;
}	test_struct_t;

test_struct_t test_struct = {42, NULL};

static void *dupdata(test_struct_t const *data)
{
	test_struct_t *ndata = malloc(sizeof(*ndata));

	ndata->i = data->i;
	ndata->ptr = malloc(100);
	return (ndata);
}

static void freedata(test_struct_t *data)
{
	if (data) {
		free(data->ptr);
		free(data);
	}
}

void test_alloc()
{
	__CLEAN(vector) vector_t *vector = new(vector);
	__CLEAN(vector) vector_t *vector2 = new(vector,
	(dup_data_func_t)dupdata, (free_data_func_t)freedata);

	vector->resize(100, &test_struct);
	assert(vector->size() == 100);
	assert(vector->capacity() == 100);
	vector->push_back(&test_struct);
	assert(vector->size() == 101);
	assert(vector->capacity() == 200);

	vector2->reserve(50);
	assert(vector2->size() == 0);
	assert(vector2->capacity() == 50);
	vector2->resize(100, &test_struct);
	assert(vector2->size() == 100);
	assert(vector2->capacity() == 100);
	vector2->resize(10, &test_struct);
	assert(vector2->size() == 10);
	assert(vector2->capacity() == 100);
	vector2->shrink_to_fit();
	assert(vector2->size() == 10);
	assert(vector2->capacity() == 10);
	vector2->push_back(&test_struct);
	assert(vector2->size() == 11);
	assert(vector2->capacity() == 20);

	for (size_t i = 0; i < vector2->size(); ++i)
		((test_struct_t *)vector2->at(i))->i = i;
	for (size_t i = 0; i < vector2->size(); ++i)
		assert(((test_struct_t *)vector2->at(i))->i == i);
	for (size_t i = 0; i < vector->size(); ++i)
		((test_struct_t *)vector->at(i))->i = i;
	for (size_t i = 0; i < vector->size(); ++i)
		assert(((test_struct_t *)vector->at(i))->i == vector->size() - 1);
	assert(test_struct.i == vector->size() - 1);
	test_struct.i = 42;
}

void test_assign()
{
	__CLEAN(vector) vector_t *vector = new(vector);
	__CLEAN(vector) vector_t *vector2 = new(vector,
	(dup_data_func_t)dupdata, (free_data_func_t)freedata);

	vector->assign(100, &test_struct);
	vector2->assign(100, &test_struct);
	assert(vector->size() == 100);
	assert(vector->capacity() == 100);
	assert(vector2->size() == 100);
	assert(vector->capacity() == 100);
	vector->assign(100, &test_struct);
	vector2->assign(100, &test_struct);
	assert(vector->size() == 100);
	assert(vector->capacity() == 100);
	assert(vector2->size() == 100);
	assert(vector->capacity() == 100);
}

void test_insert()
{
	__CLEAN(vector) vector_t *vector = new(vector,
	(dup_data_func_t)dupdata, (free_data_func_t)freedata);

	vector->assign(10, &test_struct);
	for (size_t i = 0; i < vector->size(); ++i)
		((test_struct_t *)vector->at(i))->i = i;

	vector->insert(0, &test_struct);
	assert(vector->size() == 11);
	assert(((test_struct_t *)vector->front())->i == 42);
	assert(((test_struct_t *)vector->at(1))->i == 0);
	assert(((test_struct_t *)vector->back())->i == 9);
	vector->erase(0);
	assert(vector->size() == 10);
	assert(((test_struct_t *)vector->front())->i == 0);
	assert(((test_struct_t *)vector->back())->i == 9);

	vector->insert(-1, &test_struct);
	assert(vector->size() == 11);
	assert(((test_struct_t *)vector->front())->i == 0);
	assert(((test_struct_t *)vector->at(-2))->i == 9);
	assert(((test_struct_t *)vector->at(-1))->i == 42);
	assert(((test_struct_t *)vector->back())->i == 42);
	vector->erase(-1);
	assert(vector->size() == 10);
	assert(((test_struct_t *)vector->front())->i == 0);
	assert(((test_struct_t *)vector->back())->i == 9);
}

int main()
{
	test_alloc();
	test_assign();
	test_insert();
}
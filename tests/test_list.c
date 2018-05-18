/*
** EPITECH PROJECT, 2017
** list.c for C_Object
** File description:
** description
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "cobject.h"

typedef struct {
	int i;
	void *ptr;
}	test_struct_t;

test_struct_t test_struct = {42, NULL};

void test_get()
{
	list_t *list = new(list);

	assert(list->empty() == true);
	assert(list->size() == 0);
	list->push_front((void*)1);
	assert(list->empty() == false);
	assert(list->size() == 1);
	assert(list->front() == (void*)1);
	assert(list->back() == (void*)1);
	list->push_back((void*)2);
	assert(list->empty() == false);
	assert(list->size() == 2);
	assert(list->front() == (void*)1);
	assert(list->back() == (void*)2);

	delete(list, list);
}

static void *dupdata(test_struct_t const *data)
{
	test_struct_t *ndata = malloc(sizeof(*ndata));

	ndata->i = data->i;
	ndata->ptr = malloc(100);
	return (ndata);
}

static void freedata(test_struct_t *data)
{
	free(data->ptr);
	free(data);
}

static void print(test_struct_t *data)
{
	printf("%d\n", data->i);
}

void test_assign()
{
	list_t *list = new(list, (dup_data_func_t)dupdata, (free_data_func_t)freedata);

	list->assign(10, &test_struct);
	delete(list, list);
}

void test_clear()
{
	list_t *list = new(list, (dup_data_func_t)dupdata, (free_data_func_t)freedata);

	list->assign(10, &test_struct);
	for (int i = 0; i < 5; ++i)
		list->push_front(&test_struct);
	list->clear();
	delete(list, list);
}

void test_at()
{
	const test_struct_t final[] = {{42, 0}, {42, 0}, {0, 0}, {2, 0}, {4, 0},
					{1, 0}, {3, 0}, {5, 0},	{6, 0}, {7, 0}};
	list_t *list = new(list, (dup_data_func_t)dupdata, (free_data_func_t)freedata);
	test_struct_t st = {0, NULL};

	for (int i = 0; i < 10; ++i) {
		st.i = i;
		list->emplace_back(&st);
	}	
	for (int i = -5; i < 5; ++i) {
		st.i = i;
		list->emplace(i, &st);
	}
	st.i = 42;
	for (int i = -5; i < 5; ++i) {
		list->insert(i, &st);
	}
	for (int i = -10; i < 10; ++i) {
		list->remove(i);
	}
	int i = 0;
	while (list->empty() == false) {
		assert(((test_struct_t*)list->front())->i == final[i].i);
		list->pop_front();
		i++;
	}
	delete(list, list);
}

void test_push()
{
	list_t *list = new(list);


	delete(list, list);
}

void test_merge()
{
	list_t *list = new(list);


	delete(list, list);
}

void test_removeif()
{
	list_t *list = new(list);


	delete(list, list);
}

void test_unique()
{
	list_t *list = new(list);



	delete(list, list);
}

void test_sort()
{
	list_t *list = new(list);


	delete(list, list);
}

void test_foreach()
{
	list_t *list = new(list);


	delete(list, list);
}

void clean_list(list_t **list)
{
	printf("clean ! \n");
	delete(list, *list);
}

void test_cleanup()
{
	__CLEAN(list) list_t *list = new(list);

	list->push_front(NULL);
}

int main()
{
	test_get();
	test_assign();
	test_clear();
	test_at();
	test_merge();
	test_removeif();
	test_unique();
	test_sort();
	test_foreach();
	test_cleanup();
}
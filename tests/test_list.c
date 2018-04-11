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
#include "init.h"

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

static void *dupdata(void const *data)
{
	int *ndata = malloc(sizeof(int));

	*ndata = *(int*)data;
	return (ndata);
}

void test_assign()
{
	list_t *list = new(list);
	int a = 42;

	list->assign(10, &a, dupdata);
	delete(list, list);
}
void test_clear()
{
	list_t *list = new(list);


	delete(list, list);
}
void test_at()
{
	list_t *list = new(list);


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
}

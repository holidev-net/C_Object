/*
** EPITECH PROJECT, 2017
** main2.c for C_Object
** File description:
** description
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "str.h"
#include "stream.h"
#include "init.h"

void print(void *data)
{
	printf("%d ", *(int*)data);
}

void double_var(void *data)
{
	*(int*)data += *(int*)data;
}
void double_var_plus_one(void *data)
{
	*(int*)data += *(int*)data + 1;
}

bool sort(int a, int b)
{
	return a < b;
}

bool egal(int a, int b)
{
	return a == b;
}

void *alloc_int(void const *i)
{
	int *data = malloc(sizeof(int));

	*data = *(int*)i;
	return (data);
}

int main()
{
	list_t *list = new(list);
	list_t *list2 = new(list);
	int *a = malloc(sizeof(int));

	*a = 2;

	for (int i = 0; i < 10; ++i) {
		list->push_back(a);
		list2->emplace_back(&i, alloc_int);
	}
	list->foreach(double_var);
	list2->foreach(double_var);

	puts("\nlist1 :");
	list->foreach(print);
	puts("\nlist2 :");
	list2->foreach(print);
	puts("");
	delete(list, list);
	delete(list, list2);
}

/*
** EPITECH PROJECT, 2017
** main2.c for C_Object
** File description:
** description
*/

#define PRIVATE_LIST
#include <stdio.h>
#include "list.h"
#include "str.h"
#include "stream.h"
#include "init.h"

void print(int *data)
{
	printf("%d ", *data);
}

int main()
{
	list_t *list = new(list, sizeof(int));

	for (int i = 0; i < 10; ++i)
		list->push_front(i);
	list->foreach(print);
	list->reverse();
	puts("");
	*list->front() = 42;
	list->foreach(print);
	puts("");
	delete(list, list);
}

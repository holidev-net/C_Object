/*
** EPITECH PROJECT, 2017
** test.c for C_Object
** File description:
** description
*/

#define PRIVATE_TEST

#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include "test.h"
#include "init.h"

void print(struct testObj *obj)
{
	printf("%d\n", obj->a);
}

void setA(int a, struct testObj *obj)
{
	obj->a = a;
}

struct testObj	*init_test_obj()
{
	struct testObj *b = malloc(sizeof(struct testObj));

	b->print = init_member(b, &print, 0);
	b->setA = init_member(b, &setA, 1);
	return b;
}

void delete_test_obj(struct testObj *obj)
{
	delete_member(obj->print);
	delete_member(obj->setA);
	free(obj);
}

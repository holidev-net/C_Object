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

void print(struct testObj *this)
{
	printf("%d\n", this->a);
}

void setA(int a, struct testObj *this)
{
	this->a = a;
}

int getA(struct testObj *this)
{
	return (this->a);
}

struct testObj	*init_testObj()
{
	struct testObj *b = malloc(sizeof(struct testObj));

	b->print = init_member(b, &print, 0);
	b->setA = init_member(b, &setA, 1);
	b->getA = init_member(b, &getA, 0);
	return b;
}

void delete_testObj(struct testObj *obj)
{
	delete_member(obj->print);
	delete_member(obj->setA);
	delete_member(obj->getA);
	free(obj);
}

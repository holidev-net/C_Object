/*
** EPITECH PROJECT, 2017
** test.h for C_Object
** File description:
** description
*/

#pragma once

struct testObj {
	void (*print)(void);
	void (*setA)(int);
	int (*getA)();

	#ifdef PRIVATE_TEST
	int a;
	#endif
};

struct testObj	*init_testObj();
void		delete_testObj(struct testObj *);

#ifdef PRIVATE_TEST
void print(struct testObj *);
void setA(int, struct testObj *);
int getA(struct testObj *);
#endif

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

	#ifdef PRIVATE_TEST
	int memberSize;
	int a;
	#endif
};

struct testObj	*init_test_obj();
void		delete_test_obj(struct testObj *);

#ifdef PRIVATE_TEST
void print(struct testObj *);
void setA(int, struct testObj *);
#endif

/*
** EPITECH PROJECT, 2017
** main2.c for C_Object
** File description:
** description
*/

// #define PRIVATE_TEST

#include "class/test.h"

int main()
{
	struct testObj *o = init_test_obj();

	// o->a = 23;
	o->setA(23);
	o->print();
	// print(o);

	delete_test_obj(o);
}

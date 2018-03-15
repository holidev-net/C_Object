/*
** EPITECH PROJECT, 2017
** main2.c for C_Object
** File description:
** description
*/

// #define PRIVATE_TEST
// #define PRIVATE_STRING

#include <stdio.h>
#include "class/test.h"
#include "class/string.h"
#include "class/init.h"

int main()
{
	string_t *str = new(string);
	struct testObj *obj = new(testObj);

	str->assign("bonjour");
	printf("%ld: [%s]\n", str->length(), str->front());
	*str->at(3) = 'O';
	*str->back() = 'Z';
	printf("[%s]\n", str->front());

	obj->setA(42);
	printf("%d: %s\n", obj->getA(), str->front());

	delete(string, str);
	delete(testObj, obj);
}

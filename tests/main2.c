/*
** EPITECH PROJECT, 2017
** main2.c for C_Object
** File description:
** description
*/

#include <stdio.h>
#include "class/test.h"
#include <stdio.h>
#include "class/mystring.h"
#include "class/stream.h"
#include "init.h"

int main()
{
	string_t *str = new(string);
	struct testObj *obj = new(testObj);
	stream_t *stream = new(stream);

	str->assign("bonjour");
	printf("%ld: [%s]\n", str->length(), str->front());
	*str->at(3) = 'O';
	*str->back() = 'Z';
	printf("[%s]\n", str->front());

	obj->setA(42);
	printf("%d: %s\n", obj->getA(), str->front());

	stream->str("bonjour: ")->i(42)->str(" char")->endl();

	delete(string, str);
	delete(testObj, obj);
}

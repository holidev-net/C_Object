/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** event_manager.c
*/

#include <stdio.h>
#include <stdarg.h>
#include "event_manager.h"

void fire(void (*func)(), ...)
{
	va_list ap;
	void *tmp[4];

	va_start(ap, func);
	for (int i = 0; i < 4; ++i)
		tmp[i] = va_arg(ap, void *);
	va_end(ap);
	func(tmp[0], tmp[1], tmp[2], tmp[3]);
}

void test(int a, int b)
{
	printf("%d %d\n", a, b);
}

int main()
{
	void (*func)() = test;

	func(10, 42);
	fire(func, 10, 42);
}

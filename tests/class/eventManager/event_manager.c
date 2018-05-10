/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** event_manager.c
*/

#include <stdio.h>
#include <stdarg.h>
#include "event_manager.h"

void (*func)() = NULL;

void fire2(int n, ...)
{
	if (func == NULL)
		return;
	va_list ap;
	void *tmp[4];

	va_start(ap, n);
	for (int i = 0; i < 4; ++i)
		tmp[i] = va_arg(ap, void *);
	va_end(ap);
	// printf("%lx %lx %lx\n", tmp[0], tmp[1], tmp[2]);
	func(tmp[0], tmp[1], tmp[2], tmp[3]);
}

// void fire(void (*func)(), ...)
// {
// 	va_list ap;
// 	void *tmp[4];

// 	va_start(ap, func);
// 	for (int i = 0; i < 4; ++i)
// 		tmp[i] = va_arg(ap, void *);
// 	va_end(ap);
// 	func(tmp[0], tmp[1], tmp[2], tmp[3]);
// }

// #define fire(args...) fire2(4, args)

void test(int a, int b)
{
	printf("%d %d\n", a, b);
}

void test2(int *p)
{
	printf("int ptr : %d\n", *p);
}

void test3(double f, double g, double h)
{
	printf("float : %f %f %f\n", f, g, h);
}

int main()
{
	// void (*func)() = test;

	// func(10, 42);
	// fire(test, 10, 42);

	// int a = 12;
	// fire((f_t)test2, &a);
	// fire((f_t)test3, 42.42, 43.43, 44.44);

	// float f = 10.10;
	// printf("%ld %f\n", (long)(void*)f);
	// func = (f_t)test2;
	// fire(&a);
	func = (f_t)test3;
	// fire(42.42, 43.43, 44.44);

	struct a aa = {._fire = fire2};
	aa.fire(1.1, 2.2, 3.3);
}

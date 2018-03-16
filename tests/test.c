/*
** EPITECH PROJECT, 2017
** test.c for C_Object
** File description:
** description
*/

#include <stdio.h>

void initA();

#define F0() printf("hello world\n")
#define F1(x) printf("%d\n", x)
#define F2(x, y) printf("%d %d\n", x, y)
#define F3(x, y, z) printf("%d %d %d\n", x, y, z)
#define F4(x, y, z, i) printf("%d %d %d %d\n", x, y, z, i)

#define GET_MACRO(_0, _1, _2, _3, _4, NAME, ...) NAME
#define FOO(...) GET_MACRO(_0, ##__VA_ARGS__, F4, F3, F2, F1, F0)(__VA_ARGS__)

#define GET_NARG(_0, _1, _2, _3, _4, NB, ...) NB
#define BAR(...) GET_NARG(_0, ##__VA_ARGS__, 4, 3, 2, 1, 0)

#define init(type, a...)init##type(BAR(a), ##a)

int main()
{
	init(A, 3, 4);
	init(A, 3);
	init(A);
	FOO(2, 3, 4, 5);
	FOO(2, 3, 4);
	FOO(2, 3);
	FOO(2);
	FOO();
	printf("%d\n", BAR());
	printf("%d\n", BAR(1));
	printf("%d\n", BAR(2, 3));
	printf("%d\n", BAR(3, 34, 1));
}

void initA(int nb_arg, int a, int b)
{
	printf("initA: %d\n", nb_arg);
	if (nb_arg > 0) {
		printf("arg1: %d\n", a);
	}
	if (nb_arg > 1) {
		printf("arg2: %d\n", b);
	}
	putchar('\n');
}

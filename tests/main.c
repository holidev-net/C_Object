/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>

void _test(char *s1, char *s2, char *s3, ...)
{
	printf("s1 : %s\n", (s1 ? s1 : "null"));
	printf("s2 : %s\n", (s2 ? s2 : "null"));
	printf("s3 : %s\n", (s3 ? s3 : "null"));
}

#define __NONULL(x) (x + 0)
#define __DEF_ARG4 NULL
#define __DEF_ARG3 "this arg is null"
#define __DEF_ARG2 NULL
#define __DEF_ARG1 NULL
#define __GET_DEF_ARG4(x) (__NONULL(x) ? x : __DEF_ARG4)
#define __GET_DEF_ARG3(x) (__NONULL(x) ? x : __DEF_ARG3)
#define __GET_DEF_ARG2(x) (__NONULL(x) ? x : __DEF_ARG2)
#define __GET_DEF_ARG1(x) (__NONULL(x) ? x : __DEF_ARG1)
#define ARG4(x, unused...)	__GET_DEF_ARG4(x)
#define ARG3(x, args...) 	__GET_DEF_ARG3(x), ARG4(args)
#define ARG2(x, args...) 	__GET_DEF_ARG2(x), ARG3(args)
#define ARG1(x, args...) 	__GET_DEF_ARG1(x), ARG2(args)
#define test(x, args...) 	_test(ARG1(x, args))

int main()
{
	printf("%d\n", b);
}
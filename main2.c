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
#include <stdio.h>
#include "class/string.h"

int main()
{
	string_t *str = init_string();

        printf("");
	str->assign("bonjour");
	printf("%ld: [%s]\n", str->length(), str->front());
	*str->at(3) = 'O';
	*str->back() = 'Z';
	printf("[%s]\n", str->front());

	delete_string(str);
}

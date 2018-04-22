/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** list_errors.c
*/

#include <stdio.h>
#include <stdlib.h>

static const char *class_type = "list";

void throw_list(char const *msg)
{
	fprintf(stderr, "%s : %s\n", class_type, msg);
	abort();
}

void throw_list_elem(int n)
{
	fprintf(stderr, "%s : access elem %d impossible\n", class_type, n);
	abort();
}
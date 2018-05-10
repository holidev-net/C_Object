/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** event_error.c
*/

#include <stdio.h>
#include <stdlib.h>

static const char *class_type = "event";

void throw_event(char const *msg)
{
	fprintf(stderr, "%s : %s\n", class_type, msg);
	abort();
}

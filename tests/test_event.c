/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** test_event.c
*/

#include "event.h"

void test1(int i)
{
	printf("test1: %d\n", i);
}

int main()
{
	event_t *evt = new(event, "test");

	evt->add_event(test1);
	evt->add_event(test1);
	evt->fire(evt, 10);
}
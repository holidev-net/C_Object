/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** test_event.c
*/

#include <stdio.h>

#include "event.h"
#include "init.h"

void test1(int i, char *str)
{
	printf("test1: %d [%s]\n", i, str);
}

void test2(const char *str, double f)
{
	printf("%s: this is the test2: %f\n", str, f);
}

void test21(const char *str, double f)
{
	printf("%s: %f\n", str, f);
}

void test3(double str, double f, double g)
{
	printf("%f %f %f\n", str, f, g);
}

int main()
{
	__CLEAN(event) event_t *evt = new(event, "test");
	__CLEAN(event) event_t *evt2 = new(event, "test2");
	__CLEAN(event) event_t *evt3 = new(event, "test3");

	evt->add_event(test1);
	evt->add_event(test1);
	evt->fire(evt, 10, "bonjour");
	evt2->add_event((event_type_t)test2);
	evt2->add_event((event_type_t)test21);
	evt2->fire(evt2, "test", 42.24);
	evt2->fire(evt2, "test2", -23456.);
	evt3->add_event(test3);
	evt3->add_event(test3);
	evt3->fire(evt3, 1.1, 2.2, 3.3);
}
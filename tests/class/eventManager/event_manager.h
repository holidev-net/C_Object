/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** event_manager.h
*/

#pragma once

typedef void (*f_t)();

// #include "vector.h"

// typedef struct {
// 	void (*add_event)(void(*)());
// 	void (*fire)(const char *key, ...);
// 	vector_t vec;
// }	event_manager_t;

struct a {
	int b;
	void (*_fire)(int, ...);
};
#define fire(args...) _fire(4, args)
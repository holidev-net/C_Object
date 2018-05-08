/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** event_manager.h
*/

#pragma once

#include "vector.h"

typedef struct {
	void (*add_event)(void(*)());
	void (*fire)(const char *key, ...);
	vector_t vec;
}	event_manager_t;
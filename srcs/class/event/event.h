/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** event.h
*/

#pragma once

#include <stdarg.h>

#include "init.h"
#include "list.h"

typedef void (*event_type_t)();

CLASS event {
	const char *(*get_name)(void);
	void (*add_event)(event_type_t);
	void (*fire)(struct event *, ...);
#ifdef __PRIVATE_EVENT__
	char *_name;
	list_t *_events;
#endif
}	event_t;

// #define fire(args...) _fire(4, args)

event_t	*init_event(const char *name);
void	delete_event(event_t **);

#ifdef __PRIVATE_EVENT__
void throw_event(const char *);

const char	*event_get_name(event_t *);
void		event_add_event(event_type_t, event_t *);
void		event_fire(event_t *, ...);
#endif
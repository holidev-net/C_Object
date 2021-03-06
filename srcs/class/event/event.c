/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** event.c
*/

#include <string.h>

#include "private_event.h"
#include "event.h"

static const member_wrap_t	members_tab[] = {
	MEMBER_WRAP(event_t, get_name, &event_get_name, 0),
	MEMBER_WRAP(event_t, add_event, &event_add_event, 1)
};

const char	*event_get_name(event_t *this)
{
	return (this->_name);
}

void	event_add_event(event_type_t func, event_t *this)
{
	this->_events->push_back(func);
}

void	event_fire(event_t *this, ...)
{
	va_list ap;
	void *tmp[4];

	va_start(ap, this);
	for (int i = 0; i < 4; ++i)
		tmp[i] = va_arg(ap, void *);
	for (ITER(it, list_it, this->_events)) {
		((event_type_t)it->get())(tmp[0], tmp[1], tmp[2], tmp[3]);
	}
	va_end(ap);
}

event_t	*init_event(const char *name)
{
	event_t *obj = malloc(sizeof(*obj));

	if (obj == NULL)
		throw_event("error malloc");
	obj->_name = strdup(name);
	if (obj->_name == NULL)
		throw_event("error malloc");
	obj->_events = new(list);
	init_members(obj, PASS_MEMBERS_WRAP(members_tab));
	obj->fire = event_fire;
	return (obj);
}

void	delete_event(event_t **obj)
{
	if (*obj == NULL)
		return;
	free_members(*obj, PASS_MEMBERS_WRAP(members_tab));
	delete(list, (*obj)->_events);
	free((*obj)->_name);
	free((*obj));
}

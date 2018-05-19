/*
** EPITECH PROJECT, 2017
** init_member.c for C_Object
** File description:
** description
*/

#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "cobject.h"

static inline int init_member_write_member_callers(
	void *obj, va_list vl, int nb_functs)
{
	init_wrap_t     cur_wrapper;

	while (nb_functs--) {
		cur_wrapper = va_arg(vl, init_wrap_t);
		*(cur_wrapper.funct) = create_caller(
			obj, cur_wrapper.target, cur_wrapper.nb_args);
		if (*(cur_wrapper.funct) == NULL) {
			return (-1);
		}
	}
	va_end(vl);
	return (0);
}

int init_members(void *obj, int nb_functs, ...)
{
	va_list	vl;

	va_start(vl, nb_functs);
	return (init_member_write_member_callers(
		obj, vl, nb_functs));
}
/*
** EPITECH PROJECT, 2017
** init.h for C_Object
** File description:
** description
*/

#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#define __APPROVED_BY(name...)

#define COBJECT_DEPRECATED(func) func __attribute__ ((deprecated))

#define ALIGN   16

#ifndef OFFSETOF
#define OFFSETOF(type, member) ((type *(0))->member)
#endif

#define CLASS		typedef struct

#define CREATE_WRAP(o, s, t, n)	((init_wrap_t){(void *) &((o)->s), t, n})

/**
 * t = type
 * m = member name
 * f = target function
 * s = args number
 **/
#define MEMBER_WRAP(t,m,f,s) ((member_wrap_t){((uintptr_t)&(((t*)0)->m)),f,s})

#define PASS_MEMBERS_WRAP(mems) mems, (sizeof(mems) / sizeof(*mems))

#define HERIT(o, mem, sub_mem)	o->mem = o->sub_mem

#define __CLEAN(obj)	__attribute__((__cleanup__(delete_##obj)))

#define __NONULL(x)	(x + 0)

typedef struct {
	void	**funct;
	void	*target;
	int	nb_args;
}	init_wrap_t;


typedef struct {
	uint32_t	funct_off;
	void		*target;
	int		nb_args;
}	member_wrap_t;

int	init_members(void *obj, member_wrap_t const *tab, size_t len);
void	free_members(void *obj, member_wrap_t const *tab, size_t len);

void	*create_capture(void *data_ptr, void *funcion_ptr, int arg_nbr);
void	*get_capture_data(void *caller);
void	free_capture(void *caller);

#define delete(type, obj)	delete_##type(&obj)
#define new(type, ...)		init_##type(__VA_ARGS__)
#define cast(obj, obj2)		obj##_to_##obj2
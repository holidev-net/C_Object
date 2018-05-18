/*
** EPITECH PROJECT, 2017
** init.h for C_Object
** File description:
** description
*/

#pragma once

#include <stdlib.h>
#include <unistd.h>

#define __APPROVED_BY(name)

#define CLASS		typedef struct

#define CREATE_WRAP(o, s, t, n)	((init_wrap_t){(void *) &((o)->s), t, n})

#define HERIT(o, mem, sub_mem)	o->mem = o->sub_mem

#define __CLEAN(obj)	__attribute__((__cleanup__(delete_##obj)))

#define __NONULL(x)	(x + 0)

typedef struct {
	void	**funct;
	void	*target;
	int	nb_args;
}	init_wrap_t;

int	init_members(void *obj, int nb_funct, ...);
void	*create_caller(void *data_ptr, void *funcion_ptr, int arg_nbr);
void	*get_capture(void *caller);
void	free_caller(void *caller);

#define delete(type, obj)	delete_##type(&obj);
#define new(type, ...)		init_##type(__VA_ARGS__);
#define cast(obj, obj2)		obj##_to_##obj2
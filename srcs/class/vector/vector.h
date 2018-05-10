/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** vector.h
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

#include "init.h"
#include "vector_it.h"

#ifndef DUP_DATA_FUNC
#define DUP_DATA_FUNC
typedef void *(*dup_data_func_t)(void const *);
#endif

#ifndef FREE_DATA_FUNC
#define FREE_DATA_FUNC
typedef void (*free_data_func_t)(void *);
#endif

CLASS vector {
	size_t	(*size)(void);
	void	(*resize)(size_t, void *);
	size_t	(*capacity)(void);
	bool	(*empty)(void);
	void	(*reserve)(size_t);
	void	(*shrink_to_fit)(void);
	void	*(*at)(long);
	void	*(*front)(void);
	void	*(*back)(void);
	void	(*assign)(size_t, void *);
	void	(*push_back)(void *);
	void	(*pop_back)(void);
	void	(*insert)(long, void *);
	void	(*erase)(long);
	void	(*swap)(long, long);
	void	(*clear)(void);
	#ifdef PRIVATE_VECTOR
	dup_data_func_t		_dup_data;
	free_data_func_t 	_free_data;
	void			**_datas;
	size_t			_size;
	size_t			_capacity;
	#endif
}	vector_t;

#define __VEC_DEF_ARG2 NULL
#define __VEC_DEF_ARG1 NULL

#define __VEC_GET_DEF_ARG2(x)	(__NONULL(x) ? x : __VEC_DEF_ARG2)
#define __VEC_GET_DEF_ARG1(x)	(__NONULL(x) ? x : __VEC_DEF_ARG1)
#define VEC_ARG2(x, unused...)	__VEC_GET_DEF_ARG2(x)
#define VEC_ARG1(x, args...)	__VEC_GET_DEF_ARG1(x), VEC_ARG2(args)
#define init_vector(x, args...)	__init_vector(VEC_ARG1(x, args))

vector_t	*__init_vector(dup_data_func_t, free_data_func_t);
void		delete_vector(vector_t **);

#ifdef PRIVATE_VECTOR
void	throw_vector(char const *msg)__attribute__((nonnull));
void	throw_vector_elem(int n)__attribute__((nonnull));

void insert_elem(size_t i, void *data, vector_t *);
void remove_elem(size_t i, vector_t *);

size_t	vector_size(vector_t *);
void	vector_resize(size_t n, void *data, vector_t *);
size_t	vector_capacity(vector_t *);
bool	vector_empty(vector_t *);
void	vector_reserve(size_t n, vector_t *);
void	vector_shrink_to_fit(vector_t *);
void	*vector_at(long at, vector_t *);
void	*vector_front(vector_t *);
void	*vector_back(vector_t *);
void	vector_assign(size_t n, void *data, vector_t *);
void	vector_push_back(void *data, vector_t *);
void	vector_pop_back(vector_t *);
void	vector_insert(long at, void *data, vector_t *);
void	vector_erase(long at, vector_t *);
void	vector_swap(long it1, long it2, vector_t *);
void	vector_clear(vector_t *);
#endif
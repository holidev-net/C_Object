/*
** EPITECH PROJECT, 2017
** string.h for C_Object
** File description:
** description
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef struct string {
	void	(*assign)(const char *);
	size_t	(*length)();
	void	(*clear)();
	bool	(*empty)();
	char	*(*at)(long);
	char	*(*front)();
	char	*(*back)();

	#ifdef __PRIVATE_STRING__
	size_t	_size;
	char	*_str;
	#endif
} string_t;

string_t	*init_string();
void		delete_string(string_t **);

#ifdef __PRIVATE_STRING__
void	assign(const char *str, string_t *);
size_t	length(string_t *);
void	clear(string_t *);
bool	empty(string_t *);
char	*at(long, string_t *);
char	*front(string_t *);
char	*back(string_t *);
#endif

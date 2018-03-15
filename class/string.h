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
	char	*(*at)(size_t);
	char	*(*front)();
	char	*(*back)();
	#ifdef PRIVATE_STRING
	int	memberSize;
	size_t	_size;
	char	*_str;
	#endif
} string_t;

string_t	*init_string();
void		delete_string(string_t *);

#ifdef PRIVATE_STRING
void	assign(const char *str, string_t *);
size_t	length(string_t *);
void	clear(string_t *);
bool	empty(string_t *);
char	*at(size_t, string_t *);
char	*front(string_t *);
char	*back(string_t *);
#endif

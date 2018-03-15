/*
** EPITECH PROJECT, 2017
** string.h for C_Object
** File description:
** description
*/

#pragma once

typedef struct string {
	void (*assign)(const char *);
	#ifdef PRIVATE_STRING
	int	memberSize;
	int	_size;
	char	*_str;
	#endif
} string_t;

string_t	*init_string();
void		delete_string(string_t *);

#ifdef PRIVATE_STRING
void assign(const char *str, string_t *);
void setA(int, string_t *);
#endif

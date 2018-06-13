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

int	init_members(void *obj, member_wrap_t const *tab, size_t len)
{
	void	*ptr; 

	for (size_t i = 0; i < len; i++) {
		ptr = create_capture(obj, tab[i].target, tab[i].nb_args);
		if (ptr == NULL)
			return (-1);
		*((void**) (obj + tab[i].funct_off)) = ptr;
	}
	return (0);
}

void	free_members(void *obj, member_wrap_t const *tab, size_t len)
{
	if (!obj || !tab)
		return;
	for (size_t i = 0; i < len; i++) {
		free_capture(*((void**) (obj + tab[i].funct_off)));
	}
}

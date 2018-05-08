/*
** EPITECH PROJECT, 2017
** stream.c for C_Object
** File description:
** description
*/

#include <stdio.h>
#include <stdlib.h>

#include "init.h"
#include "private_stream.h"
#include "stream.h"

void stream_ctor(stream_t *obj)
{
	obj->stream = stdout;
	init_members(obj, 7,
		CREATE_WRAP(obj, str, &write_str, 1),
		CREATE_WRAP(obj, c, &write_c, 1),
		CREATE_WRAP(obj, i, &write_i, 1),
		CREATE_WRAP(obj, ld, &write_ld, 1),
		CREATE_WRAP(obj, endl, &write_endl, 0),
		CREATE_WRAP(obj, flush, &flush, 0),
		CREATE_WRAP(obj, src, &write_src, 1)
		);
}

stream_t	*init_stream0(void)
{
	stream_t *obj = malloc(sizeof(stream_t));

	if (obj == NULL) {
		return (NULL);
	}
	stream_ctor(obj);
	return (obj);
}

stream_t	*init_stream1(FILE *file)
{
	stream_t *obj = malloc(sizeof(stream_t));

	if (obj == NULL) {
		return (NULL);
	}
	stream_ctor(obj);
	obj->stream = file;
	return (obj);
}

void		delete_stream(stream_t **obj)
{
	delete_members((*obj)->str);
	free(*obj);
}

void flush(stream_t *this)
{
	fflush(this->stream);
}
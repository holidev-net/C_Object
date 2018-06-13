/*
** EPITECH PROJECT, 2017
** stream.c for C_Object
** File description:
** description
*/

#include <stdio.h>
#include <stdlib.h>

#include "cobject.h"
#include "private_stream.h"
#include "stream.h"

static const member_wrap_t	members_tab[] = {
	MEMBER_WRAP(stream_t, str, &write_str, 1),
	MEMBER_WRAP(stream_t, c, &write_c, 1),
	MEMBER_WRAP(stream_t, i, &write_i, 1),
	MEMBER_WRAP(stream_t, ld, &write_ld, 1),
	MEMBER_WRAP(stream_t, endl, &write_endl, 0),
	MEMBER_WRAP(stream_t, flush, &flush, 0),
	MEMBER_WRAP(stream_t, src, &write_src, 1)
};

void stream_ctor(stream_t *obj)
{
	obj->stream = stdout;
	init_members(obj, PASS_MEMBERS_WRAP(members_tab));
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
	if (*obj == NULL)
		return;
	free_members(*obj, PASS_MEMBERS_WRAP(members_tab));
	free(*obj);
}

void flush(stream_t *this)
{
	fflush(this->stream);
}
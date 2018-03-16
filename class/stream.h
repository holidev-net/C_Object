/*
** EPITECH PROJECT, 2017
** stream.h for C_Object
** File description:
** description
*/

#pragma once

#include <stdio.h>

typedef struct stream {
	struct stream *(*str)(struct a *, char *str);
	struct stream *(*c)(struct a *, char);
	struct stream *(*i)(struct a *, int);
	struct stream *(*ld)(struct a *, long);
	struct stream *(*endl)(struct a *);

	#ifdef PRIVATE_STREAM
	FILE *stream;
	#endif
}	stream_t;

stream_t	*init_stream();
void		delete_stream(stream_t *);

#ifdef PRIVATE_STREAM
stream_t *write_str(char *str, stream_t *);
stream_t *write_c(char c, stream_t *);
stream_t *write_i(int i, stream_t *);
stream_t *write_ld(long l, stream_t *);
stream_t *write_endl(stream_t *);
#endif
